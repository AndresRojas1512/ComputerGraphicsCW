#include "objects.hpp"

const std::vector<size_t> Facet::getVertices() { return vertices; }

//void Facet::setUsedVertices(std::vector<size_t> usedVertices_) { usedVertices = usedVertices_; }

const std::vector<Vertex> PolygonModel::getVertices() { return vertices; }

//void PolygonModel::setVertices(std::vector<Vertex> &vertices_) { vertices = vertices_; }

const std::vector<Facet> PolygonModel::getFacets() { return facets; }

//void PolygonModel::setFacets(std::vector<Facet> facets_) { facets = facets_; }

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

//void PolygonModel::rotateZ(int angle)
//{
//    double radianAngle = (double) angle * M_PI / 180.0;

//    Dot3D start(BASE_START);
//    double xCenter = start.getXCoordinate() + xCell * SIZE_SC + SIZE_SC / 2;
//    double yCenter = start.getYCoordinate() + yCell * SIZE_SC + SIZE_SC / 2;

//    for (size_t i = 0; i < vertices.size(); i++)
//    {
//        Dot3D curDot = vertices.at(i).getPosition();
//        curDot.rotateZ(radianAngle, xCenter, yCenter, 0);
//        vertices.at(i).setPosition(curDot);
//    }
//}

//void PolygonModel::moveTo(int newXCell, int newYCell)
//{
//    Dot3D start(BASE_START);

//    int xInc = SIZE_SC * newXCell - SIZE_SC * xCell;
//    int yInc = SIZE_SC * newYCell - SIZE_SC * yCell;

//    for (size_t i = 0; i < vertices.size(); i++)
//    {
//        Dot3D curDot = vertices.at(i).getPosition();
//        curDot.move(xInc, yInc, 0);
//        vertices.at(i).setPosition(curDot);
//    }

//    xCell = newXCell;
//    yCell = newYCell;
//}

std::vector<std::vector<double>> &Light::getShadowMap() { return shadowMap; }

Light::Light(Eigen::Matrix4f &transMatrix_)
{
    transMatrix = transMatrix_;
    for (size_t i = 0; i < LIGHT_X; i++)
    { shadowMap.push_back(std::vector<double>(LIGHT_Y, 0)); }
}

void Light::setShadowMap(std::vector<std::vector<double>> &setShadowMap)
{
    shadowMap = setShadowMap;
}

void Light::clearShadowMap()
{
    for (size_t i = 0; i < shadowMap.size(); i++)
    {
        for (size_t j = 0; j < shadowMap.at(0).size(); j++)
            shadowMap.at(i).at(j) = 0;
    }
}

void Light::setAngles(int xAngle_, int yAngle_)
{
    xAngle = xAngle_;
    yAngle = yAngle_;
}

int Light::getXAngle() { return xAngle; }

int Light::getYAngle() { return yAngle; }

Eigen::Matrix4f &Light::getTransMat() { return transMatrix; }

void Light::setTransMat(Eigen::Matrix4f &mat) { transMatrix = mat; }


/*
 * SceneInf
*/

SceneInf::SceneInf()
{
    std::cout << "SceneInf::SceneInf(default)" << std::endl;
}

SceneInf::SceneInf(size_t width_, size_t height_)
{
    std::cout << "SceneInf::SceneInf(width, height)" << std::endl;
    width = width_;
    height = height_;

    modelsNum = 0;
    lightNum = 0;

    initUsedCellsZ();
    toCenter();
}

void SceneInf::addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets, int x1,
                       int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4)
{
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
    vec = {size - 4, size - 2, size - 1};
    facets.push_back(vec);
}

size_t SceneInf::getWidth()
{
    return width;
}

size_t SceneInf::getHeight()
{
    return height;
}

SceneInf::operator bool() const
{
    return this->plateModel;
}

void SceneInf::markUsedCellsZ(size_t num)
{
    int xCell = models[num].getUsedXCell();
    int yCell = models[num].getUsedYCell();
    double zCell = models[num].getUsedZCell();
    int widthModel = models[num].getLengthModel();
    int heightModel = models[num].getWidthModel();
    PolygonModel::model_t modelType_ = models[num].getModelType();

    for (int i = yCell; i < yCell + heightModel; i++)
    {
        for (int j = xCell; j < xCell + widthModel; j++)
        {
            getUsedCellsZ()[i][j].push_back(zCell);

            if (modelType_ == PolygonModel::model_t::Tile)
                getUsedCellsZ()[i][j].push_back(-1);
        }
    }
}



