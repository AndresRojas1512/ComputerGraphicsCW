#include "drawer.hpp"

void Drawer::borderPut(int x, int y, double z)
{
    if (x < 0 || x >= (int) depthBuffer.size() || y < 0 || y >= (int) depthBuffer.at(0).size())
        return;
    if (std::fabs(z - depthBuffer.at(x).at(y)) < 1 || z > depthBuffer.at(x).at(y))
        borderBuffer.at(x).at(y) = 3;
}

void Drawer::bordersForPolygon(int xStart, int yStart, double zStart, int xEnd, int yEnd, double zEnd)
{
    if (xStart == xEnd && yStart == yEnd)
    {
        borderPut(xStart, yStart, zStart);
        return;
    }

    double deltaX = xEnd - xStart;
    double deltaY = yEnd - yStart;
    double deltaZ = zEnd - zStart;

    int trX = abs(deltaX);
    int trY = abs(deltaY);

    int length;
    if (trX > trY)
        length = trX;
    else
        length = trY;

    deltaX /= length;
    deltaY /= length;
    deltaZ /= length;

    double curX = xStart;
    double curY = yStart;
    double curZ = zStart;

    for (int i = 0; i < length; i++)
    {
        borderPut(round(curX), round(curY), curZ);
        curX += deltaX;
        curY += deltaY;
        curZ += deltaZ;
    }
}

void Drawer::interRowIntoShadowMap(std::vector<std::vector<double>> *map, int xA, int xB, double zA, double zB, int curY)
{
    for (int curX = xA; curX <= xB; curX++)
    {
        double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);
        if (curX >= (int) map->size() || curX < 0 || curY >= (int) map->at(0).size() ||
            curY < 0)
            continue;

        if (curZ > map->at(curX).at(curY))
            map->at(curX).at(curY) = curZ;
    }
}

void Drawer::shadowMapForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                               Eigen::Matrix4f &transMat, Light *illum, size_t bufWidth, size_t bufHeight)
{
    std::array<Dot3D, 3> dotsArr;
    Eigen::Matrix4f toCenter;

    toCenter << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        -X_CENTER, -Y_CENTER, -BASE_Z - 5, 1;

    Eigen::Matrix4f backToStart;

    backToStart << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        X_CENTER, Y_CENTER, BASE_Z + 5, 1;

    std::vector<std::vector<double>> *shadowMap = &illum->getShadowMap();
    Eigen::Matrix4f illumMat = illum->getTransMat();

    Eigen::Matrix4f dotTransMat = toCenter * transMat * illumMat * backToStart;

    for (size_t curFaceNum = 0; curFaceNum < facets.size(); curFaceNum++)
    {
        Eigen::MatrixXf coordinatesVec(3, 4);

        std::vector<size_t> curDots = facets.at(curFaceNum).getVertices();
        dotsArr[0] = vertices.at(curDots.at(0)).getPosition();
        dotsArr[1] = vertices.at(curDots.at(1)).getPosition();
        dotsArr[2] = vertices.at(curDots.at(2)).getPosition();

        coordinatesVec <<
            dotsArr[0].getXCoordinate(), dotsArr[0].getYCoordinate(), dotsArr[0].getZCoordinate(), 1,
            dotsArr[1].getXCoordinate(), dotsArr[1].getYCoordinate(), dotsArr[1].getZCoordinate(), 1,
            dotsArr[2].getXCoordinate(), dotsArr[2].getYCoordinate(), dotsArr[2].getZCoordinate(), 1;

        coordinatesVec *= dotTransMat;
        dotsArr[0] =
            Dot3D(coordinatesVec(0, 0), coordinatesVec(0, 1), coordinatesVec(0, 2));
        dotsArr[1] =
            Dot3D(coordinatesVec(1, 0), coordinatesVec(1, 1), coordinatesVec(1, 2));
        dotsArr[2] =
            Dot3D(coordinatesVec(2, 0), coordinatesVec(2, 1), coordinatesVec(2, 2));

        if (dotsArr[0].getYCoordinate() > dotsArr[1].getYCoordinate())
            std::swap(dotsArr[0], dotsArr[1]);
        if (dotsArr[0].getYCoordinate() > dotsArr[2].getYCoordinate())
            std::swap(dotsArr[0], dotsArr[2]);
        if (dotsArr[1].getYCoordinate() > dotsArr[2].getYCoordinate())
            std::swap(dotsArr[1], dotsArr[2]);

        int x1 = round(dotsArr[0].getXCoordinate());
        int x2 = round(dotsArr[1].getXCoordinate());
        int x3 = round(dotsArr[2].getXCoordinate());

        double z1 = dotsArr[0].getZCoordinate();
        double z2 = dotsArr[1].getZCoordinate();
        double z3 = dotsArr[2].getZCoordinate();

        int y1 = round(dotsArr[0].getYCoordinate());
        int y2 = round(dotsArr[1].getYCoordinate());
        int y3 = round(dotsArr[2].getYCoordinate());

        //#pragma omp parallel for
        for (int curY = (y1 < 0) ? 0 : y1;
             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++)
        {
            double aInc = 0;
            if (y1 != y2)
                aInc = (double) (curY - y1) / (y2 - y1);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x1 + (x2 - x1) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z1 + (z2 - z1) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB)
            {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            interRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
        }

        //#pragma omp parallel for
        for (int curY = (y2 < 0) ? 0 : y2;
             curY <= ((y3 >= (int) bufHeight) ? (int) bufHeight - 1 : y3); curY++)
        {
            double aInc = 0;
            if (y2 != y3)
                aInc = (double) (curY - y2) / (y3 - y2);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x2 + (x3 - x2) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z2 + (z3 - z2) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB)
            {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            interRowIntoShadowMap(shadowMap, xA, xB, zA, zB, curY);
        }
    }
}

