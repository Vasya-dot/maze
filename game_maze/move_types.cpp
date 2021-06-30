#include "move_types.h"
#include <conio.h>

eMoveType ConsoleMove()
{
	char t = 0;
	while (true)
	{
		t = _getch();
		switch (t)
		{
		case 'W':  
		case 'w': return eMoveType::UP;
		
		case 'S':  
		case 's': return eMoveType::DOWN;
		
		case 'A':  
		case 'a': return eMoveType::LEFT;
		
        case 'D':  
		case 'd': return eMoveType::RIGHT;
		}
	}
	return eMoveType::RIGHT;
}