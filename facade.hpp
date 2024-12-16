#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include "sceneinf.hpp"
#include "drawer.hpp"
#include <QGraphicsScene>
#include "placeobjects.hpp"
#include "QDebug"
#include "QPen"
#include <limits>
#include "math.h"
#include "config.hpp"

class Facade
{
public:
    Facade();

    void setSceneInf(size_t width_, size_t height_);
    void changeSceneInf(size_t newWidth, size_t newheight);
    bool isSceneSet();

    QGraphicsScene *drawScene(QRectF rect);

    int addBrick(int xCell, int yCell, int modelLength, int modelWidth);
    int addPlate(int xCell, int yCell, int modelLength, int modelWidth);
    int addTile(int xCell, int yCell, int modelLength, int modelWidth);
    int addArc41(int xCell, int yCell);
    int addArc14(int xCell, int yCell);
    int addCylinder1(int xCell, int yCell);
    int addCylinder2(int xCell, int yCell);

    void addLight(int xAngle, int yAngle);

    QGraphicsScene *moveUpScene(double value, QRectF rect);
    QGraphicsScene *moveDownScene(double value, QRectF rect);
    QGraphicsScene *moveLeftScene(double value, QRectF rect);
    QGraphicsScene *moveRightScene(double value, QRectF rect);

    QGraphicsScene *scaleScene(double value, QRectF rect);

    QGraphicsScene *rotateXScene(double angle, QRectF rect);
    QGraphicsScene *rotateYScene(double angle, QRectF rect);
    QGraphicsScene *rotateZScene(double angle, QRectF rect);

    QGraphicsScene *toCenter(QRectF rect);

    SceneInf *getScene();

private:
    SceneInf *scene = nullptr;
    Drawer *drawer;

    void addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                 int x1, int y1, int z1,
                 int x2, int y2, int z2,
                 int x3, int y3, int z3,
                 int x4, int y4, int z4);
    void addTriangle(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                     int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int x3, int y3, int z3);
};

#endif
