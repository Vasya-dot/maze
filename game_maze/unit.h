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

    int GetX() const { return x; }
    int GetY() const { return y; }
protected:
    eMap*  map_ = nullptr;
    int x = 0;
    int y = 0;
    char g;
};