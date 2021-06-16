#include "field.h"

string ToString(eFieldType type)
{
	switch (type)
	{
	case eFieldType::EMPTY:  return ".";
	case eFieldType::START:  return "S";
	case eFieldType::RELIX:  return "R";
	case eFieldType::TRAP:   return "#";
	case eFieldType::FINISH: return "F";
	case eFieldType::TREE:   return "T";
	case eFieldType::WELL:   return "W";
	default: return "0";
	}
	
	return "";
}