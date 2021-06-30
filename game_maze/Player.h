#pragma once
#include "unit.h"

class ePlayer : public eUnit
{
	using eBase = eUnit;
public:
	ePlayer() = default;
	ePlayer(const ePlayer&) = default;
	ePlayer(ePlayer&&) = default;
	virtual ~ePlayer() = default;

	ePlayer& operator=(const ePlayer&) = default;
	ePlayer& operator=( ePlayer&&) = default;

	virtual string ToString()            const override { return "p"; }

	bool Move(char g);

protected:
	virtual void Move(eMoveType type)                 override;
	virtual bool CanMove(eMoveType type) const override;
 
private:
	int                  hp_ = 5;
	char                 g;
//	map<uint8_t, string> playerInventory_;
};