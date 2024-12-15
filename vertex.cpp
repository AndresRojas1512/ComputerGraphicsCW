#include "vertex.hpp"

const Dot3D &Vertex::getPosition() const
{
    return position;
}

void Vertex::setPosition(Dot3D &position_)
{
    position = position_;
}

const std::vector<size_t> Vertex::getFacets()
{
    return facets;
}

void Vertex::setFacets(std::vector<size_t> facets_)
{
    facets = facets_;
}
