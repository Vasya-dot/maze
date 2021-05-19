#pragma once
#include "stdafx.h"
#include "map.h"


class eUnit : private eMap
{
public:
    eUnit(uint8_t CoordinateX = 0, uint8_t CoordinateY = 0);
    eUnit()                         = default;
    eUnit(const eUnit&)             = default;
    eUnit(eUnit&&)                  = default;
    virtual ~eUnit()                = default;

    eUnit& operator=(const 	eUnit&) = default;
    eUnit& operator=(eUnit&&) = default;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

protected:
    
};