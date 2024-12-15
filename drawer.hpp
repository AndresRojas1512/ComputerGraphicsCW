#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include "placeobjects.hpp"
#include "config.hpp"
#include "objects.hpp"

class Drawer
{
public:
    Drawer()
    {
        std::cout << "Drawer::Drawer" << std::endl;
    }
    void zBufferAlg(SceneInf *scene, size_t bufheight, size_t bufWidth);
    void zBufForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                      Eigen::Matrix4f &transMat, size_t color, SceneInf *scene, size_t bufWidth, size_t bufHeight);
    void shadowMapForModel(std::vector<Facet> &facets, std::vector<Vertex> &vertices,
                           Eigen::Matrix4f &transMat, Light *light, size_t bufWidth, size_t bufHeight);


    QGraphicsScene *drawScene(SceneInf *scene, QRectF rect);

private:
    void interColIntoShadowMap();
    void interRowIntoShadowMap(std::vector<std::vector<double>> *map, int xA, int xB, double zA, double zB, int curY);
    void borderPut(int x, int y, double z);
    void bordersForPolygon(
        int xStart, int yStart, double zStart, int xEnd, int yEnd, double zEnd);

    std::vector<std::vector<double>> depthBuffer;
    std::vector<std::vector<size_t>> borderBuffer;
};

#endif // DRAWER_H
