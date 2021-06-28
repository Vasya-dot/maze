#include "enemy.h"

bool eEnemy::Move()
{
	int i = rand() % 4;
	if (CanMove(eMoveType(i)))
	{
		Move(eMoveType(i));
		return true;
	}
	return false;
}

void eEnemy::Move(eMoveType type)
{
	switch (type)
	{
		case eMoveType::DOWN:y++;  break;
		case eMoveType::UP:y--;    break;
		case eMoveType::LEFT:x--;  break;
		case eMoveType::RIGHT:x++; break;
	}
}

bool eEnemy::CanMove(eMoveType type) const
{
	return true;
}
