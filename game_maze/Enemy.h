#pragma once
#include "unit.h"

class eEnemy : public  eUnit
{
public:
	eEnemy()                         ;
	eEnemy(const eEnemy&)            = default;
	eEnemy(eEnemy&&)                 = default;
	virtual ~eEnemy()                = default;

	eEnemy& operator=(const eEnemy&) = default;
	eEnemy& operator=(eEnemy&&)      = default;

	virtual string ToString()            const override { return "e"; }
	
	virtual bool Move()                        override;

protected:
	virtual string Dump()                const override;
	virtual void Move(eMoveType type)          override;
	virtual bool CanMove(eMoveType type) const override;

private:
	static int idGenerator;
	int id = 0;
	int                  attackDmg_ = 1;
};