void SceneInf::clearUsedCellsZ(size_t num)
{
    int xCell = models[num].getUsedXCell();
    int yCell = models[num].getUsedYCell();
    int widthModel = models[num].getLengthModel();
    int heightModel = models[num].getWidthModel();
    PolygonModel::model_t modelType_ = models[num].getModelType();

    for (int i = yCell; i < yCell + heightModel; i++)
    {
        for (int j = xCell; j < xCell + widthModel; j++)
        {
            if (modelType_ == PolygonModel::model_t::Tile)
                getUsedCellsZ()[i][j].erase(getUsedCellsZ()[i][j].end() - 1);
            getUsedCellsZ()[i][j].erase(getUsedCellsZ()[i][j].end() - 1);
            qDebug() << "i = " << i << "j = " << j << "освобождена";
        }
    }
}

void SceneInf::moveUp(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, -value, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveDown(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, value, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveLeft(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        -value, 0, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::moveRight(double value)
{
    Eigen::Matrix4f moveMat;
    moveMat << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        value, 0, 0, 1;

    transMatrix *= moveMat;
}

void SceneInf::scale(double value)
{
    Eigen::Matrix4f scaleMatrix;
    scaleMatrix << value,     0,     0, 0,
        0,    value,     0, 0,
        0,        0, value, 0,
        0,        0,     0, 1;

    transMatrix *= scaleMatrix;
}

void SceneInf::rotateX(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << 1,           0,          0, 0,
        0, cos(angle), -sin(angle), 0,
        0, sin(angle),  cos(angle), 0,
        0,           0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::rotateY(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle),  0, sin(angle), 0,
        0,           1,          0, 0,
        -sin(angle), 0, cos(angle), 0,
        0,           0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::rotateZ(double angle)
{
    Eigen::Matrix4f rotateMatrix;
    rotateMatrix << cos(angle),  -sin(angle), 0, 0,
        sin(angle),   cos(angle), 0, 0,
        0,            0,          1, 0,
        0,            0,          0, 1;

    transMatrix *= rotateMatrix;
}

void SceneInf::toCenter()
{
    Dot3D start(BASE_START);

    Eigen::Matrix4f newMat;

    newMat << 1,  0, 0, 0,
        0,  1, 0, 0,
        0,  0, 1, 0,
        0,  0, 0, 1;

    newMat(3, 0) = X_CENTER - start.getXCoordinate() - getWidth() * SIZE_SC / 2;
    newMat(3, 1) = Y_CENTER - start.getYCoordinate() - getHeight() * SIZE_SC / 2;
    newMat(3, 2) = 0;

    transMatrix = newMat;
}


size_t SceneInf::getModelsNum() { return modelsNum; }

PolygonModel &SceneInf::getModel(size_t num) { return models.at(num); }

void SceneInf::setModel(size_t num, PolygonModel &newModel) { models.at(num) = newModel; }


void SceneInf::addModel(PolygonModel &model)
{
    std::cout << "SceneIng::addModel" << std::endl;
    modelsNum++;
    models.push_back(model);
    markUsedCellsZ(modelsNum - 1);
    //    printUsedCellsZ();
}

size_t SceneInf::getLightNum() { return lightNum; }

Light &SceneInf::getLight(size_t num) { return Lights.at(num); }

void SceneInf::setLight(Light &light, size_t i) { Lights.at(i) = light; }

void SceneInf::addLight(Light &light)
{
    lightNum++;
    Lights.push_back(light);
}

void SceneInf::deleteLight(size_t num)
{
    if (num < Lights.size())
    {
        lightNum--;
        Lights.erase(Lights.begin() + num);
    }
}

void SceneInf::deleteModel(size_t num)
{
    if (num < models.size())
    {
        clearUsedCellsZ(num);
        modelsNum--;
        models.erase(models.begin() + num);
    }
}

void SceneInf::printUsedCellsZ()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)

            qDebug() << "(" << i + 1<< "; " << j + 1<< ") " << getUsedCellsZ()[i][j];
    }
}


PolygonModel &SceneInf::getBaseModel()
{
    return *plateModel;
}

void SceneInf::buildBaseModel(Dot3D startOfPlate_, Dot3D endOfPlate_)
{
    std::cout << "--> SceneInf::buildBaseModel" << std::endl;
    std::cout << "SceneInf::buildBaseModel: startOfPlate_: " << startOfPlate_;
    std::cout << "SceneInf::buildBaseModel: endOfPlate_: " << endOfPlate_;

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;

    double blockHeight = 60;
    double blockDepth = 30;
    double blockWidth = 20;

    // upp
    addQuad(vertices, facets,
            startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate(), BASE_Z,
            endOfPlate_.getXCoordinate() + 10 , startOfPlate_.getYCoordinate(), BASE_Z,
            endOfPlate_.getXCoordinate() + 10 , endOfPlate_.getYCoordinate() + 10 , BASE_Z,
            startOfPlate_.getXCoordinate(), endOfPlate_.getYCoordinate() + 10 , BASE_Z);

    double componentBaseZ = BASE_Z + blockDepth;

    // USB Block - at the top
    addCube(vertices, facets,
            startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + 10,
            componentBaseZ, blockWidth, blockHeight, blockDepth);

    // // Video Block - below USB
    // addCube(vertices, facets,
    //         startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + blockHeight,
    //         componentBaseZ, blockWidth, blockHeight, blockDepth);

    // // LAN Block - below Video
    // addCube(vertices, facets,
    //         startOfPlate_.getXCoordinate(), startOfPlate_.getYCoordinate() + 2 * blockHeight,
    //         componentBaseZ, blockWidth, blockHeight, blockDepth);

    // body
    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT);

    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z);

    addQuad(vertices, facets, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z, startOfPlate_.getXCoordinate(),
            endOfPlate_.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z, endOfPlate_.getXCoordinate() + 10,
            endOfPlate_.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate_.getXCoordinate(),
            startOfPlate_.getYCoordinate(), BASE_Z, endOfPlate_.getXCoordinate() + 10,
            startOfPlate_.getYCoordinate(), BASE_Z);

    if (plateModel)
        delete plateModel;
    plateModel = new PolygonModel(vertices, facets);
}

