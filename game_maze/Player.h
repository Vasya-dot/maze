#pragma once
#include "unit.h"

class ePlayer : private  eUnit
{
public:

	ePlayer();
	ePlayer(const ePlayer&) = default;
	ePlayer(ePlayer&&) = default;
	virtual ~ePlayer() = default;

	ePlayer& operator=(const ePlayer&) = default;
	ePlayer& operator=( ePlayer&&) = default;

	void healRegen(int _healRegenId);
	void takenDmg(int _takenDmg);

private:
	int                  heal_ = 5;
	map<uint8_t, string> playerInventory_;
};