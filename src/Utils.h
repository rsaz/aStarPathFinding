#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::abs;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

namespace Utils
{
    enum class State
    {
        kEmpty,
        kObstacle,
        kClosed,
        kPath,
        kStart,
        kFinish
    };

    // hardcoded delta for now
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    vector<State> ParseLine(string line);

    vector<vector<State>> ReadMapFile(string path);

    bool Compare(const vector<int> a, const vector<int> b);

    void CellSort(vector<vector<int>> *v);

    int Heuristic(int x1, int y1, int x2, int y2);

    bool CheckValidCell(int x, int y, vector<vector<State>> &grid);

    void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid);

    void ExpandNeighbors(const vector<int> &current, int goat[2], vector<vector<int>> &openlist, vector<vector<State>> &grid);

    vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);

    string CellString(State cell);

    void PrintMap(const vector<vector<State>> map);

}
