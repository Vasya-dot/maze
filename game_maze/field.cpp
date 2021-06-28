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

eFieldType FromString(const string& txt)
{
	if (txt == ".") return eFieldType::EMPTY;
	if (txt == "F") return eFieldType::FINISH;
	if (txt == "R") return eFieldType::RELIX;
	if (txt == "S") return eFieldType::START;
	if (txt == "#") return eFieldType::TRAP;
	if (txt == "T") return eFieldType::TREE;
	if (txt == "W") return eFieldType::WELL;
	return eFieldType::EMPTY;
}

float GetProbabylity(eFieldType type)
{

	switch (type)
	{
	case eFieldType::EMPTY:  return 0.4;
	case eFieldType::START:  return 0;
	case eFieldType::RELIX:  return 0.1;
	case eFieldType::TRAP:   return 0.3;
	case eFieldType::FINISH: return 0;
	case eFieldType::TREE:   return 0.1;
	case eFieldType::WELL:   return 0.1;
	default: return 0;
	}
}

int    GetCount(eFieldType type, size_t cols, size_t rows)
{
	if (type == eFieldType::START || type == eFieldType::FINISH)
	{
		return 1;
	}
	return cols * rows * GetProbabylity(type);
}

map<eFieldType, int >  GetTextures(size_t cols, size_t rows)
{
	int count = 0;
	map<eFieldType, int > countTexturs;
	for (int i = 0; i< int(eFieldType::TOTAL_COUNT); i++)
	{
		countTexturs[(eFieldType)i] = GetCount(eFieldType(i), cols, rows);
		count += countTexturs[(eFieldType)i];
	}
	if (cols * rows > count)
	{
		countTexturs[eFieldType::EMPTY] += cols * rows - count;
	}
	return countTexturs;
}

