#include "Test.h"
#include "Utils.h"

void PrintVector(vector<int> v)
{
    cout << "{";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "}\n";
}

void PrintVectorOfVectors(vector<vector<int>> v)
{
    for (auto row : v)
    {
        std::cout << "{ ";
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << "}" << std::endl;
    }
}

void PrintVectorOfVectors(vector<vector<State>> v)
{
    for (auto row : v)
    {
        std::cout << "{ ";
        for (auto col : row)
        {
            std::cout << CellString(col) << " ";
        }
        std::cout << "}" << std::endl;
    }
}

void TestHeuristic()
{
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Heuristic Function Test\n";

    if (Heuristic(1, 2, 3, 4) != 4)
    {
        std::cout << "failed\n";
        std::cout << "\n"
                  << "Heuristic(1,2,3,4) = " << Heuristic(1, 2, 3, 4) << std::endl;
        std::cout << "The correct result: 4\n\n";
    }
    else if (Heuristic(2, -1, 4, -7) != 8)
    {
        std::cout << "Test Heuristic Failed\n";
        std::cout << "\n"
                  << "Heuristic(2,-1,4,7) = " << Heuristic(2, -1, 4, 7) << std::endl;
        std::cout << "The correct result:  8\n\n";
    }
    else
    {
        std::cout << "PASSED\n";
    }
    return;
}

void TestAddToOpen()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "AddToOpen Function Test: ";
    int x = 3;
    int y = 0;
    int g = 5;
    int h = 7;
    vector<vector<int>> open{{0, 0, 2, 9}, {1, 0, 2, 2}, {2, 0, 2, 4}};
    vector<vector<int>> solution_open = open;
    solution_open.push_back(vector<int>{3, 0, 5, 7});
    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
    vector<vector<State>> solution_grid = grid;
    solution_grid[3][0] = State::kClosed;
    AddToOpen(x, y, g, h, open, grid);
    if (open != solution_open)
    {
        cout << "failed"
             << "\n";
        cout << "\n";
        cout << "Your open list is: "
             << "\n";
        PrintVectorOfVectors(open);
        cout << "Solution open list is: "
             << "\n";
        PrintVectorOfVectors(solution_open);
        cout << "\n";
    }
    else if (grid != solution_grid)
    {
        cout << "failed"
             << "\n";
        cout << "\n";
        cout << "Your grid is: "
             << "\n";
        PrintVectorOfVectors(grid);
        cout << "\n";
        cout << "Solution grid is: "
             << "\n";
        PrintVectorOfVectors(solution_grid);
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
    cout << "----------------------------------------------------------"
         << "\n";
    return;
}

void TestCompare()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "Compare Function Test\n";
    vector<int> test_1{1, 2, 5, 7};
    vector<int> test_2{1, 3, 5, 7};
    vector<int> test_3{1, 2, 5, 8};
    vector<int> test_4{1, 3, 5, 7};

    if (Compare(test_1, test_2))
    {
        cout << "failed \n";
        cout << "a = ";
        PrintVector(test_1);
        cout << "b = ";
        PrintVector(test_2);
        cout << "Compare(a,b): " << Compare(test_1, test_2) << "\n\n";
        cout << "Correct answer is: 0"
             << "\n\n";
    }
    else if (!Compare(test_3, test_4))
    {
        cout << "failed \n";
        cout << "a = ";
        PrintVector(test_3);
        cout << "b = ";
        PrintVector(test_4);
        cout << "Compare(a,b): " << Compare(test_3, test_4) << endl;
        cout << "Correct answer is: 1"
             << "\n\n";
    }
    else
    {
        cout << "U hu PASSED\n";
        cout << "------------------------------------------------------------\n";
    }
}

void TestSearch()
{
    cout << "------------------------------------------------------------\n";
    cout << "Search function test (partial): ";
    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadMapFile("src/map.txt");

    cout.setstate(std::ios_base::failbit);
    // disable cout

    auto output = Search(board, init, goal);
    cout.clear(); // Enable cout

    vector<vector<State>> solution{{State::kStart, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kClosed, State::kClosed, State::kClosed},
                                   {State::kPath, State::kObstacle, State::kClosed, State::kPath, State::kPath, State::kPath},
                                   {State::kPath, State::kPath, State::kPath, State::kPath, State::kObstacle, State::kFinish}};
    if (output != solution)
    {
        cout << "failed\n";
        cout << "Search(board, {0, 0}, {4 , 5})\n";
        cout << "Solution board: " << endl;
        PrintVectorOfVectors(solution);
        cout << "My board: " << endl;
        PrintVectorOfVectors(output);
        cout << endl;
    }
    else
    {
        cout << "TEST SEARCH PASSED\n";
        cout << "------------------------------------------------------------\n";
    }
}

void TestCheckValidCell()
{
    cout << "------------------------------------------------------------\n";
    cout << "Check valid cell function test: ";

    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};

    if (CheckValidCell(0, 0, grid))
    {
        cout << "failed\n\n";
        cout << "Test grid is: \n";
        PrintVectorOfVectors(grid);
        cout << "Cell verified: (0,0)\n";
    }
    else if (!CheckValidCell(4, 2, grid))
    {
        cout << "failed\n\n";
        cout << "Test grid is: \n";
        PrintVectorOfVectors(grid);
        cout << "Cell verified: (4,2)\n";
    }
    else
    {
        cout << "Check valid cell PASSED\n";
    }
    cout << "------------------------------------------------\n";
}

void TestExpandNeighbors()
{
    cout << "--------------------------------------------------\n";
    cout << "ExpandNeighbors Function Test: ";

    vector<int> current{4, 2, 7, 3};
    int goal[2]{4, 5};
    vector<vector<int>> open{{4, 2, 7, 3}};
    vector<vector<int>> solution_open = open;
    solution_open.push_back(vector<int>{3, 2, 8, 4});
    solution_open.push_back(vector<int>{4, 3, 8, 2});

    vector<vector<State>> grid{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                               {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};

    auto solution_grid = grid;

    solution_grid[3][2] = State::kClosed;
    solution_grid[4][3] = State::kClosed;

    ExpandNeighbors(current, goal, open, grid);
    CellSort(&open);
    CellSort(&solution_open);

    if (open != solution_open)
    {
        cout << "Test failed\n\n";
        cout << "The open list is: \n";
        PrintVectorOfVectors(open);
        cout << "Solution open list is: \n";
        PrintVectorOfVectors(solution_open);
        cout << endl;
    }
    else if (grid != solution_grid)
    {
        cout << "Test failed\n\n";
        cout << "The grid is: \n";
        PrintVectorOfVectors(grid);
        cout << "Solution grid is: \n";
        PrintVectorOfVectors(solution_grid);
        cout << endl;
    }
    else
    {
        cout << "PASSED\n";
    }
    cout << "------------------------------------------------\n";
}