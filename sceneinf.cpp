#include "sceneinf.hpp"

SceneInf::SceneInf()
{
    std::cout << "SceneInf::SceneInf(default)" << std::endl;
}

SceneInf::SceneInf(size_t width_, size_t height_)
{
    std::cout << "SceneInf::SceneInf(width = " << width_ << ", height = " << height_ << ")" << std::endl;
    width = width_;
    height = height_;

    modelsNum = 0;
    lightNum = 0;

    // initUsedCellsZ();
    toCenter();
}

SceneInf::SceneInf(size_t width_, size_t height_, int type_)
{
    std::cout << "SceneInf::SceneInf(width = " << width_ << ", height = " << height_ << ", type = " << type_ << ")" << std::endl;
    type = type_;
    width = width_;
    height = height_;

    modelsNum = 0;
    lightNum = 0;

    // initUsedCellsZ();
    toCenter();

    startOfScene = Dot3D(BASE_START);
    endOfScene = Dot3D(width, height, BASE_Z);
    std::cout << "SceneInf::SceneInf -> start of scene: " << startOfScene;
    std::cout << "SceneInf::SceneInf -> end of scene: " << endOfScene;
}

size_t SceneInf::getWidth()
{
    return width;
}

size_t SceneInf::getHeight()
{
    return height;
}

SceneInf::operator bool() const
{
    return this->plateModel;
}

void SceneInf::markUsedCellsZ(size_t num) // deprecated
{
    int xCell = models[num].getUsedXCell();
    int yCell = models[num].getUsedYCell();
    double zCell = models[num].getUsedZCell();
    int widthModel = models[num].getLengthModel();
    int heightModel = models[num].getWidthModel();
    PolygonModel::model_t modelType_ = models[num].getModelType();

    for (int i = yCell; i < yCell + heightModel; i++)
    {
        for (int j = xCell; j < xCell + widthModel; j++)
        {
            getUsedCellsZ()[i][j].push_back(zCell);

            if (modelType_ == PolygonModel::model_t::Tile)
                getUsedCellsZ()[i][j].push_back(-1);
        }
    }
}



void SceneInf::clearUsedCellsZ(size_t num) // deprecated
{
    int xCell = models[num].getUsedXCell();
    int yCell = models[num].getUsedYCell();
    int widthModel = models[num].getLengthModel();
    int heightModel = models[num].getWidthModel();
    PolygonModel::model_t modelType_ = models[num].getModelType();

    for (int i = yCell; i < yCell + heightModel; i++)
    {
        for (int j = xCell; j < xCell + widthModel; j++)
        {
            if (modelType_ == PolygonModel::model_t::Tile)
                getUsedCellsZ()[i][j].erase(getUsedCellsZ()[i][j].end() - 1);
            getUsedCellsZ()[i][j].erase(getUsedCellsZ()[i][j].end() - 1);
            qDebug() << "i = " << i << "j = " << j << "освобождена";
        }
    }
}

