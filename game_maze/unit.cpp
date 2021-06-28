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
