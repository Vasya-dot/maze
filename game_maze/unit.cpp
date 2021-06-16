#include "unit.h"
bool eUnit::Init(eMap* _map)
{
	map_ = _map;
	return map_;
}
void eUnit::Done()
{
	eMap* map_ = nullptr;
}