void Drawer::zBufForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                          Eigen::Matrix4f &transMat, size_t color, SceneInf *scene, size_t bufWidth,
                          size_t bufHeight)
{
    // std::cout << "Drawer::zBufForModel" << std::endl;
    // std::cout << "---> color: " << color << std::endl;

    std::array<Dot3D, 3> dotsArr;
    Eigen::Matrix4f toCenter;

    toCenter << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        -X_CENTER, -Y_CENTER, -BASE_Z - 5, 1;

    Eigen::Matrix4f backToStart;

    backToStart << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        X_CENTER, Y_CENTER, BASE_Z + 5, 1;

    Eigen::Matrix4f dotTransMat;
    dotTransMat = toCenter * transMat * backToStart;
    std::vector<Eigen::Matrix4f> illumDotMatrices;

    for (size_t i = 0; i < scene->getLightNum(); i++)
        illumDotMatrices.push_back(
            toCenter * scene->getLight(i).getTransMat() * backToStart);

    for (size_t curFaceNum = 0; curFaceNum < facets.size(); curFaceNum++)
    {
        Eigen::MatrixXf coordinatesVec(3, 4);

        std::vector<size_t> curDots = facets.at(curFaceNum).getVertices();
        dotsArr[0] = vertices.at(curDots.at(0)).getPosition();
        dotsArr[1] = vertices.at(curDots.at(1)).getPosition();
        dotsArr[2] = vertices.at(curDots.at(2)).getPosition();

        coordinatesVec <<
            dotsArr[0].getXCoordinate(), dotsArr[0].getYCoordinate(), dotsArr[0].getZCoordinate(), 1,
            dotsArr[1].getXCoordinate(), dotsArr[1].getYCoordinate(), dotsArr[1].getZCoordinate(), 1,
            dotsArr[2].getXCoordinate(), dotsArr[2].getYCoordinate(), dotsArr[2].getZCoordinate(), 1;

        coordinatesVec *= dotTransMat;

        dotsArr[0] =
            Dot3D(coordinatesVec(0, 0), coordinatesVec(0, 1), coordinatesVec(0, 2));
        dotsArr[1] =
            Dot3D(coordinatesVec(1, 0), coordinatesVec(1, 1), coordinatesVec(1, 2));
        dotsArr[2] =
            Dot3D(coordinatesVec(2, 0), coordinatesVec(2, 1), coordinatesVec(2, 2));

        if (dotsArr[0].getYCoordinate() > dotsArr[1].getYCoordinate())
            std::swap(dotsArr[0], dotsArr[1]);
        if (dotsArr[0].getYCoordinate() > dotsArr[2].getYCoordinate())
            std::swap(dotsArr[0], dotsArr[2]);
        if (dotsArr[1].getYCoordinate() > dotsArr[2].getYCoordinate())
            std::swap(dotsArr[1], dotsArr[2]);

        int x1 = round(dotsArr[0].getXCoordinate());
        int x2 = round(dotsArr[1].getXCoordinate());
        int x3 = round(dotsArr[2].getXCoordinate());

        double z1 = dotsArr[0].getZCoordinate();
        double z2 = dotsArr[1].getZCoordinate();
        double z3 = dotsArr[2].getZCoordinate();

        int y1 = round(dotsArr[0].getYCoordinate());
        int y2 = round(dotsArr[1].getYCoordinate());
        int y3 = round(dotsArr[2].getYCoordinate());

        for (int curY = (y1 < 0) ? 0 : y1;
             curY < ((y2 >= (int) bufHeight) ? (int) bufHeight - 1 : y2); curY++)
        {
            double aInc = 0;
            if (y1 != y2)
                aInc = (double) (curY - y1) / (y2 - y1);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x1 + (x2 - x1) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z1 + (z2 - z1) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB)
            {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            for (int curX = xA; curX <= xB; curX++)
            {
                double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);

                if (curZ >= depthBuffer.at(curX).at(curY))
                {
                    short visible = 0;
                    Eigen::MatrixXf newCoordinates(1, 4);

                    for (size_t i = 0; i < scene->getLightNum() && !visible; i++)
                    {
                        newCoordinates << curX, curY, curZ, 1;

                        newCoordinates *= illumDotMatrices.at(i);
                        std::vector<std::vector<double>> *shadowMap =
                            &scene->getLight(i).getShadowMap();

                        int x = round(newCoordinates(0, 0));
                        int y = round(newCoordinates(0, 1));

                        if (x < (int) shadowMap->size() && x >= 0 &&
                            y < (int) shadowMap->at(0).size() && y >= 0 &&
                            std::fabs(shadowMap->at(x).at(y) - newCoordinates(0, 2)) < 2)
                            visible = 1;
                    }
                    depthBuffer.at(curX).at(curY) = curZ;
                    if (scene->getLightNum())
                    {
                        borderBuffer.at(curX).at(curY) = color + visible;
                    }
                    else
                        borderBuffer.at(curX).at(curY) = color + 1;
                }
            }
        }
        for (int curY = (y2 < 0) ? 0 : y2;
             curY <= ((y3 >= (int) bufHeight) ? (int) bufHeight - 1 : y3); curY++)
        {
            double aInc = 0;
            if (y2 != y3)
                aInc = (double) (curY - y2) / (y3 - y2);

            double bInc = 0;
            if (y1 != y3)
                bInc = (double) (curY - y1) / (y3 - y1);

            int xA = round(x2 + (x3 - x2) * aInc);
            int xB = round(x1 + (x3 - x1) * bInc);
            double zA = z2 + (z3 - z2) * aInc;
            double zB = z1 + (z3 - z1) * bInc;

            if (xA > xB)
            {
                std::swap(xA, xB);
                std::swap(zA, zB);
            }

            if (xA < 0)
                xA = 0;
            if (xB >= (int) bufWidth)
                xB = (int) bufWidth - 1;

            for (int curX = xA; curX <= xB; curX++)
            {
                double curZ = zA + (zB - zA) * (curX - xA) / (xB - xA);

                if (curZ >= depthBuffer.at(curX).at(curY))
                {
                    short is_visible = 0;
                    Eigen::MatrixXf newCoordinates(1, 4);
                    for (size_t i = 0; i < scene->getLightNum() && !is_visible; i++)
                    {
                        newCoordinates << curX, curY, curZ, 1;

                        newCoordinates *= illumDotMatrices.at(i);
                        std::vector<std::vector<double>> *shadowMap =
                            &scene->getLight(i).getShadowMap();
                        int x = round(newCoordinates(0, 0));
                        int y = round(newCoordinates(0, 1));

                        if (x < (int) shadowMap->size() && x >= 0 &&
                            y < (int) shadowMap->at(0).size() && y >= 0 &&
                            std::fabs(shadowMap->at(x).at(y) - newCoordinates(0, 2)) < 2)
                            is_visible = 1;
                    }
                    depthBuffer.at(curX).at(curY) = curZ;
                    if (scene->getLightNum())
                    {
                        borderBuffer.at(curX).at(curY) = color + is_visible;
                    }
                    else
                        borderBuffer.at(curX).at(curY) = color + 1;
                }
            }
        }
        bordersForPolygon(x1, y1, z1, x2, y2, z2);
        bordersForPolygon(x1, y1, z1, x3, y3, z3);
        bordersForPolygon(x2, y2, z2, x3, y3, z3);

    }
}

