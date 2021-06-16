#pragma once

#include "stdafx.h"

enum class eFieldType
{
    EMPTY,
    START,
    RELIX,
    WELL,
    TRAP,
    TREE,
    FINISH,
};

string ToString(eFieldType);