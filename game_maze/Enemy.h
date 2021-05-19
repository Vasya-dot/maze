#pragma once
#include "unit.h"

class eEnemy : private  eUnit
{
public:
	eEnemy();
	eEnemy(const eEnemy&) = default;
	eEnemy(eEnemy&&) = default;
	virtual ~eEnemy() = default;

	eEnemy& operator=(const eEnemy&) = default;
	eEnemy& operator=(eEnemy&&) = default;

	int randomMove();
private:
	int                  attackDmg_ = 1;
};