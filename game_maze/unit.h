#pragma once

#include "stdafx.h"
#include "map.h"
#include "move_types.h"


class eUnit
{
public:
    eUnit()                         = default;
    eUnit(const eUnit&)             = default;
    eUnit(eUnit&&)                  = default;
    virtual ~eUnit()                = default;

    eUnit& operator=(const 	eUnit&) = default;
    eUnit& operator=(eUnit&&)       = default;

    virtual bool Init(eMap*);
    virtual void Done();       //protivopolojno init
    virtual string ToString()            const  = 0;
    
    virtual bool Move()                         = 0;

    int GetX() const { return x; }
    int GetY() const { return y; }

    bool IsAlive() const { return hp > 0; }

    virtual string Dump()           const;

protected:
    virtual void Move(eMoveType type)           = 0;
    virtual bool CanMove(eMoveType type) const  = 0;
    bool IsCoordinatesOnBoard(int x, int y) const;

protected:

    eMap*  map_ = nullptr;
    int    x  = 0;
    int    y  = 0;
    size_t hp = 5;
};