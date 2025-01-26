#include "facade.hpp"

Facade::Facade(ConfigManager &configManager_) : configManager(configManager_)
{
    std::cout << "Facade::Facade" << std::endl;
    drawer = new Drawer;
}

void Facade::setSceneInf(size_t width_, size_t height_) // not in use (deprecated)
{
    std::cout << "Facade::setSceneInf" << std::endl;
    if (scene)
        delete scene;

    scene = new SceneInf(width_, height_);
}

void Facade::setSceneInfMotherboard(ConfigManager::MotherboardType type)
{
    std::cout << "Facade::setSceneInfMotherboard" << std::endl;
    std::cout << "Configuring scene for motherboard type: " << static_cast<int>(type) << std::endl;
    size_t width = 0;
    size_t height = 0;
    size_t widthScaled = 0;
    size_t heightScaled = 0;

    switch (type)
    {
    case ConfigManager::MotherboardType::ATX:
        width = ATX_WIDTH;
        height = ATX_HEIGHT;
        widthScaled = width * SIZE_SC;
        heightScaled = height * SIZE_SC;
        if (motherboardConfig)
        {
            delete motherboardConfig;
        }
        motherboardConfig = new ATXMotherboardConfig(Dot3D(BASE_START), Dot3D(widthScaled, heightScaled, BASE_Z));
        break;
    case ConfigManager::MotherboardType::MicroATX:
        width = MICROATX_WIDTH;
        height = MICROATX_HEIGHT;
        widthScaled = width * SIZE_SC;
        heightScaled = height * SIZE_SC;
        if (motherboardConfig)
        {
            delete motherboardConfig;
        }
        motherboardConfig = new MicroATXMotherboardConfig(Dot3D(BASE_START), Dot3D(widthScaled, heightScaled, BASE_Z));
        break;
    case ConfigManager::MotherboardType::MiniITX:
        width = MINIITX_WIDTH;
        height = MINIITX_HEIGHT;
        widthScaled = width * SIZE_SC;
        heightScaled = height * SIZE_SC;
        if (motherboardConfig)
        {
            delete motherboardConfig;
        }
        motherboardConfig = new MiniITXMotherboardConfig(Dot3D(BASE_START), Dot3D(widthScaled, heightScaled, BASE_Z));
        break;
    default:
        std::cout << "Unknown motherboard type selected" << std::endl;
        return;
    }
    if (scene)
    {
        delete scene;
    }
    int index = static_cast<int>(type);
    scene = new SceneInf(width, height, index);
}

// motherboard constructor
int Facade::addCPU(ConfigManager::MotherboardType motherboardType, ConfigManager::CPUType CPUType) // TODO
{
    std::cout << "Facade::addCPU" << std::endl;
    std::cout << "--> motherboard type: " << motherboardTypeToString(motherboardType) << std::endl;
    std::cout << "--> cpu type: " << cpuTypeToString(CPUType) << std::endl;
    Dot3D motherboardOffset = motherboardConfig->getCpuSlotPosition();
    ComponentConfig cpuBlock = cpuConfig.getCPUConfig(CPUType, motherboardOffset);
    scene->addCPUBlock(cpuBlock, "CPU_BLOCK", CPUType);
    std::cout << "-->" << cpuBlock;
    return 0;
}

int Facade::addRAM(ConfigManager::MotherboardType motherboardType, ConfigManager::RAMType RAMType, int slotIndex) // TODO
{
    std::cout << "Facade::addRAM" << std::endl;
    std::cout << "--> motherboard type: " << motherboardTypeToString(motherboardType) << std::endl;
    std::cout << "--> ram type: " << ramTypeToString(RAMType) << std::endl;
    std::cout << "--> slot: " << slotIndex << std::endl;

    int splitIncrement = 0;
    switch (RAMType)
    {
    case (ConfigManager::RAMType::RAM_4GB):
        splitIncrement = 52;
        break;
    case (ConfigManager::RAMType::RAM_8GB):
        splitIncrement = 6;
        break;
    case (ConfigManager::RAMType::RAM_16GB):
        splitIncrement = 0;
        break;
    case (ConfigManager::RAMType::RAM_32GB):
        splitIncrement = 0;
        break;
    };

    ConfigManager::RAMAccessoriesType RAMAccType = configManager.mapAccessoryRAM(RAMType);

    Dot3D motherboardOffset = motherboardConfig->getRamSlotPosition(slotIndex);
    Dot3D motherboardAccOffset = motherboardConfig->getRamAccSlotPosition(slotIndex);

    ComponentConfig ramBlock = ramConfig.getRAMConfig(RAMType, motherboardOffset);
    ComponentConfig ramAccBlock = ramConfig.getRAMAccConfig(RAMAccType, motherboardAccOffset, splitIncrement);

    scene->addRAMBlock(ramBlock, "RAM_BLOCK", RAMType);
    scene->addRAMAccBlock(ramAccBlock, "RAM_ACC_BLOCK", RAMAccType);

    // std::cout << "-->" << ramBlock;
    return 0;
}

