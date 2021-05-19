#include "unit.h"
void eUnit::moveUp()
{
	if (coordinateY_ == 1)
	{
		coordinateY_ = 1;
	}
	else
	{
		coordinateY_++;
	}
}