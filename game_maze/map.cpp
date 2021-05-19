#include "map.h"
#include "stdafx.h"

void eMap::cellValue(int coordinateX_, int coordinateY_, eField _field)
{
	fields_[coordinateX_][coordinateY_] = _field;
}

void eMap::generateMap(uint8_t _size, uint8_t _relicsNumber, eField _field)
{
	switch (_field)
	{
	case(eField::EMPTY):
	{
		
	}
	case(eField::RELIC):
	{

	}
	case(eField::TRAP):
	{

	}
	case(eField::WELL):
	{

	}
}



