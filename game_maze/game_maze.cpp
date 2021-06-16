// game_maze.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    eMap map;
    map.Init();
    cout << map.Dump();
    cout << (int)map.Get(1, 2) << endl;
    cout << map.Count(eFieldType::RELIX) << endl;
}

