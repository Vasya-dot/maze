#include "unit.h"

bool eUnit::Init(eMap* _map)
{
	map_ = _map;
	x = rand() % 5;
	y = rand() % 5;
	return map_ && map_->Register(this);
}

void eUnit::Done()
{
	map_->Unregister(this);
    map_ = nullptr;
}

bool eUnit::IsCoordinatesOnBoard(int _x, int _y) const
{
	if (_x < 0
		|| _x >= map_->Cols()
		|| _y < 0
		|| _y >= map_->Rows())
	{
		return false;
	}
	return true;
}

string eUnit::Dump()           const
{
	stringstream ss;
	ss << "x: " << x << "\ty: " << y << "\thp: " << hp;
	return ss.str();
}