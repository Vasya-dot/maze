#include "map.h"
#include "stdafx.h"

bool eMap::Init()
{
	vector<eFieldType> line0 = { eFieldType::EMPTY, eFieldType::FINISH, eFieldType::RELIX, eFieldType::TRAP, eFieldType::TRAP };
	vector<eFieldType> line1 = { eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::EMPTY };
	vector<eFieldType> line2 = { eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::RELIX, eFieldType::TRAP, eFieldType::TRAP };
	vector<eFieldType> line3 = { eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX };
	vector<eFieldType> line4 = { eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX, eFieldType::RELIX };
	vector<eFieldType> line5 = { eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::EMPTY, eFieldType::TRAP, eFieldType::START };
	fields_.emplace_back(line0);
	fields_.emplace_back(line1);
	fields_.emplace_back(line2);
	fields_.emplace_back(line3);
	fields_.emplace_back(line4);
	fields_.emplace_back(line5);

	return true;
}

eFieldType eMap::Get(size_t coordinateX, size_t coordinateY) const
{
	if (coordinateX < 0
		|| coordinateX > cols_ 
		|| coordinateY < 0
		||coordinateY > rows_)
	{
		return eFieldType::EMPTY;
	}
	else
	return fields_[coordinateX][coordinateY];
}


size_t eMap::Count(eFieldType type) const
{
	int counter = 0;
	for (int i = 0; i < cols_; i++)
	{
		for (int j = 0; j < rows_; j++)
		{
			if (fields_[i][j] == type)
			{
				counter++;
			}

		}
	}
	return counter;
}

string eMap::Dump() const
{
	ostringstream ss;
	for (size_t i = 0; i < fields_.size(); ++i)
	{
		for (size_t j = 0; j < fields_[i].size(); ++j)
		{
			ss << ToString(fields_[i][j]) << " ";
		}
		ss << endl;
	}
	return ss.str();
}
