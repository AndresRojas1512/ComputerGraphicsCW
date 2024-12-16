#ifndef FACET_HPP
#define FACET_HPP

#include "mathelems.hpp"
#include <iostream>
#include <vector>
#include "placeobjects.hpp"
#include <QDebug>
#include "config.hpp"
#include "vertex.hpp"

class Facet
{
public:
    Facet() {}
    Facet(std::vector<size_t> vertices_) : vertices(vertices_) {}

    const std::vector<size_t> getVertices();

private:
    std::vector<size_t> vertices;
};

#endif // FACET_HPP
