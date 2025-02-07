#include "polygonmodel.hpp"

const std::vector<Vertex> PolygonModel::getVertices() { return vertices; }

const std::vector<Facet> PolygonModel::getFacets() { return facets; }

QString PolygonModel::getName()
{
    return modelName;
}

void PolygonModel::setName(QString modelName_)
{
    std::cout << "PolygonModel::setName" << std::endl;
    modelName = modelName_;
}

void PolygonModel::setLengthModel(int lengthModel_)
{
    std::cout << "PolygonModel::setLengthModel" << std::endl;
    lengthModel = lengthModel_;
}

int  PolygonModel::getLengthModel()
{
    std::cout << "PolygonModel::getLengthModel" << std::endl;
    return lengthModel;
}

void PolygonModel::setWidthModel(int widthModel_) { widthModel = widthModel_; }

int  PolygonModel::getWidthModel() { return widthModel; }

void PolygonModel::setModelNum(size_t modelNum_) { modelNum = modelNum_; }

size_t PolygonModel::getModelNum() { return modelNum; }

void PolygonModel::setUsedCell(int xCell_, int yCell_, double zCell_)
{
    xCell = xCell_;
    yCell = yCell_;
    zCell = zCell_;
}
int PolygonModel::getUsedXCell() { return xCell; }

int PolygonModel::getUsedYCell() { return yCell; }

int PolygonModel::getUsedZCell() { return zCell; }

void PolygonModel::setModelType(model_t modelType_) { modelType = modelType_; }

PolygonModel::model_t PolygonModel::getModelType()
{
    return modelType;
}

void PolygonModel::setSlot(int slotIndex)
{
    slot = slotIndex;
}

int PolygonModel::getSlot() const
{
    return slot;
}

std::ostream &operator<<(std::ostream &os, const PolygonModel &model)
{
    os << "Model name: " << model.modelName.toStdString() << std::endl
       << "Model Type: " << model.modelType << std::endl
       << "Model index: " << model.modelNum << std::endl
       << "Number of vertices: " << model.vertices.size() << std::endl
       << "Number of facets: " << model.facets.size() << std::endl;
    return os;
}

PolygonModel::model_t parseRAMModel(ConfigManager::RAMType RAMType)
{
    switch(RAMType)
    {
    case ConfigManager::RAMType::RAM_4GB:
        return PolygonModel::model_t::RAM_4GB_BLOCK;
    case ConfigManager::RAMType::RAM_8GB:
        return PolygonModel::model_t::RAM_8GB_BLOCK;
    case ConfigManager::RAMType::RAM_16GB:
        return PolygonModel::model_t::RAM_16GB_BLOCK;
    case ConfigManager::RAMType::RAM_32GB:
        return PolygonModel::model_t::RAM_32GB_BLOCK;
    }
}

PolygonModel::model_t parseRAMAccModel(ConfigManager::RAMAccessoriesType RAMAccType)
{
    switch(RAMAccType)
    {
    case ConfigManager::RAMAccessoriesType::RAM_4GB_ACC:
        return PolygonModel::model_t::RAM_4GB_ACC_BLOCK;
    case ConfigManager::RAMAccessoriesType::RAM_8GB_ACC:
        return PolygonModel::model_t::RAM_8GB_ACC_BLOCK;
    case ConfigManager::RAMAccessoriesType::RAM_16GB_ACC:
        return PolygonModel::model_t::RAM_16GB_ACC_BLOCK;
    case ConfigManager::RAMAccessoriesType::RAM_32GB_ACC:
        return PolygonModel::model_t::RAM_32GB_ACC_BLOCK;
    }
}

PolygonModel::model_t parseGPUModel(ConfigManager::GPUType GPUType)
{
    switch(GPUType)
    {
    case ConfigManager::GPUType::GPU_4GB:
        return PolygonModel::model_t::GPU_4GB_BLOCK;
    case ConfigManager::GPUType::GPU_6GB:
        return PolygonModel::model_t::GPU_6GB_BLOCK;
    case ConfigManager::GPUType::GPU_8GB:
        return PolygonModel::model_t::GPU_8GB_BLOCK;
    case ConfigManager::GPUType::GPU_16GB:
        return PolygonModel::model_t::GPU_16GB_BLOCK;
    }
}

PolygonModel::model_t parseGPUAccModel(ConfigManager::GPUAccessoriesType GPUAccType)
{
    switch(GPUAccType)
    {
    case ConfigManager::GPUAccessoriesType::GPU_4GB_ACC:
        return PolygonModel::model_t::GPU_4GB_ACC_BLOCK;
    case ConfigManager::GPUAccessoriesType::GPU_6GB_ACC:
        return PolygonModel::model_t::GPU_6GB_ACC_BLOCK;
    case ConfigManager::GPUAccessoriesType::GPU_8GB_ACC:
        return PolygonModel::model_t::GPU_8GB_ACC_BLOCK;
    case ConfigManager::GPUAccessoriesType::GPU_16GB_ACC:
        return PolygonModel::model_t::GPU_16GB_ACC_BLOCK;
    }
}

PolygonModel::model_t parseCPUModel(ConfigManager::CPUType CPUType)
{
    switch(CPUType)
    {
    case ConfigManager::CPUType::Intel:
        return PolygonModel::model_t::Intel_CPU;
    case ConfigManager::CPUType::AMD:
        return PolygonModel::model_t::AMD_CPU;
    }
}

