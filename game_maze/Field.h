#pragma once
#include <vector>

using namespace std;
enum class field
{
    TRAP, //#
    RELIC, //R
    EMPTY, // o
    WELL //колодец?
};

class Field
{
public:
    Field(uint8_t size, uint8_t RelicsNumber);
    Field(const Field&) = delete;
    Field(Field&&) = delete;
    virtual ~Field() = default;

    void GenerateMap(uint8_t Size, uint8_t RelicsNumber);
    void Dump();


protected:

    vector<vector<Field>> Fields;
    uint8_t               RelicsNumber = 2;
    uint8_t               Size = 6;
};