#pragma once

#include "stdafx.h"

enum class eFieldType
{
    BEGIN,
    EMPTY = BEGIN,
    START,
    RELIX,
    WELL,
    TRAP,
    TREE,
    FINISH,
    TOTAL_COUNT,
};

string ToString(eFieldType);
float  GetProbabylity(eFieldType);
int    GetCount(eFieldType,size_t cols,size_t rows);
map<eFieldType, int >  GetTextures(size_t cols, size_t rows);

eFieldType FromString(const string&);