int Facade::addGPU(ConfigManager::MotherboardType motherboardType, ConfigManager::GPUType GPUType, int slotIndex) // TODO
{
    std::cout << "Facade::addGPU" << std::endl;
    std::cout << "--> motherboard type: " << motherboardTypeToString(motherboardType) << std::endl;
    std::cout << "--> gpu type: " << gpuTypeToString(GPUType) << std::endl;
    std::cout << "--> slot: " << slotIndex << std::endl;
    Dot3D motherboardOffset = motherboardConfig->getGpuSlotPosition(slotIndex);
    ComponentConfig gpuBlock = gpuConfig.getGPUConfig(GPUType, motherboardOffset);
    scene->addGPUBlock(gpuBlock, "GPU_BLOCK", GPUType);
    std::cout << "-->" << gpuBlock;
    return 0;
}

BaseMotherboardConfig *Facade::getMotherboardConfig()
{
    return motherboardConfig;
}

void Facade::changeSceneInf(size_t newWidth, size_t newheight) // not in use (deprecated)
{
    std::cout << "Facade::changeSceneInf" << std::endl;
    scene->changeSize(newWidth, newheight);
}

bool Facade::isSceneSet()
{
    return scene;
}

QGraphicsScene *Facade::drawScene(QRectF rect)
{
    std::cout << "Facade::drawScene" << std::endl;
    QGraphicsScene *retScene = nullptr;
    if (isSceneSet())
        retScene = drawer->drawScene(scene, rect);

    return retScene;
}

QGraphicsScene *Facade::moveUpScene(double value, QRectF rect)
{
    std::cout << "Facade::moveUpScene" << std::endl;
    scene->moveUp(value);

    return drawScene(rect);
}

QGraphicsScene *Facade::moveDownScene(double value, QRectF rect)
{
    std::cout << "Facade::moveDownScene" << std::endl;
    scene->moveDown(value);

    return drawScene(rect);
}

QGraphicsScene *Facade::moveRightScene(double value, QRectF rect)
{
    std::cout << "Facade::moveRightScene" << std::endl;
    scene->moveRight(value);

    return drawScene(rect);
}

QGraphicsScene *Facade::moveLeftScene(double value, QRectF rect)
{
    std::cout << "Facade::moveLeftScene" << std::endl;
    scene->moveLeft(value);

    return drawScene(rect);
}

QGraphicsScene *Facade::scaleScene(double value, QRectF rect)
{
    std::cout << "Facade::scaleScene" << std::endl;
    scene->scale(value);

    return drawScene(rect);
}

QGraphicsScene *Facade::rotateXScene(double angle, QRectF rect)
{
    std::cout << "Facade::rotateXScene" << std::endl;
    scene->rotateX(angle);

    return drawScene(rect);
}

QGraphicsScene *Facade::rotateYScene(double angle, QRectF rect)
{
    std::cout << "Facade::rotateYScene" << std::endl;
    scene->rotateY(angle);

    return drawScene(rect);
}

QGraphicsScene *Facade::rotateZScene(double angle, QRectF rect)
{
    std::cout << "Facade::rotateZScene" << std::endl;
    scene->rotateZ(angle);

    return drawScene(rect);
}

QGraphicsScene *Facade::toCenter(QRectF rect)
{
    std::cout << "Facade::toCenter" << std::endl;
    scene->toCenter();

    return drawScene(rect);
}

SceneInf *Facade::getScene()
{
    std::cout << "Facade::getScene" << std::endl;
    return scene;
}

void Facade::addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                     int x1, int y1, int z1, int x2, int y2, int z2,
                     int x3, int y3, int z3, int x4, int y4, int z4)
{
    std::cout << "Facade::addQuad" << std::endl;
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
    vec = {size - 4, size - 1, size - 2};
    facets.push_back(vec);
}

