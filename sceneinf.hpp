#ifndef OBJS_HPP
#define OBJS_HPP

#include "mathelems.hpp"
#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"
#include "vertex.hpp"
#include "facet.hpp"
#include "polygonmodel.hpp"
#include "light.hpp"
#include "placeobjects.hpp"

class SceneInf
{
public:
    SceneInf();
    SceneInf(size_t width_, size_t height_);

    operator bool() const;

    size_t getWidth();
    size_t getHeight();

    void buildBaseModel(Dot3D startOfPlate_, Dot3D endOfPlate_);
    PolygonModel &getBaseModel();

    void changeSize(size_t newWidth, size_t newHeight);

    void moveUp(double value);
    void moveDown(double value);
    void moveLeft(double value);
    void moveRight(double value);

    void scale(double value);

    void rotateX(double angle);
    void rotateY(double angle);
    void rotateZ(double angle);

    void toCenter();

    size_t getModelsNum();
    PolygonModel &getModel(size_t num);
    void setModel(size_t num, PolygonModel &newModel);
    void addModel(PolygonModel &model);
    void deleteModel(size_t num);

    size_t getLightNum();
    Light &getLight(size_t num);
    void setLight(Light &light, size_t i);
    void addLight(Light &light);
    void deleteLight(size_t num);

    Eigen::Matrix4f &getTransMatrix();
    void multToTrans(Eigen::Matrix4f &newTrans);

    std::vector<std::vector<std::vector<double>>> &getUsedCellsZ();
    void initUsedCellsZ();

    void markUsedCellsZ(size_t num);
    void clearUsedCellsZ(size_t num);
    void printUsedCellsZ();

private:
    void addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                 int x1, int y1, int z1,
                 int x2, int y2, int z2,
                 int x3, int y3, int z3,
                 int x4, int y4, int z4);

    void addCube(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                           double x, double y, double z, double width, double height, double depth);

    size_t width, height;

    PolygonModel *plateModel = nullptr;

    Eigen::Matrix4f transMatrix;

    size_t modelsNum = 0;
    std::vector<PolygonModel> models;

    size_t lightNum = 0;
    std::vector<Light> Lights;

    Dot3D centerDot;

    std::vector<std::vector<std::vector<double>>> usedCellsZ;

};

#endif
