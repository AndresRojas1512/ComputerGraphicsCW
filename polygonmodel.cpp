#include "polygonmodel.hpp"

const std::vector<Vertex> PolygonModel::getVertices() { return vertices; }

const std::vector<Facet> PolygonModel::getFacets() { return facets; }

QString PolygonModel::getName()
{
    std::cout << "PolygonModel::getName" << std::endl;
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

