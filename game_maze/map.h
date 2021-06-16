#pragma once

#include "stdafx.h"
#include "field.h"

class eMap
{
public:
//    eMap(uint8_t cols, uint8_t rows);
    eMap()                                            = default;
    eMap(const eMap&)                                 = delete;
    eMap(eMap&&)                                      = delete;
    virtual ~eMap()                                   = default;

    eMap&       operator=(const eMap&)                = delete;
    eMap&       operator=(eMap&&)                     = delete;

    bool        Init();
    //todo:
    eFieldType  Get(size_t coordinateX, size_t coordinateY) const;
    size_t      Count(eFieldType) const;
    
    uint8_t      Cols() const { return cols_ ; }
    uint8_t      Rows() const { return rows_ ; }

    string      Dump() const;
protected:
    vector<vector<eFieldType>>  fields_;
    uint8_t                     cols_ = 6;
    uint8_t                     rows_ = 5;
};