#ifndef OBJS_HPP
#define OBJS_HPP

#include <vector>
#include "mathelems.hpp"
#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"
#include "vertex.hpp"
#include "facet.hpp"
#include "polygonmodel.hpp"
#include "light.hpp"
#include "microatxmotherboardconfig.hpp"
#include "atxmotherboardconfig.hpp"
#include "miniitxmotherboardconfig.hpp"
#include "configmanager.hpp"

class SceneInf
{
public:
    SceneInf();
    SceneInf(size_t width_, size_t height);
    SceneInf(size_t width_, size_t height_, int index);

    operator bool() const;

    size_t getWidth();
    size_t getHeight();

    void buildBaseModel(Dot3D startOfPlate_, Dot3D endOfPlate_);
    void buildATXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_);
    void buildMicroATXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_);
    void buildMiniITXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_);

    PolygonModel &getBaseModel();

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

    std::vector<PolygonModel> getModels() const;

    void addMotherboardComponent(ComponentConfig &config, QString modelName, PolygonModel::model_t modelType);

    void addRAMBlock(ComponentConfig &config, QString modelName, ConfigManager::RAMType RAMType, int slot);
    void addRAMAccBlock(ComponentConfig &config, QString accName, ConfigManager::RAMAccessoriesType RAMAccType, int slot);

    void addGPUBlock(ComponentConfig &config, QString modelName, ConfigManager::GPUType GPUType, int slot);
    void addGPUAccBlock(ComponentConfig &config, QString accName, ConfigManager::GPUAccessoriesType GPUAccType, int slot);

    void addCPUBlock(ComponentConfig &config, QString modelName, ConfigManager::CPUType CPUType);
    void addCPUAccBlock(ComponentConfig &config, QString modelName, ConfigManager::CPUAccessoriesType CPUAccType);

    void addTriangle(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                     int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3);

    void addCylinder(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                     double x, double y, double z, double radius, double height, int segments);
private:
    size_t width, height;
    int type;
    Dot3D startOfScene;
    Dot3D endOfScene;

    PolygonModel *plateModel = nullptr;

    Eigen::Matrix4f transMatrix;

    size_t modelsNum = 0;
    std::vector<PolygonModel> models;

    size_t lightNum = 0;
    std::vector<Light> Lights;

    Dot3D centerDot;

    void addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                 int x1, int y1, int z1,
                 int x2, int y2, int z2,
                 int x3, int y3, int z3,
                 int x4, int y4, int z4);

    void addParallelepiped(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                           double x, double y, double z,
                           double width, double height, double depth);


    void addFrame(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                            double x, double y, double z, double width, double height, double depth,
                            double topFrameWidth, double bottomFrameWidth, double leftFrameWidth, double rightFrameWidth);

    void buildBasePlate(std::vector<Vertex> &vertices, std::vector<Facet> &facets, Dot3D startOfPlate_, Dot3D endOfPlate_);

};

#endif