void SceneInf::moveUp(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, -value, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveDown(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, value, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveLeft(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        -value, 0, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveRight(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        value, 0, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::scale(double value)
{
    Eigen::Matrix4f scaleMatrix;
    scaleMatrix << value,     0,     0, 0,
        0,    value,     0, 0,
        0,        0, value, 0,
        0,        0,     0, 1;

    transMatrix *= scaleMatrix;
}

void SceneInf::rotateX(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << 1,           0,          0, 0,
        0, cos(angle), -sin(angle), 0,
        0, sin(angle),  cos(angle), 0,
        0,           0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::rotateY(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle),  0, sin(angle), 0,
        0,           1,          0, 0,
        -sin(angle), 0, cos(angle), 0,
        0,           0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::rotateZ(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle),  -sin(angle), 0, 0,
        sin(angle),   cos(angle), 0, 0,
        0,            0,          1, 0,
        0,            0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::toCenter()
{
    Dot3D start(BASE_START);

    Eigen::Matrix4f newMat;

    newMat << 1,  0, 0, 0,
        0,  1, 0, 0,
        0,  0, 1, 0,
        0,  0, 0, 1;

    newMat(3, 0) = X_CENTER - start.getXCoordinate() - getWidth() * SIZE_SC / 2;
    newMat(3, 1) = Y_CENTER - start.getYCoordinate() - getHeight() * SIZE_SC / 2;
    newMat(3, 2) = 0;

    transMatrix = newMat;
}


size_t SceneInf::getModelsNum()
{
    return modelsNum;
}

PolygonModel &SceneInf::getModel(size_t num)
{
    return models.at(num);
}

void SceneInf::setModel(size_t num, PolygonModel &newModel)
{
    // std::cout << "================================================" << std::endl;
    models.at(num) = newModel;
}

void SceneInf::addModel(PolygonModel &model)
{
    std::cout << "SceneInf::addModel" << std::endl;
    models.push_back(model);
    modelsNum = models.size();
    std::cout << "modelsNum: " << modelsNum << std::endl;
    // markUsedCellsZ(modelsNum - 1);
    //    printUsedCellsZ();
}

size_t SceneInf::getLightNum()
{
    return lightNum;
}

Light &SceneInf::getLight(size_t num)
{
    return Lights.at(num);
}

void SceneInf::setLight(Light &light, size_t i)
{
    Lights.at(i) = light;
}

void SceneInf::addLight(Light &light)
{
    lightNum++;
    Lights.push_back(light);
}

void SceneInf::deleteLight(size_t num)
{
    if (num < Lights.size())
    {
        lightNum--;
        Lights.erase(Lights.begin() + num);
    }
}

void SceneInf::deleteModel(size_t num)
{
    if (num < models.size())
    {
        // clearUsedCellsZ(num);
        modelsNum--;
        models.erase(models.begin() + num);
    }
}

void SceneInf::printUsedCellsZ()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)

            qDebug() << "(" << i + 1<< "; " << j + 1<< ") " << getUsedCellsZ()[i][j];
    }
}

std::vector<PolygonModel> SceneInf::getModels() const
{
    return models;
}


PolygonModel &SceneInf::getBaseModel()
{
    return *plateModel;
}

void SceneInf::buildBaseModel(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    std::cout << "--> SceneInf::buildBaseModel" << std::endl;
    switch (type)
    {
    case 0:
        buildATXMotherboard(startOfPlate_, endOfPlate_);
        break;
    case 1:
        buildMicroATXMotherboard(startOfPlate_, endOfPlate_);
        break;
    case 2:
        buildMiniITXMotherboard(startOfPlate_, endOfPlate_);
        break;
    default:
        std::cout << "unknown motherboard type" << std::endl;
    }
}

void SceneInf::addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets, int x1,
                       int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4)
{
    Dot3D dot;
    std::vector<size_t> vec;

    size_t size = facets.size();

    dot = Dot3D(x1, y1, z1);
    vec = {size, size + 1};
    vertices.push_back(Vertex(dot, vec));

    dot = Dot3D(x2, y2, z2);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Dot3D(x3, y3, z3);
    vec = {size, size + 1};
    vertices.push_back(Vertex(dot, vec));

    dot = Dot3D(x4, y4, z4);
    vec = {size + 1};
    vertices.push_back(Vertex(dot, vec));

    size = vertices.size();
    vec = {size - 4, size - 3, size - 2};
    facets.push_back(vec);
    vec = {size - 4, size - 2, size - 1};
    facets.push_back(vec);
}

void SceneInf::addParallelepiped(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                       double x, double y, double z, double width, double height, double depth)
{
    // Front face
    addQuad(vertices, facets, x, y, z, x + width, y, z, x + width, y + height, z, x, y + height, z);
    // Back face
    addQuad(vertices, facets, x, y, z - depth, x + width, y, z - depth, x + width, y + height, z - depth, x, y + height, z - depth);
    // Left face
    addQuad(vertices, facets, x, y, z, x, y + height, z, x, y + height, z - depth, x, y, z - depth);
    // Right face
    addQuad(vertices, facets, x + width, y, z, x + width, y + height, z, x + width, y + height, z - depth, x + width, y, z - depth);
    // Top face
    addQuad(vertices, facets, x, y + height, z, x + width, y + height, z, x + width, y + height, z - depth, x, y + height, z - depth);
    // Bottom face
    addQuad(vertices, facets, x, y, z, x + width, y, z, x + width, y, z - depth, x, y, z - depth);
}

void SceneInf::addFrame(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                        double x, double y, double z, double width, double height, double depth,
                        double topFrameWidth, double bottomFrameWidth, double leftFrameWidth, double rightFrameWidth)
{
    // Top border
    addParallelepiped(vertices, facets, x, y, z, width, topFrameWidth, depth);
    // Bottom border
    addParallelepiped(vertices, facets, x, y + height - bottomFrameWidth, z, width, bottomFrameWidth, depth);
    // Left border
    addParallelepiped(vertices, facets, x, y + topFrameWidth, z, leftFrameWidth, height - topFrameWidth - bottomFrameWidth, depth);
    // Right border
    addParallelepiped(vertices, facets, x + width - rightFrameWidth, y + topFrameWidth, z, rightFrameWidth, height - topFrameWidth - bottomFrameWidth, depth);
}

void SceneInf::addTriangle(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                         int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3)
{
    std::cout << "Facade::addTriangle" << std::endl;
    Dot3D dot;
    std::vector<size_t> vec;

    size_t size = facets.size();

    dot = Dot3D(x1, y1, z1);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Dot3D(x2, y2, z2);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    dot = Dot3D(x3, y3, z3);
    vec = {size};
    vertices.push_back(Vertex(dot, vec));

    size = vertices.size();
    vec = {size - 3, size - 2, size - 1};
    facets.push_back(vec);
}

void SceneInf::addCylinder(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                           double x, double y, double z, double radius, double height, int segments)
{
    double angleStep = 360.0 / segments;
    double rad, nextRad;
    int xr, yr, xrN, yrN;

    // Calculate positions for cylinder caps and side walls
    for (int i = 0; i < 360; i += angleStep) {
        rad = i * PI / 180;
        nextRad = (i + angleStep) * PI / 180;

        xr = x + radius * cos(rad);
        yr = y + radius * sin(rad);
        xrN = x + radius * cos(nextRad);
        yrN = y + radius * sin(nextRad);

        // Side wall
        addQuad(vertices, facets,
                xr, yr, z,
                xrN, yrN, z,
                xrN, yrN, z + height,
                xr, yr, z + height);

        // Top cap
        addTriangle(vertices, facets,
                    x, y, z + height,
                    xr, yr, z + height,
                    xrN, yrN, z + height);

        // Bottom cap
        addTriangle(vertices, facets,
                    x, y, z,
                    xrN, yrN, z,
                    xr, yr, z);
    }
}


void SceneInf::buildBasePlate(std::vector<Vertex> &vertices, std::vector<Facet> &facets, Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    addQuad(vertices, facets,
            startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate(), BASE_Z,
            endOfPlate_.getXCoordinate() + 10 , startOfPlate_.getYCoordinate(), BASE_Z,
            endOfPlate_.getXCoordinate() + 10 , endOfPlate_.getYCoordinate() + 10 , BASE_Z,
            startOfPlate_.getXCoordinate(), endOfPlate_.getYCoordinate() + 10 , BASE_Z);
    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT);

    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z);

    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z);
}