void Facade::addTriangle(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
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

void Facade::addLight(int xAngle, int yAngle)
{
    std::cout << "Facade::addLight" << std::endl;
    Eigen::Matrix4f transMat;
    double radianXAngle = (double) xAngle * M_PI / 180.0;
    double radianYAngle = (double) yAngle * M_PI / 180.0;

    transMat << 1,          0,          0,               0,
        0, cos(radianXAngle), -sin(radianXAngle), 0,
        0, sin(radianXAngle),  cos(radianXAngle), 0,
        0,           0,          0,               1;

    Eigen::Matrix4f prodMat;
    prodMat << cos(radianYAngle), 0, sin(radianYAngle), 0,
        0,                1,    0,              0,
        -sin(radianYAngle), 0, cos(radianYAngle), 0,
        0,                0,    0,              1;

    transMat *= prodMat;

    Light illum(transMat);
    illum.setAngles(xAngle, yAngle);
    scene->addLight(illum);
}


int Facade::addBrick(int xCell, int yCell, int modelLength, int modelWidth) // deprecated
{
    std::cout << "Facade::addBrick" << std::endl;
    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].back();
            }

            if (scene->getUsedCellsZ()[i][j].back() == -1.0 && scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2);
            }
        }
    }


    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "i = " << i << "j = " << j << "ячейка занята плиткой";
                    return 1;
                }
            }
        }
    }


    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;

    //стены кирпичика
    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor                        , yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor + SIZE_SC,
                xFactor                        , yFactor, zFactor + SIZE_SC);
        xFactor = xCell * SIZE_SC + 10;
        yFactor += SIZE_SC * modelWidth;
    }

    yFactor = yCell * SIZE_SC + 10;


    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor, yFactor                       , zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor + SIZE_SC,
                xFactor, yFactor                       , zFactor + SIZE_SC);
        yFactor = yCell * SIZE_SC + 10;
        xFactor += SIZE_SC * modelLength;
    }

    xFactor = xCell * SIZE_SC + 10;

    // Низ кирпичика
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            addQuad(vertices, facets,
                    xFactor          , yFactor               , zFactor,
                    xFactor + SIZE_SC, yFactor               , zFactor,
                    xFactor + SIZE_SC, yFactor + SIZE_SC, zFactor,
                    xFactor          , yFactor + SIZE_SC, zFactor);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    xFactor = xCell * SIZE_SC + 10;
    yFactor = yCell * SIZE_SC + 10;
    zFactor += SIZE_SC;

    // Верх кирпичика
    addQuad(vertices, facets,
            xFactor                        , yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor + SIZE_SC * modelWidth, zFactor,
            xFactor                        , yFactor + SIZE_SC * modelWidth, zFactor);

    // Верх кирпичика (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    PolygonModel Brick(vertices, facets, "Кирпичик");
    Brick.setUsedCell(xCell, yCell, zCell + SIZE_SC);
    Brick.setWidthModel(modelWidth);
    Brick.setLengthModel(modelLength);
    Brick.setModelType(PolygonModel::Brick);
    Brick.setModelNum(scene->getModelsNum());
    scene->addModel(Brick);

    return 0;
}


int Facade::addPlate(int xCell, int yCell, int modelLength, int modelWidth) // deprecated
{
    std::cout << "Facade::addPlate" << std::endl;
    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].back();
            }

            if (scene->getUsedCellsZ()[i][j].back() == -1.0 && scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2);
            }
        }
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;

    //стенки пластинки
    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor                        , yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor + PLATE_HEIGHT,
                xFactor                        , yFactor, zFactor + PLATE_HEIGHT);
        xFactor = xCell * SIZE_SC + 10;
        yFactor += SIZE_SC * modelWidth;
    }

    yFactor = yCell * SIZE_SC + 10;


    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor, yFactor                       , zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor + PLATE_HEIGHT,
                xFactor, yFactor                       , zFactor + PLATE_HEIGHT);
        yFactor = yCell * SIZE_SC + 10;
        xFactor += SIZE_SC * modelLength;
    }

    xFactor = xCell * SIZE_SC + 10;

    // Низ пластинки
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            addQuad(vertices, facets,
                    xFactor          , yFactor          , zFactor,
                    xFactor + SIZE_SC, yFactor          , zFactor,
                    xFactor + SIZE_SC, yFactor + SIZE_SC, zFactor,
                    xFactor          , yFactor + SIZE_SC, zFactor);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    xFactor = xCell * SIZE_SC + 10;
    yFactor = yCell * SIZE_SC + 10;
    zFactor += PLATE_HEIGHT;

    // Верх пластинки
    addQuad(vertices, facets,
            xFactor                        , yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor + SIZE_SC * modelWidth, zFactor,
            xFactor                        , yFactor + SIZE_SC * modelWidth, zFactor);

    // Верх пластинки (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    PolygonModel Plate(vertices, facets, "Пластинка");
    Plate.setUsedCell(xCell, yCell, zCell + PLATE_HEIGHT);
    Plate.setWidthModel(modelWidth);
    Plate.setLengthModel(modelLength);
    Plate.setModelType(PolygonModel::Plate);
    Plate.setModelNum(scene->getModelsNum());
    scene->addModel(Plate);

    return 0;
}


