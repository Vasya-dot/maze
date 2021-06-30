#include "enemy.h"

int eEnemy::idGenerator = 0;

eEnemy::eEnemy()
{
	id = idGenerator++;
}

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

string eEnemy::Dump() const
{
	stringstream ss;
	ss << "enemy id: " << id <<"\t"<<eUnit::Dump();
	return ss.str();
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
