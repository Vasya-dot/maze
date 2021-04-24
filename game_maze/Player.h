#pragma once

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Player
{
public:
    
    Player(uint8_t CoordinateX = 0, uint8_t CoordinateY = 0);
    Player() = default;
    Player(const Player&) = default;
    Player(Player&&) = default;
    virtual ~Player() = default;

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void ReceivedDamage(uint8_t _damageId);
    void HealRegen(uint8_t _regenId);

protected:
    uint8_t               Health           = 5;
    uint8_t               CollectedRelics  = 0;
    int                   CoordinateX      = 0;
    int                   CoordinateY      = 0;
    map<uint8_t,string>   inventory;
};