int Facade::addTile(int xCell, int yCell, int modelLength, int modelWidth) // deprecated
{
    std::cout << "Facade::addTile" << std::endl;
    xCell -= 1;
    yCell -= 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
                                                                      yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].back();
            }

            if (scene->getUsedCellsZ()[i][j].back() == -1.0 && scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2);
            }
        }
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;

    //стенки плитки
    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor                        , yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor + PLATE_HEIGHT,
                xFactor                        , yFactor, zFactor + PLATE_HEIGHT);
        xFactor = xCell * SIZE_SC + 10;
        yFactor += SIZE_SC * modelWidth;
    }

    yFactor = yCell * SIZE_SC + 10;


    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor, yFactor                       , zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor + PLATE_HEIGHT,
                xFactor, yFactor                       , zFactor + PLATE_HEIGHT);
        yFactor = yCell * SIZE_SC + 10;
        xFactor += SIZE_SC * modelLength;
    }

    xFactor = xCell * SIZE_SC + 10;

    // Низ плитки
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            addQuad(vertices, facets,
                    xFactor          , yFactor          , zFactor,
                    xFactor + SIZE_SC, yFactor          , zFactor,
                    xFactor + SIZE_SC, yFactor + SIZE_SC, zFactor,
                    xFactor          , yFactor + SIZE_SC, zFactor);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    yFactor = yCell * SIZE_SC + 10;
    xFactor = xCell * SIZE_SC + 10;
    zFactor += PLATE_HEIGHT;

    addQuad(vertices, facets,
            xFactor                        , yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor + SIZE_SC * modelWidth, zFactor,
            xFactor                        , yFactor + SIZE_SC * modelWidth, zFactor);

    PolygonModel Tile(vertices, facets, "Плитка");
    Tile.setUsedCell(xCell, yCell, zCell + PLATE_HEIGHT);
    Tile.setWidthModel(modelWidth);
    Tile.setLengthModel(modelLength);
    Tile.setModelType(PolygonModel::Tile);
    Tile.setModelNum(scene->getModelsNum());
    scene->addModel(Tile);

    return 0;
}

