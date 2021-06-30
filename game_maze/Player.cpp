#include "player.h"

bool ePlayer::Move(char g)
{
	switch (g)
	{
	case 'w': 
		if(CanMove(eMoveType::UP))
		Move(eMoveType::UP);     break;
	case 's': 
		if(CanMove(eMoveType::DOWN))
		Move(eMoveType::DOWN);   break;
	case 'a': 
		if (CanMove(eMoveType::LEFT))
		Move(eMoveType::LEFT);   break;
	case 'd': 
		if (CanMove(eMoveType::RIGHT))
		Move(eMoveType::RIGHT);  break;
	default : return 0;
	}
}


void ePlayer::Move(eMoveType type)
{
	switch (type)
	{
	case eMoveType::DOWN:x++;  break;
	case eMoveType::UP:x--;    break;
	case eMoveType::LEFT:y--;  break;
	case eMoveType::RIGHT:y++; break;
	}
}

bool ePlayer::CanMove(eMoveType type) const
{
	return true;
}
