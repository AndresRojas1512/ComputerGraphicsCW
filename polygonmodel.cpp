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
    std::cout << "PolygonModel::getModelType" << std::endl;
    return modelType;
}
