#pragma once
#include "unit.h"

class eEnemy : public  eUnit
{
public:
	eEnemy() = default;
	eEnemy(const eEnemy&) = default;
	eEnemy(eEnemy&&) = default;
	virtual ~eEnemy() = default;

	eEnemy& operator=(const eEnemy&) = default;
	eEnemy& operator=(eEnemy&&) = default;

	virtual string ToString()            const override { return "e"; }
	
	bool Move();

protected:

	virtual void Move(eMoveType type)          override;
	virtual bool CanMove(eMoveType type) const override;

private:

	int                  attackDmg_ = 1;
};