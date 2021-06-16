#pragma once

#include "unit.h"

class ePlayer : public eUnit
{
	using eBase = eUnit;
public:
	ePlayer();
	ePlayer(const ePlayer&) = default;
	ePlayer(ePlayer&&) = default;
	virtual ~ePlayer() = default;

	ePlayer& operator=(const ePlayer&) = default;
	ePlayer& operator=( ePlayer&&) = default;

	virtual bool Init(eMap*);
	virtual string ToString() const  override { return "P";  };
	virtual void Move(eMoveType type) = 0;
	virtual bool CanMove(eMoveType type) const = 0;


//	void healRegen(int _healRegenId);
//	void takenDmg(int _takenDmg);

private:
	int                  hp_ = 5;
//	map<uint8_t, string> playerInventory_;
};