#include "microatxmotherboard.hpp"

void MicroATXMotherboard::buildMotherboard()
{
    buildPlate();
}

void MicroATXMotherboard::buildPlate()
{
    std::cout << "--> MicroATXMotherboard::buildBase" << std::endl;
    std::cout << "MicroATXMotherboard::buildBase: startOfPlate: " << startOfPlate;
    std::cout << "MicroATXMotherboard::buildBase: endOfPlate_: " << endOfPlate;

    addQuad(vertices, facets,
            startOfPlate.getXCoordinate(), startOfPlate.getYCoordinate(), BASE_Z,
            endOfPlate.getXCoordinate() + 10 , startOfPlate.getYCoordinate(), BASE_Z,
            endOfPlate.getXCoordinate() + 10 , endOfPlate.getYCoordinate() + 10 , BASE_Z,
            startOfPlate.getXCoordinate(), endOfPlate.getYCoordinate() + 10 , BASE_Z);

    addQuad(vertices, facets, startOfPlate.getXCoordinate(),
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate.getXCoordinate(),
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT);

    addQuad(vertices, facets, startOfPlate.getXCoordinate(),
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate.getXCoordinate(),
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, startOfPlate.getXCoordinate(),
            endOfPlate.getYCoordinate() + 10, BASE_Z, startOfPlate.getXCoordinate(),
            startOfPlate.getYCoordinate(), BASE_Z);

    addQuad(vertices, facets, startOfPlate.getXCoordinate(),
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            endOfPlate.getYCoordinate() + 10, BASE_Z, startOfPlate.getXCoordinate(),
            endOfPlate.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate.getXCoordinate() + 10,
            endOfPlate.getYCoordinate() + 10, BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT, endOfPlate.getXCoordinate() + 10,
            startOfPlate.getYCoordinate(), BASE_Z, endOfPlate.getXCoordinate() + 10,
            endOfPlate.getYCoordinate() + 10, BASE_Z);

    addQuad(vertices, facets, endOfPlate.getXCoordinate() + 10,
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate.getXCoordinate(),
            startOfPlate.getYCoordinate(), BASE_Z - PLATE_HEIGHT, startOfPlate.getXCoordinate(),
            startOfPlate.getYCoordinate(), BASE_Z, endOfPlate.getXCoordinate() + 10,
            startOfPlate.getYCoordinate(), BASE_Z);
}

void MicroATXMotherboard::addQuad(std::vector<Vertex> &vertices, std::vector<Facet> &facets, int x1, int y1, int z1,
                                                                                             int x2, int y2, int z2,
                                                                                             int x3, int y3, int z3,
                                                                                             int x4, int y4, int z4)
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

void MicroATXMotherboard::addCube(std::vector<Vertex> &vertices, std::vector<Facet> &facets, double x, double y, double z, double width, double height, double depth)
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