void SceneInf::changeSize(size_t newWidth, size_t newHeight)
{
    if (newWidth)
    {
        if (newWidth < width)
        {
            for (size_t i = 0; i < modelsNum; i++)
            {
                if (getModel(i).getUsedXCell() >= (int)newWidth)
                {
                    deleteModel(i);
                    i--;
                }
            }
        }

        width = newWidth;
    }


    if (newHeight)
    {
        if (newHeight < height)
        {
            for (size_t i = 0; i < modelsNum; i++)
            {
                if (getModel(i).getUsedYCell() >= (int)newHeight)
                {
                    deleteModel(i);
                    i--;
                }
            }
        }

        height = newHeight;
    }
}

Eigen::Matrix4f &SceneInf::getTransMatrix() { return transMatrix; }

void SceneInf::initUsedCellsZ()
{
    usedCellsZ.resize(getHeight());

    for (size_t i = 0; i < getHeight(); i++)
    {
        usedCellsZ[i].resize(getWidth());
        for (size_t j = 0; j < getWidth(); j++)
            usedCellsZ[i][j].resize(1, 0);
    }

}

std::vector<std::vector<std::vector<double>>> &SceneInf::getUsedCellsZ()
{
    return usedCellsZ;
}

/*
 * ======================= ATX build logic =======================
*/