int Facade::addArc41(int xCell, int yCell) // deprecated
{
    std::cout << "Facade::addArc41" << std::endl;
    xCell -= 1;
    yCell -= 1;
    int modelLength = 4;
    int modelWidth = 1;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
                                                                      yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    if (scene->getUsedCellsZ()[yCell][xCell].back() > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell][xCell].back();
    }
    if (scene->getUsedCellsZ()[yCell][xCell].back() == -1.0 && scene->getUsedCellsZ()[yCell][xCell].at(scene->getUsedCellsZ()[yCell][xCell].size() - 2) > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell][xCell].at(scene->getUsedCellsZ()[yCell][xCell].size() - 2);
    }
    if (scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back() > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back();
    }
    if (scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back() == -1.0 && scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].at(scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].size() - 2) > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].at(scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].size() - 2);
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;

    //стенки арки
    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor          , yFactor, zFactor,
                xFactor + SIZE_SC, yFactor, zFactor,
                xFactor + SIZE_SC, yFactor, zFactor + SIZE_SC,
                xFactor          , yFactor, zFactor + SIZE_SC);
        addTriangle(vertices, facets,
                    xFactor + SIZE_SC      , yFactor, zFactor,
                    xFactor + SIZE_SC      , yFactor, zFactor + SIZE_SC,
                    xFactor + 1.5 * SIZE_SC, yFactor, zFactor + 0.4 * SIZE_SC);
        addQuad(vertices, facets,
                xFactor + SIZE_SC      , yFactor, zFactor + SIZE_SC,
                xFactor + 1.5 * SIZE_SC, yFactor, zFactor + 0.4 * SIZE_SC,
                xFactor + 2 * SIZE_SC  , yFactor, zFactor + 0.5 * SIZE_SC,
                xFactor + 2 * SIZE_SC  , yFactor, zFactor + SIZE_SC);
        addQuad(vertices, facets,
                xFactor + 3 * SIZE_SC  , yFactor, zFactor + SIZE_SC,
                xFactor + 2.5 * SIZE_SC, yFactor, zFactor + 0.4 * SIZE_SC,
                xFactor + 2 * SIZE_SC  , yFactor, zFactor + 0.5 * SIZE_SC,
                xFactor + 2 * SIZE_SC  , yFactor, zFactor + SIZE_SC);
        addTriangle(vertices, facets,
                    xFactor + 3 * SIZE_SC  , yFactor, zFactor,
                    xFactor + 3 * SIZE_SC  , yFactor, zFactor + SIZE_SC,
                    xFactor + 2.5 * SIZE_SC, yFactor, zFactor + 0.4 * SIZE_SC);
        addQuad(vertices, facets,
                xFactor + 4 * SIZE_SC, yFactor, zFactor,
                xFactor + 3 * SIZE_SC, yFactor, zFactor,
                xFactor + 3 * SIZE_SC, yFactor, zFactor + SIZE_SC,
                xFactor + 4 * SIZE_SC, yFactor, zFactor + SIZE_SC);
        xFactor = xCell * SIZE_SC + 10;
        yFactor += SIZE_SC * modelWidth;
    }

    yFactor = yCell * SIZE_SC + 10;

    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor, yFactor                       , zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor,
                xFactor, yFactor + SIZE_SC * modelWidth, zFactor + SIZE_SC,
                xFactor, yFactor                       , zFactor + SIZE_SC);
        xFactor += SIZE_SC * modelLength;
    }

    xFactor = xCell * SIZE_SC + 10;

    // Низ арки
    addQuad(vertices, facets,
            xFactor          , yFactor          , zFactor,
            xFactor          , yFactor + SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor          , zFactor);
    addQuad(vertices, facets,
            xFactor + 3 * SIZE_SC, yFactor          , zFactor,
            xFactor + 3 * SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor + 4 * SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor + 4 * SIZE_SC, yFactor          , zFactor);
    addQuad(vertices, facets,
            xFactor + SIZE_SC      , yFactor          , zFactor,
            xFactor + SIZE_SC      , yFactor + SIZE_SC, zFactor,
            xFactor + 1.5 * SIZE_SC, yFactor + SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + 1.5 * SIZE_SC, yFactor          , zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor + 1.5 * SIZE_SC, yFactor          , zFactor + 0.4 * SIZE_SC,
            xFactor + 1.5 * SIZE_SC, yFactor + SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + 2 * SIZE_SC  , yFactor + SIZE_SC, zFactor + 0.5 * SIZE_SC,
            xFactor + 2 * SIZE_SC  , yFactor          , zFactor + 0.5 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor + 2 * SIZE_SC  , yFactor          , zFactor + 0.5 * SIZE_SC,
            xFactor + 2 * SIZE_SC  , yFactor + SIZE_SC, zFactor + 0.5 * SIZE_SC,
            xFactor + 2.5 * SIZE_SC, yFactor + SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + 2.5 * SIZE_SC, yFactor          , zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor + 3 * SIZE_SC  , yFactor          , zFactor,
            xFactor + 3 * SIZE_SC  , yFactor + SIZE_SC, zFactor,
            xFactor + 2.5 * SIZE_SC, yFactor + SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + 2.5 * SIZE_SC, yFactor          , zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor + 4 * SIZE_SC, yFactor          , zFactor,
            xFactor + 4 * SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor + 3 * SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor + 3 * SIZE_SC, yFactor          , zFactor);

    yFactor = yCell * SIZE_SC + 10;
    xFactor = xCell * SIZE_SC + 10;
    zFactor += SIZE_SC;

    // верх
    addQuad(vertices, facets,
            xFactor                        , yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor + SIZE_SC * modelWidth, zFactor,
            xFactor                        , yFactor + SIZE_SC * modelWidth, zFactor);

    // Верх арки (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }


    PolygonModel Arc(vertices, facets, "Арка (4x1)");
    Arc.setUsedCell(xCell, yCell, zCell + SIZE_SC);
    Arc.setWidthModel(modelWidth);
    Arc.setLengthModel(modelLength);
    Arc.setModelType(PolygonModel::Arc41);
    Arc.setModelNum(scene->getModelsNum());
    scene->addModel(Arc);

    return 0;
}