void SceneInf::addCube(std::vector<Vertex> &vertices, std::vector<Facet> &facets,
                       double x, double y, double z, double width, double height, double depth)
{
    // Front face
    addQuad(vertices, facets, x, y, z, x + width, y, z, x + width, y + height, z, x, y + height, z);
    // Back face
    addQuad(vertices, facets, x, y, z - depth, x + width, y, z - depth, x + width, y + height, z - depth, x, y + height, z - depth);
    // Left face
    addQuad(vertices, facets, x, y, z, x, y + height, z, x, y + height, z - depth, x, y, z - depth);
    // Right face
    addQuad(vertices, facets, x + width, y, z, x + width, y + height, z, x + width, y + height, z - depth, x + width, y, z - depth);
    // Top face
    addQuad(vertices, facets, x, y + height, z, x + width, y + height, z, x + width, y + height, z - depth, x, y + height, z - depth);
    // Bottom face
    addQuad(vertices, facets, x, y, z, x + width, y, z, x + width, y, z - depth, x, y, z - depth);
}

void SceneInf::changeSize(size_t newWidth, size_t newHeight)
{
    if (newWidth)
    {
        if (newWidth < width)
        {
            for (size_t i = 0; i < modelsNum; i++)
            {
                if (getModel(i).getUsedXCell() >= (int)newWidth)
                {
                    deleteModel(i);
                    i--;
                }
            }
        }

        width = newWidth;
    }


    if (newHeight)
    {
        if (newHeight < height)
        {
            for (size_t i = 0; i < modelsNum; i++)
            {
                if (getModel(i).getUsedYCell() >= (int)newHeight)
                {
                    deleteModel(i);
                    i--;
                }
            }
        }

        height = newHeight;
    }
}

Eigen::Matrix4f &SceneInf::getTransMatrix() { return transMatrix; }

void SceneInf::initUsedCellsZ()
{
    usedCellsZ.resize(getHeight());

    for (size_t i = 0; i < getHeight(); i++)
    {
        usedCellsZ[i].resize(getWidth());
        for (size_t j = 0; j < getWidth(); j++)
            usedCellsZ[i][j].resize(1, 0);
    }

}

std::vector<std::vector<std::vector<double>>> &SceneInf::getUsedCellsZ() { return usedCellsZ; }
