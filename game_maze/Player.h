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
	virtual void Move(eMoveType type)          override { return; }
	virtual bool CanMove(eMoveType type) const override { return true; }

//	void healRegen(int _healRegenId);
//	void takenDmg(int _takenDmg);

private:
	int                  hp_ = 5;
//	map<uint8_t, string> playerInventory_;
};