int Facade::addArc14(int xCell, int yCell) // deprecated
{
    std::cout << "Facade::addArc14" << std::endl;
    xCell -= 1;
    yCell -= 1;
    int modelLength = 1;
    int modelWidth = 4;

    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
                                                                      yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    if (scene->getUsedCellsZ()[yCell][xCell].back() > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell][xCell].back();
    }
    if (scene->getUsedCellsZ()[yCell][xCell].back() == -1.0 && scene->getUsedCellsZ()[yCell][xCell].at(scene->getUsedCellsZ()[yCell][xCell].size() - 2) > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell][xCell].at(scene->getUsedCellsZ()[yCell][xCell].size() - 2);
    }
    if (scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back() > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back();
    }
    if (scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].back() == -1.0 && scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].at(scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].size() - 2) > zCell)
    {
        zCell = scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].at(scene->getUsedCellsZ()[yCell + modelWidth - 1][xCell + modelLength - 1].size() - 2);
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;

    //стенки арки
    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor                        , yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor,
                xFactor + SIZE_SC * modelLength, yFactor, zFactor + SIZE_SC,
                xFactor                        , yFactor, zFactor + SIZE_SC);
        yFactor += SIZE_SC * modelWidth;
    }

    yFactor = yCell * SIZE_SC + 10;

    for (int k = 0; k < 2; k++)
    {
        addQuad(vertices, facets,
                xFactor, yFactor          , zFactor,
                xFactor, yFactor + SIZE_SC, zFactor,
                xFactor, yFactor + SIZE_SC, zFactor + SIZE_SC,
                xFactor, yFactor          , zFactor + SIZE_SC);
        addTriangle(vertices, facets,
                    xFactor, yFactor + SIZE_SC      , zFactor,
                    xFactor, yFactor + SIZE_SC      , zFactor + SIZE_SC,
                    xFactor, yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC);
        addQuad(vertices, facets,
                xFactor, yFactor + SIZE_SC      , zFactor + SIZE_SC,
                xFactor, yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
                xFactor, yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC,
                xFactor, yFactor + 2 * SIZE_SC  , zFactor + SIZE_SC);
        addQuad(vertices, facets,
                xFactor, yFactor + 3 * SIZE_SC  , zFactor + SIZE_SC,
                xFactor, yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
                xFactor, yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC,
                xFactor, yFactor + 2 * SIZE_SC  , zFactor + SIZE_SC);
        addTriangle(vertices, facets,
                    xFactor, yFactor + 3 * SIZE_SC  , zFactor,
                    xFactor, yFactor + 3 * SIZE_SC  , zFactor + SIZE_SC,
                    xFactor, yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC);
        addQuad(vertices, facets,
                xFactor, yFactor + 4 * SIZE_SC, zFactor,
                xFactor, yFactor + 3 * SIZE_SC, zFactor,
                xFactor, yFactor + 3 * SIZE_SC, zFactor + SIZE_SC,
                xFactor, yFactor + 4 * SIZE_SC, zFactor + SIZE_SC);
        xFactor += SIZE_SC * modelLength;
    }

    xFactor = xCell * SIZE_SC + 10;

    // Низ арки
    addQuad(vertices, facets,
            xFactor          , yFactor          , zFactor,
            xFactor + SIZE_SC, yFactor          , zFactor,
            xFactor + SIZE_SC, yFactor + SIZE_SC, zFactor,
            xFactor          , yFactor + SIZE_SC, zFactor);
    addQuad(vertices, facets,
            xFactor          , yFactor + 3 * SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor + 3 * SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor + 4 * SIZE_SC, zFactor,
            xFactor          , yFactor + 4 * SIZE_SC, zFactor);
    addQuad(vertices, facets,
            xFactor          , yFactor + SIZE_SC      , zFactor,
            xFactor + SIZE_SC, yFactor + SIZE_SC      , zFactor,
            xFactor + SIZE_SC, yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor          , yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor          , yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + SIZE_SC, yFactor + 1.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor + SIZE_SC, yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC,
            xFactor          , yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor          , yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC,
            xFactor + SIZE_SC, yFactor + 2 * SIZE_SC  , zFactor + 0.5 * SIZE_SC,
            xFactor + SIZE_SC, yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor          , yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor          , yFactor + 3 * SIZE_SC  , zFactor,
            xFactor + SIZE_SC, yFactor + 3 * SIZE_SC  , zFactor,
            xFactor + SIZE_SC, yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC,
            xFactor          , yFactor + 2.5 * SIZE_SC, zFactor + 0.4 * SIZE_SC);
    addQuad(vertices, facets,
            xFactor          , yFactor + 4 * SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor + 4 * SIZE_SC, zFactor,
            xFactor + SIZE_SC, yFactor + 4 * SIZE_SC, zFactor,
            xFactor          , yFactor + 4 * SIZE_SC, zFactor);

    zFactor += SIZE_SC;

    // верх
    addQuad(vertices, facets,
            xFactor                        , yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor                       , zFactor,
            xFactor + SIZE_SC * modelLength, yFactor + SIZE_SC * modelWidth, zFactor,
            xFactor                        , yFactor + SIZE_SC * modelWidth, zFactor);

    // Верх арки (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    PolygonModel Arc(vertices, facets, "Арка (1x4)");
    Arc.setUsedCell(xCell, yCell, zCell + SIZE_SC);
    Arc.setWidthModel(modelWidth);
    Arc.setLengthModel(modelLength);
    Arc.setModelType(PolygonModel::Arc14);
    Arc.setModelNum(scene->getModelsNum());
    scene->addModel(Arc);

    return 0;
}



