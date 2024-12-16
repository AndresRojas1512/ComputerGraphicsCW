#ifndef MICROATXMOTHERBOARD_H
#define MICROATXMOTHERBOARD_H

#include "vertex.hpp"
#include "facet.hpp"
#include "polygonmodel.hpp"
#include "config.hpp"

class MicroATXMotherboard
{
public:
    MicroATXMotherboard(Dot3D startOfPlate_, Dot3D endOfPlate_)
        : startOfPlate(startOfPlate_), endOfPlate(endOfPlate_)
    {
        std::cout << "MicroATXMotherboard::MicroATXMotherboard" << std::endl;
    }

    ~MicroATXMotherboard()
    {
        if (plateModel)
        {
            delete plateModel;
        }
    }

    void buildMotherboard();

private:
    Dot3D startOfPlate;
    Dot3D endOfPlate;

    std::vector<Vertex> vertices;
    std::vector<Facet> facets;
    PolygonModel *plateModel = nullptr;

    void buildPlate();

    void addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets, int x1, int y1, int z1,
                                                                            int x2, int y2, int z2,
                                                                            int x3, int y3, int z3,
                                                                            int x4, int y4, int z4);

    void addCube(std::vector<Vertex> &vertices, std::vector<Facet> &facets, double x, double y, double z, double width, double height, double depth);
};

#endif // MICROATXMOTHERBOARD_H