void SceneInf::buildATXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    std::cout << "SceneInf::buildATXMotherboard" << std::endl;
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    ATXMotherboardConfig ATXConfig(startOfPlate_, endOfPlate_);

    buildBasePlate(vertices, facets, startOfPlate_, endOfPlate_);

    if (plateModel)
        delete plateModel;
    plateModel = new PolygonModel(vertices, facets);

    addMotherboardComponent(ATXConfig.HDMI_DP, "ATX_HDMI_DP", PolygonModel::ATX_HDMI_DP);
    addMotherboardComponent(ATXConfig.BIOS_FLBK, "ATX_BIOS_FLBK", PolygonModel::ATX_BIOS_FLBK);
    addMotherboardComponent(ATXConfig.U32G2_1_4, "ATX_U32G2_1_4", PolygonModel::ATX_U32G2_1_4);
    addMotherboardComponent(ATXConfig.LAN2_U32G2_56, "ATX_LAN2_U32G2_56", PolygonModel::ATX_LAN2_U32G2_56);
    addMotherboardComponent(ATXConfig.U3252_C8_LAN1_U32G2_7, "ATX_U3252_C8_LAN1_U32G2_7", PolygonModel::ATX_U3252_C8_LAN1_U32G2_7);
    addMotherboardComponent(ATXConfig.M2_WIFI, "ATX_M2_WIFI", PolygonModel::ATX_M2_WIFI);
    addMotherboardComponent(ATXConfig.AUDIO, "ATX_AUDIO", PolygonModel::ATX_AUDIO);
    addMotherboardComponent(ATXConfig.socketAM4, "ATX_socketM4", PolygonModel::ATX_socketAM4);
    addMotherboardComponent(ATXConfig.DDR4_DIMM_B1, "ATX_DDR4_DIMM_B1", PolygonModel::ATX_DDR4_DIMM_B1);
    addMotherboardComponent(ATXConfig.DDR4_DIMM_B2, "ATX_DDR4_DIMM_B2", PolygonModel::ATX_DDR4_DIMM_B2);
    addMotherboardComponent(ATXConfig.DDR4_DIMM_A1, "ATX_DDR4_DIMM_A1", PolygonModel::ATX_DDR4_DIMM_A1);
    addMotherboardComponent(ATXConfig.DDR4_DIMM_A2, "ATX_DDR4_DIMM_A2", PolygonModel::ATX_DDR4_DIMM_A2);
    addMotherboardComponent(ATXConfig.PCIEX16_1, "ATX_PCIEX16_1", PolygonModel::ATX_PCIEX16_1);
    addMotherboardComponent(ATXConfig.PCIEX16_2, "ATX_PCIEX16_2", PolygonModel::ATX_PCIEX16_2);
    addMotherboardComponent(ATXConfig.PCIEX16_3, "ATX_PCIEX16_3", PolygonModel::ATX_PCIEX16_3);
    addMotherboardComponent(ATXConfig.C22110_1, "ATX_C22110_1", PolygonModel::ATX_C22110_1);
    addMotherboardComponent(ATXConfig.C2280_1, "ATX_C2280_1", PolygonModel::ATX_C2280_1);
    addMotherboardComponent(ATXConfig.C2260_1, "ATX_C2260_1", PolygonModel::ATX_C2260_1);
    addMotherboardComponent(ATXConfig.C2242_1, "ATX_C2242_1", PolygonModel::ATX_C2242_1);
    addMotherboardComponent(ATXConfig.C22110_2, "ATX_C22110_2", PolygonModel::ATX_C22110_2);
    addMotherboardComponent(ATXConfig.C2280_2, "ATX_C2280_2", PolygonModel::ATX_C2280_2);
    addMotherboardComponent(ATXConfig.C2260_2, "ATX_C2260_2", PolygonModel::ATX_C2260_2);
    addMotherboardComponent(ATXConfig.C2242_2, "ATX_C2260_2", PolygonModel::ATX_C2242_2);
    addMotherboardComponent(ATXConfig.BATTERY, "ATX_BATTERY", PolygonModel::ATX_BATTERY);
    addMotherboardComponent(ATXConfig.AMDX570, "ATX_AMDX570", PolygonModel::ATX_AMDX570);
    addMotherboardComponent(ATXConfig.SATA6G_1, "ATX_SATA6G_1", PolygonModel::ATX_SATA6G_1);
    addMotherboardComponent(ATXConfig.SATA6G_2, "ATX_SATA6G_2", PolygonModel::ATX_SATA6G_2);
    addMotherboardComponent(ATXConfig.SATA6G_3, "ATX_SATA6G_3", PolygonModel::ATX_SATA6G_3);
    addMotherboardComponent(ATXConfig.SATA6G_4, "ATX_SATA6G_4", PolygonModel::ATX_SATA6G_4);
    addMotherboardComponent(ATXConfig.SATA6G_5, "ATX_SATA6G_5", PolygonModel::ATX_SATA6G_5);
    addMotherboardComponent(ATXConfig.SATA6G_6, "ATX_SATA6G_6", PolygonModel::ATX_SATA6G_6);
    addMotherboardComponent(ATXConfig.SATA6G_7, "ATX_SATA6G_7", PolygonModel::ATX_SATA6G_7);
    addMotherboardComponent(ATXConfig.SATA6G_8, "ATX_SATA6G_8", PolygonModel::ATX_SATA6G_8);
}