int Facade::addCylinder1(int xCell, int yCell) // deprecated
{
    std::cout << "Facade::addCylinder1" << std::endl;
    xCell -= 1;
    yCell -= 1;
    double Radius = 0.5;
    int modelWidth = 1;
    int modelLength = 1;
    int polygons_num = 24;
    Radius *= SIZE_SC;


    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
                                                                      yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].back();
            }

            if (scene->getUsedCellsZ()[i][j].back() == -1.0 && scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2);
            }
        }
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }


    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;
    double rad, next_rad;
    int xr, yr, xr_n, yr_n;

    //стены цилиндра
    int step = 360 / polygons_num;
    for (int i = 0; i < 360 - step; i += step)
    {
        rad = i * PI / 180;
        next_rad = (i + step) * PI / 180;
        xr = Radius * (cos(rad) + 1);
        yr = Radius * (sin(rad) + 1);
        xr_n = Radius * (cos(next_rad) + 1);
        yr_n = Radius * (sin(next_rad) + 1);

        // стенка
        addQuad(vertices, facets,
                xFactor + xr  , yFactor + yr  , zFactor,
                xFactor + xr  , yFactor + yr  , zFactor + SIZE_SC,
                xFactor + xr_n, yFactor + yr_n, zFactor + SIZE_SC,
                xFactor + xr_n, yFactor + yr_n, zFactor);
        //верх
        addTriangle(vertices, facets,
                    xFactor + Radius, yFactor + Radius, zFactor + SIZE_SC,
                    xFactor + xr    , yFactor + yr    , zFactor + SIZE_SC,
                    xFactor + xr_n  , yFactor + yr_n  , zFactor + SIZE_SC);
        //низ
        addTriangle(vertices, facets,
                    xFactor + Radius, yFactor + Radius, zFactor,
                    xFactor + xr    , yFactor + yr    , zFactor,
                    xFactor + xr_n  , yFactor + yr_n  , zFactor);

        // последняя стенка, низ и верх
        if (i == 360 - 2 * step)
        {
            xr = Radius * (cos(next_rad) + 1);
            yr = Radius * (sin(next_rad) + 1);
            xr_n = Radius * (cos(0) + 1);
            yr_n = Radius * (sin(0) + 1);
            addQuad(vertices, facets,
                    xFactor + xr  , yFactor + yr  , zFactor,
                    xFactor + xr  , yFactor + yr  , zFactor + SIZE_SC,
                    xFactor + xr_n, yFactor + yr_n, zFactor + SIZE_SC,
                    xFactor + xr_n, yFactor + yr_n, zFactor);

            addTriangle(vertices, facets,
                        xFactor + Radius, yFactor + Radius, zFactor + SIZE_SC,
                        xFactor + xr    , yFactor + yr    , zFactor + SIZE_SC,
                        xFactor + xr_n  , yFactor + yr_n  , zFactor + SIZE_SC);

            addTriangle(vertices, facets,
                        xFactor + Radius, yFactor + Radius, zFactor,
                        xFactor + xr    , yFactor + yr    , zFactor,
                        xFactor + xr_n  , yFactor + yr_n  , zFactor);
        }
    }

    zFactor += SIZE_SC;

    // Верх цилиндра (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    PolygonModel Cylinder(vertices, facets, "Цилиндр (1x1)");
    Cylinder.setUsedCell(xCell, yCell, zCell + SIZE_SC);
    Cylinder.setWidthModel(modelWidth);
    Cylinder.setLengthModel(modelLength);
    Cylinder.setModelType(PolygonModel::Cylinder1);
    Cylinder.setModelNum(scene->getModelsNum());
    scene->addModel(Cylinder);

    return 0;
}

