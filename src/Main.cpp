#include <iostream>

#include "Utils.h"
#include "Test.h"

using std::cin;

int main()
{
   int init[2]{0, 0};
   int goal[2]{4, 5};
   auto grid = ReadMapFile("src/map.txt");
   auto aStar = Search(grid, init, goal);
   PrintMap(aStar);

   //Test cases
   TestHeuristic();
   TestAddToOpen();
   TestCompare();
   TestSearch();
   TestCheckValidCell();
   TestExpandNeighbors();

   cin.get();
}