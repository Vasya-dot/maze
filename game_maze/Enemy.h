#pragma once

#include <vector>

using namespace std;

//create class iUnit with pure virtual function Move
//use inheritance to enemy and player


class Enemy
{
public:
    Enemy();
    Enemy(const Enemy&)  = delete;
    Enemy(Enemy&&)       = delete;
    virtual ~Enemy()     = default;

    virtual void Move();

protected:
    uint8_t   Damage = 1;
    
};