int Facade::addCylinder2(int xCell, int yCell)
{
    std::cout << "Facade::addCylinder2" << std::endl;
    xCell -= 1;
    yCell -= 1;
    double Radius = 1;
    int modelWidth = 2;
    int modelLength = 2;
    int polygons_num = 24;
    Radius *= SIZE_SC;


    if (xCell + modelLength - 1 >= (int) scene->getWidth() || \
                                                                      yCell + modelWidth - 1 >= (int) scene->getHeight())
        return 2;

    double zCell = 0;
    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].back();
            }

            if (scene->getUsedCellsZ()[i][j].back() == -1.0 && scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) > zCell)
            {
                zCell = scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2);
            }
        }
    }

    for (int i = yCell; i < yCell + modelWidth; i++)
    {
        for (int j = xCell; j < xCell + modelLength; j++)
        {
            if (scene->getUsedCellsZ()[i][j].back() == -1.0)
            {
                if (scene->getUsedCellsZ()[i][j].at(scene->getUsedCellsZ()[i][j].size() - 2) == zCell)
                {
                    qDebug() << "На ячейке " << i << ", " << j << "стоит плитка";
                    return 1;
                }
            }
        }
    }

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    int xFactor = xCell * SIZE_SC + 10;
    int yFactor = yCell * SIZE_SC + 10;
    int zFactor = BASE_Z + zCell;
    double rad, next_rad;
    int xr, yr, xr_n, yr_n;

    //стены цилиндра
    int step = 360 / polygons_num;
    for (int i = 0; i < 360 - step; i += step)
    {
        rad = i * PI / 180;
        next_rad = (i + step) * PI / 180;
        xr = Radius * (cos(rad) + 1);
        yr = Radius * (sin(rad) + 1);
        xr_n = Radius * (cos(next_rad) + 1);
        yr_n = Radius * (sin(next_rad) + 1);

        // стенка
        addQuad(vertices, facets,
                xFactor + xr  , yFactor + yr  , zFactor,
                xFactor + xr  , yFactor + yr  , zFactor + SIZE_SC,
                xFactor + xr_n, yFactor + yr_n, zFactor + SIZE_SC,
                xFactor + xr_n, yFactor + yr_n, zFactor);
        //верх
        addTriangle(vertices, facets,
                    xFactor + Radius, yFactor + Radius, zFactor + SIZE_SC,
                    xFactor + xr    , yFactor + yr    , zFactor + SIZE_SC,
                    xFactor + xr_n  , yFactor + yr_n  , zFactor + SIZE_SC);
        //низ
        addTriangle(vertices, facets,
                    xFactor + Radius, yFactor + Radius, zFactor,
                    xFactor + xr    , yFactor + yr    , zFactor,
                    xFactor + xr_n  , yFactor + yr_n  , zFactor);

        // последняя стенка, низ и верх
        if (i == 360 - 2 * step)
        {
            xr = Radius * (cos(next_rad) + 1);
            yr = Radius * (sin(next_rad) + 1);
            xr_n = Radius * (cos(0) + 1);
            yr_n = Radius * (sin(0) + 1);
            addQuad(vertices, facets,
                    xFactor + xr  , yFactor + yr  , zFactor,
                    xFactor + xr  , yFactor + yr  , zFactor + SIZE_SC,
                    xFactor + xr_n, yFactor + yr_n, zFactor + SIZE_SC,
                    xFactor + xr_n, yFactor + yr_n, zFactor);

            addTriangle(vertices, facets,
                        xFactor + Radius, yFactor + Radius, zFactor + SIZE_SC,
                        xFactor + xr    , yFactor + yr    , zFactor + SIZE_SC,
                        xFactor + xr_n  , yFactor + yr_n  , zFactor + SIZE_SC);

            addTriangle(vertices, facets,
                        xFactor + Radius, yFactor + Radius, zFactor,
                        xFactor + xr    , yFactor + yr    , zFactor,
                        xFactor + xr_n  , yFactor + yr_n  , zFactor);
        }
    }

    zFactor += SIZE_SC;

    // Верх цилиндра (крепежи)
    for (int i = 0; i < modelLength; i++)
    {
        yFactor = yCell * SIZE_SC + 10;

        for (int j = 0; j < modelWidth; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor,
                        xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC, zFactor + BRICK_TOP_HEIGHT);

                yFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            yFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);

            // крышечка
            addQuad(vertices, facets,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT,
                    xFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

            for (int k = 0; k < 2; k++)
            {
                addQuad(vertices, facets,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * (1 - BRICK_TOP_SIZE_SC), zFactor + BRICK_TOP_HEIGHT,
                        xFactor + SIZE_SC * BRICK_TOP_SIZE_SC, yFactor + SIZE_SC * BRICK_TOP_SIZE_SC      , zFactor + BRICK_TOP_HEIGHT);

                xFactor += SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            }

            xFactor -= 2 * SIZE_SC * (1 - 2 * BRICK_TOP_SIZE_SC);
            yFactor += SIZE_SC;
        }
        xFactor += SIZE_SC;
    }

    PolygonModel Cylinder(vertices, facets, "Цилиндр (2x2)");
    Cylinder.setUsedCell(xCell, yCell, zCell + SIZE_SC);
    Cylinder.setWidthModel(modelWidth);
    Cylinder.setLengthModel(modelLength);
    Cylinder.setModelType(PolygonModel::Cylinder2);
    Cylinder.setModelNum(scene->getModelsNum());
    scene->addModel(Cylinder);

    return 0;
}
