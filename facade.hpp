#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include "sceneinf.hpp"
#include "drawer.hpp"
#include <QGraphicsScene>
#include "QDebug"
#include "QPen"
#include <limits>
#include "math.h"
#include "config.hpp"
#include "basemotherboardconfig.hpp"
#include "atxmotherboardconfig.hpp"
#include "microatxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"
#include "configmanager.hpp"
#include "ramconfig.hpp"
#include "gpuconfig.hpp"
#include "cpuconfig.hpp"

class Facade
{
public:
    Facade(ConfigManager &configManager_);

    void setSceneInfMotherboard(ConfigManager::MotherboardType type);
    void changeSceneInf(size_t newWidth, size_t newheight);
    bool isSceneSet();

    QGraphicsScene *drawScene(QRectF rect);

    int addCPU(ConfigManager::MotherboardType motherboardType, ConfigManager::CPUType CPUType);
    int addRAM(ConfigManager::MotherboardType motherboardType, ConfigManager::RAMType RAMType, int slotIndex);
    int addGPU(ConfigManager::MotherboardType motherboardType, ConfigManager::GPUType GPUType, int slotIndex);

    void addLight(int xAngle, int yAngle);
    bool isLightSet(void);
    void removeLight(void);

    void changeCPUColor(QColor color, QColor shadow);
    void changeRAMColor(QColor color, QColor shadow);
    void changeGPUColor(QColor color, QColor shadow);

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

    BaseMotherboardConfig *getMotherboardConfig();

private:
    ConfigManager &configManager;
    SceneInf *scene = nullptr;
    SceneDrawer *drawer;
    BaseMotherboardConfig *motherboardConfig = nullptr;
    CPUConfig cpuConfig;
    RAMConfig ramConfig;
    GPUConfig gpuConfig;
    bool lightSet = false;

    Color cpuColor = Color::GREEN_BLUE;
    Color cpuShadow = Color::DARK_GREEN_BLUE;

    Color ramColor = Color::GRAY_BLUE;
    Color ramShadow = Color::DARK_GRAY_BLUE;

    Color gpuColor = Color::GRAY_BLUE;
    Color gpuShadow = Color::DARK_GRAY_BLUE;


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