/*
 * ======================= Micro-ATX build logic =======================
*/

void SceneInf::buildMicroATXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    std::cout << "SceneInf::buildMicroATXMotherboard" << std::endl;
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    MicroATXMotherboardConfig microATXConfig(startOfPlate_, endOfPlate_);

    buildBasePlate(vertices, facets, startOfPlate_, endOfPlate_);

    if (plateModel)
        delete plateModel;
    plateModel = new PolygonModel(vertices, facets);

    addMotherboardComponent(microATXConfig.HDMI1_DP, "MICROATX_HDMI1_DP", PolygonModel::MICROATX_HDMI1_DP);
    addMotherboardComponent(microATXConfig.HDMI2, "MICROATX_HDMI2", PolygonModel::MICROATX_HDMI2);
    addMotherboardComponent(microATXConfig.KBMS_USB_E32, "MICROATX_KBMS_USB_E32", PolygonModel::MICROATX_KBMS_USB_E32);
    addMotherboardComponent(microATXConfig.U32G2_C2, "MICROATX_U32G2_C2", PolygonModel::MICROATX_U32G2_C2);
    addMotherboardComponent(microATXConfig.LAN_USB_E12, "MICROATX_LAN_USB_E12", PolygonModel::MICROATX_LAN_USB_E12);
    addMotherboardComponent(microATXConfig.AUDIO, "MICROATX_AUDIO", PolygonModel::MICROATX_AUDIO);
    addMotherboardComponent(microATXConfig.LGA1200, "MICROATX_LGA1200", PolygonModel::MICROATX_LGA1200);
    addMotherboardComponent(microATXConfig.DDR4_DIMM_A1, "MICROATX_DDR4_DIMM_A1", PolygonModel::MICROATX_DDR4_DIMM_A1);
    addMotherboardComponent(microATXConfig.DDR4_DIMM_A2, "MICROATX_DDR4_DIMM_A2", PolygonModel::MICROATX_DDR4_DIMM_A2);
    addMotherboardComponent(microATXConfig.DDR4_DIMM_B1, "MICROATX_DDR4_DIMM_B1", PolygonModel::MICROATX_DDR4_DIMM_B1);
    addMotherboardComponent(microATXConfig.DDR4_DIMM_B2, "MICROATX_DDR4_DIMM_B2", PolygonModel::MICROATX_DDR4_DIMM_B2);
    addMotherboardComponent(microATXConfig.PCIEX16_1, "MICROATX_PCIEX16_1", PolygonModel::MICROATX_PCIEX16_1);
    addMotherboardComponent(microATXConfig.PCIEX16_2, "MICROATX_PCIEX16_2", PolygonModel::MICROATX_PCIEX16_2);
    addMotherboardComponent(microATXConfig.C2242_1, "MICROATX_C2242_1", PolygonModel::MICROATX_C2242_1);
    addMotherboardComponent(microATXConfig.C2260_1, "MICROATX_C2260_1", PolygonModel::MICROATX_C2260_1);
    addMotherboardComponent(microATXConfig.C2280_1, "MICROATX_C2280_1", PolygonModel::MICROATX_C2280_1);
    addMotherboardComponent(microATXConfig.C2242_2, "MICROATX_C2242_2", PolygonModel::MICROATX_C2242_2);
    addMotherboardComponent(microATXConfig.C2260_2, "MICROATX_C2260_2", PolygonModel::MICROATX_C2260_2);
    addMotherboardComponent(microATXConfig.C2280_2, "MICROATX_C2280_2", PolygonModel::MICROATX_C2280_2);
    addMotherboardComponent(microATXConfig.BATTERY, "MICROATX_BATTERY", PolygonModel::MICROATX_BATTERY);
    addMotherboardComponent(microATXConfig.SATA6G_1, "MICROATX_SATA6G_1", PolygonModel::MICROATX_SATA6G_1);
    addMotherboardComponent(microATXConfig.SATA6G_2, "MICROATX_SATA6G_2", PolygonModel::MICROATX_SATA6G_2);
    addMotherboardComponent(microATXConfig.SATA6G_3, "MICROATX_SATA6G_3", PolygonModel::MICROATX_SATA6G_3);
    addMotherboardComponent(microATXConfig.SATA6G_4, "MICROATX_SATA6G_4", PolygonModel::MICROATX_SATA6G_4);
}

