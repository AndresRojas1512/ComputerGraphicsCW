#ifndef POLYGONMODEL_H
#define POLYGONMODEL_H

#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"
#include "vertex.hpp"
#include "facet.hpp"
#include "mathelems.hpp"
#include "placeobjects.hpp"

class PolygonModel
{
public:
    PolygonModel()
    {
        std::cout << "PolygonModel::PolygonModel(default)" << std::endl;
    }
    PolygonModel(std::vector<Vertex> vertices_, std::vector<Facet> facets_)
        : vertices(vertices_), facets(facets_)
    {
        std::cout << "PolygonModel::PolygonModel(vertices, facets)" << std::endl;
    }

    PolygonModel(std::vector<Vertex> vertices_, std::vector<Facet> facets_, QString name_)
        : vertices(vertices_), facets(facets_), modelName(name_)
    {
        std::cout << "PolygonModel::PolygonModel(vertices, facets, name)" << std::endl;
    }

    ~PolygonModel() {}

    const std::vector<Vertex> getVertices();
    //    void setVertices(std::vector<Vertex> &vertices_);
    const std::vector<Facet> getFacets();
    //    void setFacets(std::vector<Facet> facets_);

    //    void moveTo(int newXCell, int newYCell);
    //    void rotateZ(int angle);

    void setUsedCell(int xCell_, int yCell_, double zCell_);
    int getUsedXCell();
    int getUsedYCell();
    int getUsedZCell();

    void setLengthModel(int widthModel_);
    int  getLengthModel();
    void setWidthModel(int heightModel_);
    int  getWidthModel();

    void setModelNum(size_t modelNum_);
    size_t getModelNum();

    QString getName();
    void setName(QString modelName_);

    enum model_t
    {
        Brick,
        Plate,
        Tile,
        Arc41,
        Arc14,
        Cylinder1,
        Cylinder2
    };

    void setModelType(model_t modelType_);
    model_t getModelType();

private:
    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    QString modelName;

    int xCell, yCell;
    double zCell;
    int lengthModel, widthModel;

    size_t modelNum;
    model_t modelType;
};

#endif // POLYGONMODEL_H
