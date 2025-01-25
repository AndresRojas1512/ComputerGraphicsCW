#ifndef BASEMOTHERBOARDCONFIG_HPP
#define BASEMOTHERBOARDCONFIG_HPP

#include <QList>
#include <vector>
#include <map>
#include "mathelems.hpp"
#include "config.hpp"
#include "componentprimitives.hpp"

class BaseMotherboardConfig
{
public:
    BaseMotherboardConfig(const Dot3D &startOfPlate_, const Dot3D &endOfPlate_)
        : startOfPlate(startOfPlate_), endOfPlate(endOfPlate_) {}

    virtual ~BaseMotherboardConfig() = default;

    virtual bool isRamSlotAvailable(int slot) = 0;
    virtual void occupyRamSlot(int slot) = 0;
    virtual QList<int> getAvailableRamSlots() = 0;

    virtual Dot3D getStartOfPlate() const = 0;
    virtual Dot3D getEndOfPlate() const = 0;

    virtual Dot3D getRamSlotPosition(int slot) const = 0;

protected:
    Dot3D startOfPlate;
    Dot3D endOfPlate;
    std::map<int, bool> ramSlotsOccupied;
};

#endif // BASEMOTHERBOARDCONFIG_HPP
