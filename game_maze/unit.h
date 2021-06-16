#pragma once
#include "stdafx.h"
#include "map.h"

enum class eMoveType
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

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
    virtual void Move(eMoveType type)           = 0;
    virtual bool CanMove(eMoveType type) const  = 0;

protected:
    eMap*  map_ = nullptr;
    size_t x = 0;
    size_t y = 0;

};