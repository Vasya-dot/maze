﻿// game_maze.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    ofstream ofs("2.txt");
    if(ofs.is_open())
    {
       map.Save(ofs);
    }
    ofs.close();
    eMap map1;
    ifstream ifs("2.txt");
    if (ifs.is_open())
    {
        map1.Load(ifs);
    }
    ifs.close();
    cout << map1.Dump();
    cout << map.Count(eFieldType::RELIX) << endl;
}

