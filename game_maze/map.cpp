#include "map.h"
#include "stdafx.h"
#include "unit.h"
#include <algorithm>

bool eMap::Init()
{
	map<eFieldType, int > countTexturs = GetTextures(cols_, rows_);
	ranlux48 generator;
	normal_distribution<float> distribution((float)eFieldType::BEGIN, (float)eFieldType::TOTAL_COUNT);

	int r = 0;
	for (int i = 0; i < cols_; i++)
	{
		vector<eFieldType> line;
		for (int j = 0; j < rows_; j++)
		{
			while(true)
			{
				r = distribution (generator);
				//r = rand() % (int(eFieldType::TOTAL_COUNT));
				if (countTexturs[(eFieldType)r] > 0)
				{
					countTexturs[(eFieldType)r]--;
					break;
				}
			} 
			 line.emplace_back((eFieldType)r);
		}
		fields_.emplace_back(line);
	}

	return true;
}

eFieldType eMap::Get(size_t coordinateX, size_t coordinateY) const
{
	if (coordinateX < 0
		|| coordinateX >= cols_ 
		|| coordinateY < 0
		||coordinateY >= rows_)
	{
		return eFieldType::EMPTY;
	}
	else
	return fields_[coordinateX][coordinateY];
}


size_t eMap::Count(eFieldType type) const
{
	int counter = 0;
	for (int i = 0; i < fields_.size(); i++)
	{
		for (int j = 0; j < fields_[i].size (); j++)
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
	for (eUnit* unit : units_)
	{
		ss << unit->Dump() << endl;
	}
	for (size_t i = 0; i < fields_.size(); ++i)
	{
		for (size_t j = 0; j < fields_[i].size(); ++j)
		{
			auto it = find_if(units_.cbegin(), units_.cend(), [x = i,y = j](eUnit* item)
				{
					return x == item->GetX() && y == item->GetY() && item->IsAlive();
				});
			if (it != units_.cend())
			{
				ss <<(*it)->ToString() << " ";

			}
			else
			{
                ss << ToString(fields_[i][j]) << " ";
			}
			
		}
		ss << endl;
	}
	return ss.str();
}

bool    eMap::Save(ostream& oss) const
{
	oss << cols_<<"\t"<<rows_;
	oss << Dump();
	return true;
}

bool eMap::Load(istream& iss)
{
	iss >> cols_ >> rows_;
	fields_.clear();
	string txt;
	for (int i = 0; i < cols_; i++)
	{
		vector<eFieldType> line;
		for (int j = 0; j < rows_; j++)
		{
			iss >> txt;
			line.emplace_back(FromString(txt));
		}
		fields_.emplace_back(line);
	}
	return true;
}

bool eMap::Register(eUnit* unit)
{
	auto it = find_if(units_.cbegin(), units_.cend(), [unit](eUnit* item)
		{return unit == item; });
	if (it != units_.cend())
	{
		return false;
	}
	units_.emplace_back(unit);
	return true;
}

bool eMap::Unregister(eUnit* unit)
{
	auto it = remove_if(units_.begin(), units_.end(), [unit](eUnit* item)
		               {return unit == item; });
	units_.erase(it, units_.end());
	return true;
}

void eMap::Move()
{
	for (eUnit* unit : units_)
	{
		if (unit->IsAlive())
		{
          unit->Move();
		}
		
	}
}

void  eMap::Set(size_t coordinateX, size_t coordinateY, eFieldType type) 
{
	if (!
		(coordinateX < 0
		|| coordinateX >= cols_
		|| coordinateY < 0
		|| coordinateY >= rows_))
	{
		fields_[coordinateX][coordinateY] = type;
	}
}