void Drawer::zBufferAlg(SceneInf *scene, size_t bufHeight, size_t bufWidth)
{
    // std::cout << "Drawer::zBufferAlg" << std::endl;
    depthBuffer.erase(depthBuffer.begin(), depthBuffer.end());
    borderBuffer.erase(borderBuffer.begin(), borderBuffer.end());

    for (size_t i = 0; i < bufWidth; i++)
    {
        depthBuffer.push_back(std::vector<double>(bufHeight, 0));
        borderBuffer.push_back(std::vector<size_t>(bufHeight, 0));
    }

    PolygonModel model;
    std::vector<Facet> facets;
    std::vector<Vertex> vertices;
    PolygonModel::model_t typeModel;

    for (size_t i = 0; i < scene->getModelsNum(); i++)
    {
        model = scene->getModel(i);
        facets = model.getFacets();
        vertices = model.getVertices();
        for (size_t j = 0; j < scene->getLightNum(); j++)
            shadowMapForModel(facets, vertices, scene->getTransMatrix(),
                              &scene->getLight(j), bufWidth, bufHeight);
    }

    model = scene->getBaseModel();
    facets = model.getFacets();
    vertices = model.getVertices();
    for (size_t j = 0; j < scene->getLightNum(); j++)
        shadowMapForModel(facets, vertices, scene->getTransMatrix(),
                          &scene->getLight(j), bufWidth, bufHeight);

    // std::cout << "zBufferAlg loop:" << std::endl;
    for (size_t i = 0; i < scene->getModelsNum(); i++)
    {
        // std::cout << "---> iteration: " << i << std::endl;
        model = scene->getModel(i);
        // std::cout << model;
        facets = model.getFacets();
        vertices = model.getVertices();
        typeModel = model.getModelType();
        zBufForModel(facets, vertices, scene->getTransMatrix(), 4 + typeModel * 2, scene, bufWidth, bufHeight);
    }
    model = scene->getBaseModel();
    facets = model.getFacets();
    vertices = model.getVertices();
    zBufForModel(facets, vertices, scene->getTransMatrix(), 1, scene, bufWidth, bufHeight);

    for (size_t i = 0; i < scene->getLightNum(); i++)
        scene->getLight(i).clearShadowMap();
}

