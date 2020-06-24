#pragma once

#include <iostream>
#include <vector>

#include "Utils.h"

using std::vector;

void PrintVector(vector<int> v);

void PrintVectorOfVectors(vector<vector<int>> v);

void PrintVectorOfVectors(vector<vector<State>> v);

void TestHeuristic();

void TestAddToOpen();

void TestCompare();

void TestSearch();

void TestCheckValidCell();

void TestExpandNeighbors();
