#include "player.h"

bool ePlayer::Move()
{
	eMoveType var = ConsoleMove();
	if (CanMove(var))
	{
		Move(var);
		return true;
	}
	return false;
}


void ePlayer::Move(eMoveType type)
{
	switch (type)
	{
	case eMoveType::DOWN:	x++;	break;
	case eMoveType::UP:		x--;    break;
	case eMoveType::LEFT:	y--;	break;
	case eMoveType::RIGHT:	y++;	break;
	}

	eFieldType  field = map_->Get(x, y);
	
	
	switch (field)
	{
	case eFieldType::WELL : hp++ ;
		break;
	}
	map_->Set(x, y, eFieldType::EMPTY);
}

bool ePlayer::CanMove(eMoveType type) const
{
	int xNew = x;
	int yNew = y;

	switch (type)
	{
	case eMoveType::DOWN:	xNew++;		break;
	case eMoveType::UP:		xNew--;		break;
	case eMoveType::LEFT:	yNew--;		break;
	case eMoveType::RIGHT:	yNew++;		break;
	}
	if (!IsCoordinatesOnBoard(xNew, yNew))
	{
		return false;
	}
	eFieldType  field = map_->Get(xNew,yNew);
	switch (field)
	{
	case eFieldType::TREE: return false;
	}
	return true;
}

string ePlayer::Dump() const
{
	stringstream ss;
	ss << "player " << eUnit::Dump();
	return ss.str();
}
