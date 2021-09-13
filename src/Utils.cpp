#include "Utils.h"

namespace Utils
{
    // Change the data character to an image
    vector<State> ParseLine(string line)
    {
        istringstream sline(line);
        int n;
        char c;
        vector<State> row;

        while (sline >> n >> c && c == ',')
        {
            if (n == 0)
            {
                row.push_back(State::kEmpty);
            }
            else
            {
                row.push_back(State::kObstacle);
            }
        }
        return row;
    }

    // Read the file from the map
    vector<vector<State>> ReadMapFile(string path)
    {
        ifstream file(path);
        vector<vector<State>> board{};

        if (file)
        {
            string line;
            while (getline(file, line))
            {
                vector<State> row = ParseLine(line);
                board.push_back(row);
            }
        }
        return board;
    }

    // compare the F values of two cells
    bool Compare(const vector<int> a, const vector<int> b)
    {
        int f1 = a[2] + a[3];
        int f2 = b[2] + b[3];

        return f1 > f2;
    }

    void CellSort(vector<vector<int>> *v)
    {
        sort(v->begin(), v->end(), Compare);
    }

    //==============================================================================================
    // Calculate the manhattan distance
    int Heuristic(int x1, int y1, int x2, int y2)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    }

    bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
    {
        bool on_grid_x = (x >= 0 && x < grid.size());
        bool on_grid_y = (y >= 0 && y < grid[0].size());

        if (on_grid_x && on_grid_y)
        {
            return grid[x][y] == State::kEmpty;
        }
        return false;
    }

    // Add node to the open list and mark it as open
    void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openlist, vector<vector<State>> &grid)
    {
        openlist.push_back(vector<int>{x, y, g, h});
        grid[x][y] = State::kClosed;
    }

    void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid)
    {
        // get the current node
        int x = current[0];
        int y = current[1];
        int g = current[2];

        // loop through nodes potential neighbors
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + delta[i][0];
            int y2 = y + delta[i][1];

            // verify if the potential neighbors x2 and y2 are not kClosed and is not out of the board
            if (CheckValidCell(x2, y2, grid))
            {
                // increment g value and add neighbors to open list
                int g2 = g + 1;
                int h2 = Heuristic(x2, y2, goal[0], goal[1]);
                AddToOpen(x2, y2, g2, h2, openlist, grid);
            }
        }
    }

    // Implement A* Pathfinding
    vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
    {
        vector<vector<int>> open{};
        // initialize the starting node
        int x = init[0];
        int y = init[1];
        int g = 0;
        int h = Heuristic(x, y, goal[0], goal[1]);
        AddToOpen(x, y, g, h, open, grid);

        while (open.size() > 0)
        {
            // Get the next node
            CellSort(&open);
            auto current = open.back();
            open.pop_back();
            x = current[0];
            y = current[1];
            grid[x][y] = State::kPath;

            // verify if the expansion is done
            if (x == goal[0] && y == goal[1])
            {
                grid[init[0]][init[1]] = State::kStart;
                grid[goal[0]][goal[1]] = State::kFinish;
                return grid;
            }

            // if we are not done, expand the search to current neighbors nodes
            ExpandNeighbors(current, goal, open, grid);
        }

        cout << "Place holder until I implement the code\n";
        return vector<vector<State>>{};
    }
    //==============================================================================================

    string CellString(State cell)
    {
        switch (cell)
        {
        case State::kObstacle:
            return "⛰️   ";
        case State::kPath:
            return "🚗   ";
        case State::kStart:
            return "🚦   ";
        case State::kFinish:
            return "🏁   ";
        default:
            return "0   ";
        }
    }

    // Read map and change the map numbers to pictures
    void PrintMap(const vector<vector<State>> map)
    {
        for (int i = 0; i < map.size(); i++)
        {
            for (int j = 0; j < map[i].size(); j++)
            {
                cout << CellString(map[i][j]);
            }
            cout << endl;
        }
    }
}