/*
 * ======================= Mini-ITX build logic =======================
*/
void SceneInf::buildMiniITXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    std::cout << "SceneInf::buildMiniITXMotherboard" << std::endl;
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    MiniITXMotherboardConfig miniITXConfig(startOfPlate_, endOfPlate_);

    buildBasePlate(vertices, facets, startOfPlate_, endOfPlate_);

    if (plateModel)
        delete plateModel;
    plateModel = new PolygonModel(vertices, facets);

    addMotherboardComponent(miniITXConfig.USB3_5, "MINIITX_USB3_5", PolygonModel::MINIITX_USB3_5);
    addMotherboardComponent(miniITXConfig.USB7_10, "MINIITX_USB7_10", PolygonModel::MINIITX_USB7_10);
    addMotherboardComponent(miniITXConfig.HDMI_DP, "MINIITX_HDMI_DP", PolygonModel::MINIITX_HDMI_DP);
    addMotherboardComponent(miniITXConfig.LAN_USB3_34, "MINIITX_LAN_USB3_34", PolygonModel::MINIITX_LAN_USB3_34);
    addMotherboardComponent(miniITXConfig.M2_WIFI, "MINIITX_M2_WIFI", PolygonModel::MINIITX_M2_WIFI);
    addMotherboardComponent(miniITXConfig.AUDIO, "MINIITX_AUDIO", PolygonModel::MINIITX_AUDIO);
    addMotherboardComponent(miniITXConfig.DDR4_DIMM_A1, "MINIITX_DDR4_DIMM_A1", PolygonModel::MINIITX_DDR4_DIMM_A1);
    addMotherboardComponent(miniITXConfig.DDR4_DIMM_B1, "MINIITX_DDR4_DIMM_B1", PolygonModel::MINIITX_DDR4_DIMM_B1);
    addMotherboardComponent(miniITXConfig.PCIEX16_1, "MINIITX_PCIEX16_1", PolygonModel::MINIITX_PCIEX16_1);
    addMotherboardComponent(miniITXConfig.C2280, "MINIITX_C2280", PolygonModel::MINIITX_C2280);
    addMotherboardComponent(miniITXConfig.C2260, "MINIITX_C2260", PolygonModel::MINIITX_C2260);
}

