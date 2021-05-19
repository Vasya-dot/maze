#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;


class eMap
{
public:
    eMap(uint8_t size, uint8_t RelicsNumber);
    eMap(const eMap&) = delete;
    eMap(eMap&&) = delete;
    virtual ~eMap() = default;

    void generateMap(uint8_t _size, uint8_t _relicsNumber, eField _field);
    void cellValue(int coordinateX_,int coordinateY_, eField _field);
    /*
      1X 2X 3X 4X 5X 6X 
      2X  X  X  X  X  X 
      3X  X  X  X  X  X
      4X  X  X  X  X  X
      5X  X  X  X  X  X
      6X  X  X  X  X  X
     */

    void dump();


protected:

    int                    coordinateX_ = 0;
    int                    coordinateY_ = 0;
    vector<vector<eMap>>  fields_;    
    uint8_t               relicsNumber_ = 2;
    uint8_t               size_ = 6;
};