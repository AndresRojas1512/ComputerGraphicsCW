#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "mathelems.hpp"
#include <iostream>
#include <vector>
#include <QDebug>
#include "config.hpp"

class Vertex
{
public:
    Vertex() {}
    Vertex(Dot3D &position_, std::vector<size_t> &facets_)
        : position(position_), facets(facets_) { }

    Vertex(Dot3D &position_) : position(position_) { }

    const Dot3D &getPosition() const;
    void setPosition(Dot3D &position_);
    const std::vector<size_t> getFacets();
    void setFacets(std::vector<size_t> facets_);

private:
    Dot3D position;
    std::vector<size_t> facets;
};

#endif // VERTEX_HPP