void SceneInf::addMotherboardComponent(ComponentConfig &config, QString modelName, PolygonModel::model_t modelType)
{
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }
    for (auto &c : config.cylinders)
    {
        addCylinder(vertices, facets, c.x, c.y, c.z, c.radius, c.height, c.segments);
    }
    PolygonModel layoutComponent(vertices, facets, modelName);
    layoutComponent.setModelType(modelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}

void SceneInf::addRAMBlock(ComponentConfig &config, QString modelName, ConfigManager::RAMType RAMType)
{
    PolygonModel::model_t RAMPolygonModelType = parseRAMModel(RAMType);
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }
    PolygonModel layoutComponent(vertices, facets, modelName);
    layoutComponent.setModelType(RAMPolygonModelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}

void SceneInf::addRAMAccBlock(ComponentConfig &config, QString accName, ConfigManager::RAMAccessoriesType RAMAccType)
{
    PolygonModel::model_t RAMAccPolygonModelType = parseRAMAccModel(RAMAccType);

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }

    PolygonModel layoutComponent(vertices, facets, accName);
    layoutComponent.setModelType(RAMAccPolygonModelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}

void SceneInf::addGPUBlock(ComponentConfig &config, QString modelName, ConfigManager::GPUType GPUType)
{
    PolygonModel::model_t GPUPolygonModelType = parseGPUModel(GPUType);
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }
    PolygonModel layoutComponent(vertices, facets, modelName);
    layoutComponent.setModelType(GPUPolygonModelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}

void SceneInf::addGPUAccBlock(ComponentConfig &config, QString accName, ConfigManager::GPUAccessoriesType GPUAccType)
{
    PolygonModel::model_t GPUAccPolygonModelType = parseGPUAccModel(GPUAccType);

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }

    PolygonModel layoutComponent(vertices, facets, accName);
    layoutComponent.setModelType(GPUAccPolygonModelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}

void SceneInf::addCPUBlock(ComponentConfig &config, QString modelName, ConfigManager::CPUType CPUType)
{
    PolygonModel::model_t CPUPolygonModelType = parseCPUModel(CPUType);
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    for (auto &p : config.parallelepipeds)
    {
        addParallelepiped(vertices, facets, p.x, p.y, p.z, p.width, p.height, p.depth);
    }
    for (auto &f : config.frames)
    {
        addFrame(vertices, facets, f.x, f.y, f.z, f.width, f.height, f.depth, f.topFrameWidth, f.bottomFrameWidth, f.leftFrameWidth, f.rightFrameWidth);
    }
    PolygonModel layoutComponent(vertices, facets, modelName);
    layoutComponent.setModelType(CPUPolygonModelType);
    layoutComponent.setModelNum(modelsNum);
    addModel(layoutComponent);
}
