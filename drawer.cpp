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
        zBufForModel(facets, vertices, scene->getTransMatrix(), 4 + typeModel * 2, scene, bufWidth, bufHeight); // ID
    }
    model = scene->getBaseModel();
    facets = model.getFacets();
    vertices = model.getVertices();
    zBufForModel(facets, vertices, scene->getTransMatrix(), 1, scene, bufWidth, bufHeight);

    for (size_t i = 0; i < scene->getLightNum(); i++)
        scene->getLight(i).clearShadowMap();
}

QGraphicsScene *Drawer::drawScene(SceneInf *scene, QRectF rect, Color cpuColor, Color cpuShadow, Color ramColor, Color ramShadow, Color gpuColor, Color gpuShadow)
{
    size_t width = scene->getWidth() * SIZE_SC;
    size_t height = scene->getHeight() * SIZE_SC;

    scene->buildBaseModel(Dot3D(BASE_START), Dot3D(width, height, BASE_Z));

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

    nanoseconds start2 = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());

    // ATX color
    applyDefaultColor(image, rect, atxPeripheriaSockets, Color::SILVER, Color::GRAY);
    applyDefaultColor(image, rect, atxCpuSocket, Color::GRAY, Color::DIM_GRAY);
    applyDefaultColor(image, rect, atxRamSockets_01, Color::BLUE, Color::DARK_BLUE);
    applyDefaultColor(image, rect, atxRamSockets_02, Color::YELLOW, Color::OLIVE);
    applyDefaultColor(image, rect, atxGpuSockets, Color::KHAKI, Color::DARK_KHAKI);
    applyDefaultColor(image, rect, atxCapacitors, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);
    applyDefaultColor(image, rect, atxSataSockets, Color::RED, Color::DARK_RED);
    applyDefaultColor(image, rect, atxEatxSockets, Color::LIGHT_BLUE, Color::DARK_LIGHT_BLUE);
    applyDefaultColor(image, rect, atxConnectors, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, atxMicrochips, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, atxBattery, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);

    // Micro-ATX color
    applyDefaultColor(image, rect, microAtxPeripheriaSockets, Color::SILVER, Color::GRAY);
    applyDefaultColor(image, rect, microAtxCpuSocket, Color::GRAY, Color::DIM_GRAY);
    applyDefaultColor(image, rect, microAtxRamSockets_01, Color::BLUE, Color::DARK_BLUE);
    applyDefaultColor(image, rect, microAtxRamSockets_02, Color::YELLOW, Color::OLIVE);
    applyDefaultColor(image, rect, microAtxGpuSockets, Color::KHAKI, Color::DARK_KHAKI);
    applyDefaultColor(image, rect, microAtxCapacitors, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);
    applyDefaultColor(image, rect, microAtxSataSockets, Color::RED, Color::DARK_RED);
    applyDefaultColor(image, rect, microAtxAtxSockets, Color::LIGHT_BLUE, Color::DARK_LIGHT_BLUE);
    applyDefaultColor(image, rect, microAtxConnectors, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, microAtxMicrochips, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, microAtxBattery, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);

    // Mini-ITX color
    applyDefaultColor(image, rect, miniItxPeripheriaSockets, Color::SILVER, Color::GRAY);
    applyDefaultColor(image, rect, miniItxCpuSocket, Color::GRAY, Color::DIM_GRAY);
    applyDefaultColor(image, rect, miniItxRamSockets_01, Color::BLUE, Color::DARK_BLUE);
    applyDefaultColor(image, rect, miniItxRamSockets_02, Color::YELLOW, Color::OLIVE);
    applyDefaultColor(image, rect, miniItxGpuSockets, Color::KHAKI, Color::DARK_KHAKI);
    applyDefaultColor(image, rect, miniItxCapacitors, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);
    applyDefaultColor(image, rect, miniItxSataSockets, Color::RED, Color::DARK_RED);
    applyDefaultColor(image, rect, miniItxAtxSockets, Color::LIGHT_BLUE, Color::DARK_LIGHT_BLUE);
    applyDefaultColor(image, rect, miniItxConnectors, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, miniItxMicrochips, Color::DARK_GRAY, Color::DARK_DARK_GRAY);
    applyDefaultColor(image, rect, miniItxBattery, Color::LIGHT_SILVER, Color::DARK_LIGHT_SILVER);

    // CPU color
    applyDefaultColor(image, rect, cpuIntelBlock, cpuColor, cpuShadow);
    applyDefaultColor(image, rect, cpuAMDBlock, cpuColor, cpuShadow);
    applyDefaultColor(image, rect, cpuAccBlocks, Color::DARK_GRAY, Color::DARK_DARK_GRAY);

    // GPU color
    applyDefaultColor(image, rect, gpuBlocks, gpuColor, gpuShadow);
    applyDefaultColor(image, rect, gpuAccBlocks, Color::GRAY, Color::DIM_GRAY);

    // RAM color
    applyDefaultColor(image, rect, ramBlocks, ramColor, ramShadow);
    applyDefaultColor(image, rect, ramAccBlocks, Color::GRAY, Color::DIM_GRAY);

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

void Drawer::applyDefaultColor(QImage *image, QRectF rect, std::vector<PolygonModel::model_t> models, Color color, Color shadow)
{
    uint colorUint = qRgb(color.r, color.g, color.b);
    uint shadowUint = qRgb(shadow.r, shadow.g, shadow.b);
    std::vector<int> colorIDs;
    std::vector<int> shadowIDs;
    for (auto &model : models)
    {
        int colorID = ((model + 2) * 2) + 1;
        int shadowID = ((model + 2) * 2);
        colorIDs.push_back(colorID);
        shadowIDs.push_back(shadowID);
    }

    for (size_t i = 0; i < rect.size().width() - 1; i++)
    {
        for (size_t j = 0; j < rect.size().height() - 1; j++)
        {
            int bufferValue = borderBuffer.at(i).at(j);
            if (std::find(shadowIDs.begin(), shadowIDs.end(), bufferValue) != shadowIDs.end())
            {
                image->setPixel(i, j, shadowUint);
            }
            else if (std::find(colorIDs.begin(), colorIDs.end(), bufferValue) != colorIDs.end())
            {
                image->setPixel(i, j, colorUint);
            }
        }
    }
}

