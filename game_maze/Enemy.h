#pragma once

#include <vector>

using namespace std;


class Enemy
{
public:
    Enemy();
    Enemy(const Enemy&)  = delete;
    Enemy(Enemy&&)       = delete;
    virtual ~Enemy()     = default;

    void EnemyMove();

protected:
    uint8_t   Damage = 1;
    
};