QGraphicsScene *Drawer::drawScene(SceneInf *scene, QRectF rect)
{
    std::cout << "Drawer::drawScene" << std::endl;
    std::cout << "Drawer::drawScene -> rect: " << rect.height() << ", " << rect.width() << std::endl;
    size_t width = scene->getWidth() * SIZE_SC;
    size_t height = scene->getHeight() * SIZE_SC;

    scene->buildBaseModel(Dot3D(BASE_START), Dot3D(width, height, BASE_Z));
    std::cout << "---> modelsNum: " << scene->getModelsNum() << std::endl;

    using namespace std::chrono;
    nanoseconds start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    zBufferAlg(scene, rect.size().height(), rect.size().width());
    nanoseconds end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    qDebug() << "Время выполнения алгоритма" << size_t((end - start).count() / 1000000);

    QGraphicsScene *outScene = new QGraphicsScene;
    outScene->setSceneRect(rect);

    QImage *image =
        new QImage(rect.size().width(), rect.size().height(), QImage::Format_RGB32);
    image->fill(Qt::white);

    uint baseColor              = qRgb(ATX_MOTHERBOARD_COLOR);
    uint baseColorShadow        = qRgb(ATX_MOTHERBOARD_COLOR_SHADOW);

    uint borderColor            = qRgb(BLACK_COLOR);

    uint brickColor             = qRgb(BRICK_COLOR);
    uint brickColorShadow       = qRgb(BRICK_COLOR_SHADOW);

    uint plateColor             = qRgb(PLATE_COLOR);
    uint plateColorShadow       = qRgb(PLATE_COLOR_SHADOW);

    uint tileColor              = qRgb(TILE_COLOR);
    uint tileColorShadow        = qRgb(TILE_COLOR_SHADOW);

    uint arcColor               = qRgb(ARC_COLOR);
    uint arcColorShadow         = qRgb(ARC_COLOR_SHADOW);

    uint cylinderColor          = qRgb(CYLINDER_COLOR);
    uint cylinderColorShadow    = qRgb(CYLINDER_COLOR_SHADOW);

    // ATX_HDMI_DP
    uint atx_HDMI_DP_Color = qRgb(ATX_HDMI_DP_COLOR);
    uint atx_HDMI_DP_ColorShadow = qRgb(ATX_HDMI_DP_COLOR_SHADOW);
    // ATX_BIOS_FLBK
    uint atx_BIOS_FLBK_Color = qRgb(ATX_BIOS_FLBK_COLOR);
    uint atx_BIOS_FLBK_ColorShadow = qRgb(ATX_BIOS_FLBK_COLOR_SHADOW);
    // ATX_U32G2_1_4
    uint atx_U32G2_1_4_Color = qRgb(ATX_U32G2_1_4_COLOR);
    uint atx_U32G2_1_4_ColorShadow = qRgb(ATX_U32G2_1_4_COLOR_SHADOW);
    // ATX_LAN2_U32G2_56
    uint atx_LAN2_U32G2_56_Color = qRgb(ATX_LAN2_U32G2_56_COLOR);
    uint atx_LAN2_U32G2_56_ColorShadow = qRgb(ATX_LAN2_U32G2_56_COLOR_SHADOW);
    // ATX_U3252_C8_LAN1_U32G2_7
    uint atx_U3252_C8_LAN1_U32G2_7_Color = qRgb(ATX_U3252_C8_LAN1_U32G2_7_COLOR);
    uint atx_U3252_C8_LAN1_U32G2_7_ColorShadow = qRgb(ATX_U3252_C8_LAN1_U32G2_7_COLOR_SHADOW);
    // ATX_M2_WIFI
    uint atx_M2_WIFI_Color = qRgb(ATX_M2_WIFI_COLOR);
    uint atx_M2_WIFI_ColorShadow = qRgb(ATX_M2_WIFI_COLOR_SHADOW);
    // ATX_AUDIO
    uint atx_AUDIO_Color = qRgb(ATX_AUDIO_COLOR);
    uint atx_AUDIO_ColorShadow = qRgb(ATX_AUDIO_COLOR_SHADOW);
    // ATX_socketM4
    uint atx_socketM4_Color = qRgb(ATX_SOCKET_M4_COLOR);
    uint atx_socketM4_ColorShadow = qRgb(ATX_SOCKET_M4_COLOR_SHADOW);
    // ATX_DDR4_DIMM_B1
    uint atx_DDR4_DIMM_B1_Color = qRgb(ATX_DDR4_DIMM_B1_COLOR);
    uint atx_DDR4_DIMM_B1_ColorShadow = qRgb(ATX_DDR4_DIMM_B1_COLOR_SHADOW);
    // ATX_DDR4_DIMM_B2
    uint atx_DDR4_DIMM_B2_Color = qRgb(ATX_DDR4_DIMM_B2_COLOR);
    uint atx_DDR4_DIMM_B2_ColorShadow = qRgb(ATX_DDR4_DIMM_B2_COLOR_SHADOW);
    // ATX_DDR4_DIMM_A1
    uint atx_DDR4_DIMM_A1_Color = qRgb(ATX_DDR4_DIMM_A1_COLOR);
    uint atx_DDR4_DIMM_A1_ColorShadow = qRgb(ATX_DDR4_DIMM_A1_COLOR_SHADOW);
    // ATX_DDR4_DIMM_A2
    uint atx_DDR4_DIMM_A2_Color = qRgb(ATX_DDR4_DIMM_A2_COLOR);
    uint atx_DDR4_DIMM_A2_ColorShadow = qRgb(ATX_DDR4_DIMM_A2_COLOR_SHADOW);
    // ATX_PCIEX16_1
    uint atx_PCIEX16_1_Color = qRgb(ATX_PCIEX16_1_COLOR);
    uint atx_PCIEX16_1_ColorShadow = qRgb(ATX_PCIEX16_1_COLOR_SHADOW);
    // ATX_PCIEX16_2
    uint atx_PCIEX16_2_Color = qRgb(ATX_PCIEX16_2_COLOR);
    uint atx_PCIEX16_2_ColorShadow = qRgb(ATX_PCIEX16_2_COLOR_SHADOW);
    // ATX_PCIEX16_3
    uint atx_PCIEX16_3_Color = qRgb(ATX_PCIEX16_3_COLOR);
    uint atx_PCIEX16_3_ColorShadow = qRgb(ATX_PCIEX16_3_COLOR_SHADOW);

    // MICROATX_HDMI1_DP
    uint microAtx_HDMI1_DP_Color = qRgb(MICROATX_HDMI1_DP_COLOR);
    uint microAtx_HDMI1_DP_ColorShadow = qRgb(MICROATX_HDMI1_DP_COLOR_SHADOW);
    // MICROATX_HDMI2
    uint microAtx_HDMI2_Color = qRgb(MICROATX_HDMI2_COLOR);
    uint microAtx_HDMI2_ColorShadow = qRgb(MICROATX_HDMI2_COLOR_SHADOW);
    // MICROATX_KBMS_USB_E32
    uint microAtx_KBMS_USB_E32_Color = qRgb(MICROATX_KBMS_USB_E32_COLOR);
    uint microAtx_KBMS_USB_E32_ColorShadow = qRgb(MICROATX_KBMS_USB_E32_COLOR_SHADOW);
    // MICROATX_U32G2_C2
    uint microAtx_U32G2_C2_Color = qRgb(MICROATX_U32G2_C2_COLOR);
    uint microAtx_U32G2_C2_ColorShadow = qRgb(MICROATX_U32G2_C2_COLOR_SHADOW);
    // MICROATX_LAN_USB_E12
    uint microAtx_LAN_USB_E12_Color = qRgb(MICROATX_LAN_USB_E12_COLOR);
    uint microAtx_LAN_USB_E12_ColorShadow = qRgb(MICROATX_LAN_USB_E12_COLOR_SHADOW);
    // MICROATX_AUDIO
    uint microAtx_AUDIO_Color = qRgb(MICROATX_AUDIO_COLOR);
    uint microAtx_AUDIO_ColorShadow = qRgb(MICROATX_AUDIO_COLOR_SHADOW);
    // MICROATX_LGA1200
    uint microAtx_LGA1200_Color = qRgb(MICROATX_LGA1200_COLOR);
    uint microAtx_LGA1200_ColorShadow = qRgb(MICROATX_LGA1200_COLOR_SHADOW);
    // MICROATX_DDR4_DIMM_A1
    uint microAtx_DDR4_DIMM_A1_Color = qRgb(MICROATX_DDR4_DIMM_A1_COLOR);
    uint microAtx_DDR4_DIMM_A1_ColorShadow = qRgb(MICROATX_DDR4_DIMM_A1_COLOR_SHADOW);
    // MICROATX_DDR4_DIMM_A2
    uint microAtx_DDR4_DIMM_A2_Color = qRgb(MICROATX_DDR4_DIMM_A2_COLOR);
    uint microAtx_DDR4_DIMM_A2_ColorShadow = qRgb(MICROATX_DDR4_DIMM_A2_COLOR_SHADOW);
    // MICROATX_DDR4_DIMM_B1
    uint microAtx_DDR4_DIMM_B1_Color = qRgb(MICROATX_DDR4_DIMM_B1_COLOR);
    uint microAtx_DDR4_DIMM_B1_ColorShadow = qRgb(MICROATX_DDR4_DIMM_B1_COLOR_SHADOW);
    // MICROATX_DDR4_DIMM_B2
    uint microAtx_DDR4_DIMM_B2_Color = qRgb(MICROATX_DDR4_DIMM_B2_COLOR);
    uint microAtx_DDR4_DIMM_B2_ColorShadow = qRgb(MICROATX_DDR4_DIMM_B2_COLOR_SHADOW);
    // MICROATX_PCIEX16_1
    uint microAtx_PCIEX16_1_Color = qRgb(MICROATX_PCIEX16_1_COLOR);
    uint microAtx_PCIEX16_1_ColorShadow = qRgb(MICROATX_PCIEX16_1_COLOR_SHADOW);
    // MICROATX_PCIEX16_2
    uint microAtx_PCIEX16_2_Color = qRgb(MICROATX_PCIEX16_2_COLOR);
    uint microAtx_PCIEX16_2_ColorShadow = qRgb(MICROATX_PCIEX16_2_COLOR_SHADOW);

    // MINIITX_USB3_5
    uint miniItx_USB3_5_Color = qRgb(MINIITX_USB3_5_COLOR);
    uint miniItx_USB3_5_ColorShadow = qRgb(MINIITX_USB3_5_COLOR_SHADOW);
    // MINIITX_USB7_10
    uint miniItx_USB7_10_Color = qRgb(MINIITX_USB7_10_COLOR);
    uint miniItx_USB7_10_ColorShadow = qRgb(MINIITX_USB7_10_COLOR_SHADOW);
    // MINIITX_HDMI_DP
    uint miniItx_HDMI_DP_Color = qRgb(MINIITX_HDMI_DP_COLOR);
    uint miniItx_HDMI_DP_ColorShadow = qRgb(MINIITX_HDMI_DP_COLOR_SHADOW);
    // MINIITX_LAN_USB3_34
    uint miniItx_LAN_USB3_34_Color = qRgb(MINIITX_LAN_USB3_34_COLOR);
    uint miniItx_LAN_USB3_34_ColorShadow = qRgb(MINIITX_LAN_USB3_34_COLOR_SHADOW);
    // MINIITX_M2_WIFI
    uint miniItx_M2_WIFI_Color = qRgb(MINIITX_M2_WIFI_COLOR);
    uint miniItx_M2_WIFI_ColorShadow = qRgb(MINIITX_M2_WIFI_COLOR_SHADOW);
    // MINIITX_AUDIO
    uint miniItx_AUDIO_Color = qRgb(MINIITX_AUDIO_COLOR);
    uint miniItx_AUDIO_ColorShadow = qRgb(MINIITX_AUDIO_COLOR_SHADOW);
    // MINIITX_DDR4_DIMM_A1
    uint miniItx_DDR4_DIMM_A1_Color = qRgb(MINIITX_DDR4_DIMM_A1_COLOR);
    uint miniItx_DDR4_DIMM_A1_ColorShadow = qRgb(MINIITX_DDR4_DIMM_A1_COLOR_SHADOW);
    // MINIITX_DDR4_DIMM_B1
    uint miniItx_DDR4_DIMM_B1_Color = qRgb(MINIITX_DDR4_DIMM_B1_COLOR);
    uint miniItx_DDR4_DIMM_B1_ColorShadow = qRgb(MINIITX_DDR4_DIMM_B1_COLOR_SHADOW);
    // MINIITX_PCIEX16_1
    uint miniItx_PCIEX16_1_Color = qRgb(MINIITX_PCIEX16_1_COLOR);
    uint miniItx_PCIEX16_1_ColorShadow = qRgb(MINIITX_PCIEX16_1_COLOR_SHADOW);

    nanoseconds start2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    std::cout << "START DEBUG (borderBuffer)" << std::endl;
    std::cout << "size: " << borderBuffer.size() << " x " << borderBuffer[0].size() << std::endl;
    std::cout << "END DEBUG (borderBuffer)" << std::endl;

    for (size_t i = 0; i < rect.size().width() - 1; i++)
    {
        for (size_t j = 0; j < rect.size().height() - 1; j++)
        {
            if (borderBuffer.at(i).at(j) == 1)
            {
                image->setPixel(i, j, baseColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 2)
            {
                image->setPixel(i, j, baseColor);
            }
            else if (borderBuffer.at(i).at(j) == 3)
            {
                image->setPixel(i, j, borderColor);
            }
            else if (borderBuffer.at(i).at(j) == 4)
            {
                image->setPixel(i, j, brickColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 5)
            {
                image->setPixel(i, j, brickColor);
            }
            else if (borderBuffer.at(i).at(j) == 6)
            {
                image->setPixel(i, j, plateColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 7)
            {
                image->setPixel(i, j, plateColor);
            }
            else if (borderBuffer.at(i).at(j) == 8)
            {
                image->setPixel(i, j, tileColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 9)
            {
                image->setPixel(i, j, tileColor);
            }
            else if (borderBuffer.at(i).at(j) == 10 || borderBuffer.at(i).at(j) == 12)
            {
                image->setPixel(i, j, arcColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 11 || borderBuffer.at(i).at(j) == 13)
            {
                image->setPixel(i, j, arcColor);
            }
            else if (borderBuffer.at(i).at(j) == 14 || borderBuffer.at(i).at(j) == 16)
            {
                image->setPixel(i, j, cylinderColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 15 || borderBuffer.at(i).at(j) == 17)
            {
                image->setPixel(i, j, cylinderColor);
            }
            // ATX_HDMI_DP
            else if (borderBuffer.at(i).at(j) == 18)
            {
                image->setPixel(i, j, atx_HDMI_DP_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 19)
            {
                image->setPixel(i, j, atx_HDMI_DP_Color);
            }
            // ATX_BIOS_FLBK
            else if (borderBuffer.at(i).at(j) == 20)
            {
                image->setPixel(i, j, atx_BIOS_FLBK_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 21)
            {
                image->setPixel(i, j, atx_BIOS_FLBK_Color);
            }
            // ATX_U32G2_1_4
            else if (borderBuffer.at(i).at(j) == 22)
            {
                image->setPixel(i, j, atx_U32G2_1_4_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 23)
            {
                image->setPixel(i, j, atx_U32G2_1_4_Color);
            }
            // ATX_LAN2_U32G2_56
            else if (borderBuffer.at(i).at(j) == 24)
            {
                image->setPixel(i, j, atx_LAN2_U32G2_56_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 25)
            {
                image->setPixel(i, j, atx_LAN2_U32G2_56_Color);
            }
            // ATX_U3252_C8_LAN1_U32G2_7
            else if (borderBuffer.at(i).at(j) == 26)
            {
                image->setPixel(i, j, atx_U3252_C8_LAN1_U32G2_7_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 27)
            {
                image->setPixel(i, j, atx_U3252_C8_LAN1_U32G2_7_Color);
            }
            // ATX_M2_WIFI
            else if (borderBuffer.at(i).at(j) == 28)
            {
                image->setPixel(i, j, atx_M2_WIFI_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 29)
            {
                image->setPixel(i, j, atx_M2_WIFI_Color);
            }
            // ATX_AUDIO
            else if (borderBuffer.at(i).at(j) == 30)
            {
                image->setPixel(i, j, atx_AUDIO_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 31)
            {
                image->setPixel(i, j, atx_AUDIO_Color);
            }
            // ATX_socketM4
            else if (borderBuffer.at(i).at(j) == 32)
            {
                image->setPixel(i, j, atx_socketM4_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 33)
            {
                image->setPixel(i, j, atx_socketM4_Color);
            }
            // ATX_DDR4_DIMM_B1
            else if (borderBuffer.at(i).at(j) == 34)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_B1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 35)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_B1_Color);
            }
            // ATX_DDR4_DIMM_B2
            else if (borderBuffer.at(i).at(j) == 36)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_B2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 37)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_B2_Color);
            }
            // ATX_DDR4_DIMM_A1
            else if (borderBuffer.at(i).at(j) == 38)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_A1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 39)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_A1_Color);
            }
            // ATX_DDR4_DIMM_A2
            else if (borderBuffer.at(i).at(j) == 40)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_A2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 41)
            {
                image->setPixel(i, j, atx_DDR4_DIMM_A2_Color);
            }
            // ATX_PCIEX16_1
            else if (borderBuffer.at(i).at(j) == 42)
            {
                image->setPixel(i, j, atx_PCIEX16_1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 43)
            {
                image->setPixel(i, j, atx_PCIEX16_1_Color);
            }
            // ATX_PCIEX16_2
            else if (borderBuffer.at(i).at(j) == 44)
            {
                image->setPixel(i, j, atx_PCIEX16_2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 45)
            {
                image->setPixel(i, j, atx_PCIEX16_2_Color);
            }
            // ATX_PCIEX16_3
            else if (borderBuffer.at(i).at(j) == 46)
            {
                image->setPixel(i, j, atx_PCIEX16_3_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 47)
            {
                image->setPixel(i, j, atx_PCIEX16_3_Color);
            }
            // MICROATX_HDMI1_DP
            else if (borderBuffer.at(i).at(j) == 48)
            {
                image->setPixel(i, j, microAtx_HDMI1_DP_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 49)
            {
                image->setPixel(i, j, microAtx_HDMI1_DP_Color);
            }
            // MICROATX_HDMI2
            else if (borderBuffer.at(i).at(j) == 50)
            {
                image->setPixel(i, j, microAtx_HDMI2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 51)
            {
                image->setPixel(i, j, microAtx_HDMI2_Color);
            }
            // MICROATX_KBMS_USB_E32
            else if (borderBuffer.at(i).at(j) == 52)
            {
                image->setPixel(i, j, microAtx_KBMS_USB_E32_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 53)
            {
                image->setPixel(i, j, microAtx_KBMS_USB_E32_Color);
            }
            // MICROATX_U32G2_C2
            else if (borderBuffer.at(i).at(j) == 54)
            {
                image->setPixel(i, j, microAtx_U32G2_C2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 55)
            {
                image->setPixel(i, j, microAtx_U32G2_C2_Color);
            }
            // MICROATX_LAN_USB_E12
            else if (borderBuffer.at(i).at(j) == 56)
            {
                image->setPixel(i, j, microAtx_LAN_USB_E12_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 57)
            {
                image->setPixel(i, j, microAtx_LAN_USB_E12_Color);
            }
            // MICROATX_AUDIO
            else if (borderBuffer.at(i).at(j) == 58)
            {
                image->setPixel(i, j, microAtx_AUDIO_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 59)
            {
                image->setPixel(i, j, microAtx_AUDIO_Color);
            }
            // MICROATX_LGA1200
            else if (borderBuffer.at(i).at(j) == 60)
            {
                image->setPixel(i, j, microAtx_LGA1200_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 61)
            {
                image->setPixel(i, j, microAtx_LGA1200_Color);
            }
            // MICROATX_DDR4_DIMM_A1
            else if (borderBuffer.at(i).at(j) == 62)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_A1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 63)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_A1_Color);
            }
            // MICROATX_DDR4_DIMM_A2
            else if (borderBuffer.at(i).at(j) == 64)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_A2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 65)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_A2_Color);
            }
            // MICROATX_DDR4_DIMM_B1
            else if (borderBuffer.at(i).at(j) == 66)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_B1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 67)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_B1_Color);
            }
            // MICROATX_DDR4_DIMM_B2
            else if (borderBuffer.at(i).at(j) == 68)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_B2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 69)
            {
                image->setPixel(i, j, microAtx_DDR4_DIMM_B2_Color);
            }
            // MICROATX_PCIEX16_1
            else if (borderBuffer.at(i).at(j) == 70)
            {
                image->setPixel(i, j, microAtx_PCIEX16_1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 71)
            {
                image->setPixel(i, j, microAtx_PCIEX16_1_Color);
            }
            // MICROATX_PCIEX16_2
            else if (borderBuffer.at(i).at(j) == 72)
            {
                image->setPixel(i, j, microAtx_PCIEX16_2_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 73)
            {
                image->setPixel(i, j, microAtx_PCIEX16_2_Color);
            }
            // MINIITX_USB3_5
            else if (borderBuffer.at(i).at(j) == 74)
            {
                image->setPixel(i, j, miniItx_USB3_5_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 75)
            {
                image->setPixel(i, j, miniItx_USB3_5_Color);
            }
            // MINIITX_USB7_10
            else if (borderBuffer.at(i).at(j) == 76)
            {
                image->setPixel(i, j, miniItx_USB7_10_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 77)
            {
                image->setPixel(i, j, miniItx_USB7_10_Color);
            }
            // MINIITX_HDMI_DP
            else if (borderBuffer.at(i).at(j) == 78)
            {
                image->setPixel(i, j, miniItx_HDMI_DP_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 79)
            {
                image->setPixel(i, j, miniItx_HDMI_DP_Color);
            }
            // MINIITX_LAN_USB3_34
            else if (borderBuffer.at(i).at(j) == 80)
            {
                image->setPixel(i, j, miniItx_LAN_USB3_34_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 81)
            {
                image->setPixel(i, j, miniItx_LAN_USB3_34_Color);
            }
            // MINIITX_M2_WIFI
            else if (borderBuffer.at(i).at(j) == 82)
            {
                image->setPixel(i, j, miniItx_M2_WIFI_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 83)
            {
                image->setPixel(i, j, miniItx_M2_WIFI_Color);
            }
            // MINIITX_AUDIO
            else if (borderBuffer.at(i).at(j) == 84)
            {
                image->setPixel(i, j, miniItx_AUDIO_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 85)
            {
                image->setPixel(i, j, miniItx_AUDIO_Color);
            }
            // MINIITX_DDR4_DIMM_A1
            else if (borderBuffer.at(i).at(j) == 86)
            {
                image->setPixel(i, j, miniItx_DDR4_DIMM_A1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 87)
            {
                image->setPixel(i, j, miniItx_DDR4_DIMM_A1_Color);
            }
            // MINIITX_DDR4_DIMM_B1
            else if (borderBuffer.at(i).at(j) == 88)
            {
                image->setPixel(i, j, miniItx_DDR4_DIMM_B1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 89)
            {
                image->setPixel(i, j, miniItx_DDR4_DIMM_B1_Color);
            }
            // MINIITX_PCIEX16_1
            else if (borderBuffer.at(i).at(j) == 90)
            {
                image->setPixel(i, j, miniItx_PCIEX16_1_ColorShadow);
            }
            else if (borderBuffer.at(i).at(j) == 91)
            {
                image->setPixel(i, j, miniItx_PCIEX16_1_Color);
            }
        }
    }

    nanoseconds end2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
    qDebug() << "Отрисовка" << size_t((end2 - start2).count() / 1000000);
    qDebug() << "Общее время"     << size_t((end2 - start2).count() / 1000000) +
                                     size_t((end - start).count()   / 1000000);


    outScene->addPixmap(QPixmap::fromImage(*image));
    delete image;
    for (size_t i = 0; i < scene->getLightNum(); i++)
        scene->getLight(i).clearShadowMap();

    return outScene;
}
