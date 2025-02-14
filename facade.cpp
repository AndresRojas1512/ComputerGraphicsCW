#include "facade.hpp"

Facade::Facade(ConfigManager &configManager_) : configManager(configManager_)
{
    std::cout << "Facade::Facade" << std::endl;
    drawer = new SceneDrawer;
}

void Facade::setSceneInfMotherboard(ConfigManager::MotherboardType type)
{
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

int Facade::addCPU(ConfigManager::MotherboardType motherboardType, ConfigManager::CPUType CPUType)
{
    int splitIncrement = 0;
    ConfigManager::CPUAccessoriesType CPUAccType = configManager.mapAccessoryCPU(CPUType);

    Dot3D motherboardOffset = motherboardConfig->getCpuSlotPosition();
    Dot3D motherboardAccOffset = motherboardConfig->getCpuAccSlotPosition();

    ComponentConfig cpuBlock = cpuConfig.getCPUConfig(CPUType, motherboardOffset);
    ComponentConfig cpuAccBlock = cpuConfig.getCPUAccConfig(CPUAccType, motherboardAccOffset, splitIncrement);

    PolygonModel::model_t cpuPolygonModelType = parseCPUModel(CPUType);
    PolygonModel::model_t cpuAccPolygonModelType = parseCPUAccModel(CPUAccType);

    QString cpuName = QString::fromStdString(mapModelName(cpuPolygonModelType));
    QString cpuAccName = QString::fromStdString(mapAccessoryName(cpuAccPolygonModelType));

    scene->addCPUBlock(cpuBlock, cpuName, CPUType);
    scene->addCPUAccBlock(cpuAccBlock, cpuAccName, CPUAccType);

    return 0;
}

int Facade::addRAM(ConfigManager::MotherboardType motherboardType, ConfigManager::RAMType RAMType, int slotIndex)
{
    int splitIncrement = 0;
    switch (RAMType)
    {
    case (ConfigManager::RAMType::RAM_4GB):
        splitIncrement = 67;
        break;
    case (ConfigManager::RAMType::RAM_8GB):
        splitIncrement = 6;
        break;
    case (ConfigManager::RAMType::RAM_16GB):
        splitIncrement = 20;
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

    PolygonModel::model_t ramPolygonModelType = parseRAMModel(RAMType);
    PolygonModel::model_t ramAccPolygonModelType = parseRAMAccModel(RAMAccType);

    QString ramName = QString::fromStdString(mapModelName(ramPolygonModelType));
    QString ramAccName = QString::fromStdString(mapAccessoryName(ramAccPolygonModelType));

    scene->addRAMBlock(ramBlock, ramName, RAMType, slotIndex);
    scene->addRAMAccBlock(ramAccBlock, ramAccName, RAMAccType, slotIndex);

    return 0;
}

int Facade::addGPU(ConfigManager::MotherboardType motherboardType, ConfigManager::GPUType GPUType, int slotIndex)
{
    int splitIncrement = 0;
    switch (GPUType)
    {
    case (ConfigManager::GPUType::GPU_4GB):
        splitIncrement = 70;
        break;
    case (ConfigManager::GPUType::GPU_6GB):
        splitIncrement = 50;
        break;
    case (ConfigManager::GPUType::GPU_8GB):
        splitIncrement = 50;
        break;
    case (ConfigManager::GPUType::GPU_16GB):
        splitIncrement = 50;
        break;
    }

    ConfigManager::GPUAccessoriesType GPUAccType = configManager.mapAccessoryGPU(GPUType);

    Dot3D motherboardOffset = motherboardConfig->getGpuSlotPosition(slotIndex);
    Dot3D motherboardAccOffset = motherboardConfig->getGPuAccSlotPosition(slotIndex);

    ComponentConfig gpuBlock = gpuConfig.getGPUConfig(GPUType, motherboardOffset);
    ComponentConfig gpuAccBlock = gpuConfig.getGPUAccConfig(GPUAccType, motherboardAccOffset, splitIncrement);

    PolygonModel::model_t gpuPolygonModelType = parseGPUModel(GPUType);
    PolygonModel::model_t gpuAccPolygonModelType = parseGPUAccModel(GPUAccType);

    QString gpuName = QString::fromStdString(mapModelName(gpuPolygonModelType));
    QString gpuAccName = QString::fromStdString(mapAccessoryName(gpuAccPolygonModelType));

    scene->addGPUBlock(gpuBlock, gpuName, GPUType, slotIndex);
    scene->addGPUAccBlock(gpuAccBlock, gpuAccName, GPUAccType, slotIndex);

    return 0;
}

void Facade::changeCPUColor(QColor color, QColor shadow)
{
    Color blockColor(color.red(), color.green(), color.blue());
    Color shadowColor(shadow.red(), shadow.green(), shadow.blue());
    cpuColor = blockColor;
    cpuShadow = shadowColor;

}

void Facade::changeRAMColor(QColor color, QColor shadow)
{
    Color blockColor(color.red(), color.green(), color.blue());
    Color shadowColor(shadow.red(), shadow.green(), shadow.blue());
    ramColor = blockColor;
    ramShadow = shadowColor;
}

void Facade::changeGPUColor(QColor color, QColor shadow)
{
    Color blockColor(color.red(), color.green(), color.blue());
    Color shadowColor(shadow.red(), shadow.green(), shadow.blue());
    gpuColor = blockColor;
    gpuShadow = shadowColor;
}

BaseMotherboardConfig *Facade::getMotherboardConfig()
{
    return motherboardConfig;
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
        retScene = drawer->drawScene(scene, rect, cpuColor, cpuShadow, ramColor, ramShadow, gpuColor, gpuShadow);

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
    if (!lightSet)
    {
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
        lightSet = true;
    }
}

bool Facade::isLightSet(void)
{
    return lightSet;
}

void Facade::removeLight(void)
{
    lightSet = false;
}