PolygonModel::model_t parseCPUAccModel(ConfigManager::CPUAccessoriesType CPUAccType)
{
    switch(CPUAccType)
    {
    case ConfigManager::CPUAccessoriesType::Intel_ACC:
        return PolygonModel::model_t::Intel_ACC_CPU;
    case ConfigManager::CPUAccessoriesType::AMD_ACC:
        return PolygonModel::model_t::AMD_ACC_CPU;
    }
}

std::string mapModelName(PolygonModel::model_t type)
{
    switch (type)
    {
    // RAM MAPPINGS
    case (PolygonModel::RAM_4GB_BLOCK):
        return "RAM 4GB";
    case (PolygonModel::RAM_8GB_BLOCK):
        return "RAM 8GB";
    case (PolygonModel::RAM_16GB_BLOCK):
        return "RAM 16GB";
    case (PolygonModel::RAM_32GB_BLOCK):
        return "RAM 32GB";
    // GPU MAPPINGS
    case (PolygonModel::GPU_4GB_BLOCK):
        return "GPU 4GB";
    case (PolygonModel::GPU_6GB_BLOCK):
        return "GPU 6GB";
    case (PolygonModel::GPU_8GB_BLOCK):
        return "GPU 8GB";
    case (PolygonModel::GPU_16GB_BLOCK):
        return "GPU 16GB";
    // CPU MAPPINGS
    case (PolygonModel::Intel_CPU):
        return "Intel CPU";
    case (PolygonModel::AMD_CPU):
        return "AMD CPU";
    };
}

std::string mapAccessoryName(PolygonModel::model_t type)
{
    switch (type)
    {
    // RAM MAPPINGS
    case (PolygonModel::RAM_4GB_ACC_BLOCK):
        return "RAM ACCESSORY 4GB";
    case (PolygonModel::RAM_8GB_ACC_BLOCK):
        return "RAM ACCESSORY 8GB";
    case (PolygonModel::RAM_16GB_ACC_BLOCK):
        return "RAM ACCESSORY 16GB";
    case (PolygonModel::RAM_32GB_ACC_BLOCK):
        return "RAM ACCESSORY 32GB";
    // GPU MAPPINGS
    case (PolygonModel::GPU_4GB_ACC_BLOCK):
        return "GPU ACCESSORY 4GB";
    case (PolygonModel::GPU_6GB_ACC_BLOCK):
        return "GPU ACCESSORY 6GB";
    case (PolygonModel::GPU_8GB_ACC_BLOCK):
        return "GPU ACCESSORY 8GB";
    case (PolygonModel::GPU_16GB_ACC_BLOCK):
        return "GPU ACCESSORY 16GB";
    // CPU MAPPINGS
    case (PolygonModel::Intel_ACC_CPU):
        return "Intel ACCESSORY CPU";
    case (PolygonModel::AMD_ACC_CPU):
        return "AMD ACCESSORY CPU";
    };
}

PolygonModel::model_t mapModelAccessory(PolygonModel::model_t model)
{
    switch (model)
    {
    // CPU MAPPINGS
    case (PolygonModel::model_t::Intel_CPU):
        return PolygonModel::model_t::Intel_ACC_CPU;
    case (PolygonModel::model_t::AMD_CPU):
        return PolygonModel::model_t::AMD_ACC_CPU;
    // RAM MAPPINGS
    case (PolygonModel::model_t::RAM_4GB_BLOCK):
        return PolygonModel::model_t::RAM_4GB_ACC_BLOCK;
    case (PolygonModel::model_t::RAM_8GB_BLOCK):
        return PolygonModel::model_t::RAM_8GB_ACC_BLOCK;
    case (PolygonModel::model_t::RAM_16GB_BLOCK):
        return PolygonModel::model_t::RAM_16GB_ACC_BLOCK;
    case (PolygonModel::model_t::RAM_32GB_BLOCK):
        return PolygonModel::model_t::RAM_32GB_ACC_BLOCK;
    // GPU MAPPINGS
    case (PolygonModel::model_t::GPU_4GB_BLOCK):
        return PolygonModel::model_t::GPU_4GB_ACC_BLOCK;
    case (PolygonModel::model_t::GPU_6GB_BLOCK):
        return PolygonModel::model_t::GPU_6GB_ACC_BLOCK;
    case (PolygonModel::model_t::GPU_8GB_BLOCK):
        return PolygonModel::model_t::GPU_8GB_ACC_BLOCK;
    case (PolygonModel::model_t::GPU_16GB_BLOCK):
        return PolygonModel::model_t::GPU_16GB_ACC_BLOCK;
    };
}

bool isRamModel(PolygonModel::model_t modelType)
{
    switch (modelType)
    {
    case PolygonModel::RAM_4GB_BLOCK:
        return true;
    case PolygonModel::RAM_8GB_BLOCK:
        return true;
    case PolygonModel::RAM_16GB_BLOCK:
        return true;
    case PolygonModel::RAM_32GB_BLOCK:
        return true;
    }
    return false;
}

bool isGpuModel(PolygonModel::model_t modelType)
{
    switch (modelType)
    {
    case PolygonModel::GPU_4GB_BLOCK:
        return true;
    case PolygonModel::GPU_6GB_BLOCK:
        return true;
    case PolygonModel::GPU_8GB_BLOCK:
        return true;
    case PolygonModel::GPU_16GB_BLOCK:
        return true;
    }
    return false;
}
