#include <iostream>
using namespace std;

// 0->pathway
// 1->wall
// 2->exit
// 3->treasure
const int row = 5;
const int col = 5;

bool reached = false;
bool gotTreasure = false;

int maze[row][col] = {
    0, 1, 0, 0, 2,
    0, 0, 0, 1, 0,
    0, 3, 1, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0};
int visited[row][col] = {0};


int path[row * col][2];
int path_index = 0;

void find_paths_with_treasures(int start_row, int start_col)
{
   
    if (start_row < 0 || start_row >= row || start_col < 0 || start_col >= col)
        return;

    // If already visited or it's a wall
    if (visited[start_row][start_col] || maze[start_row][start_col] == 1)
        return;

    // Mark the cell as visited
    visited[start_row][start_col] = 1;
    path[path_index][0] = start_row;
    path[path_index][1] = start_col;
    path_index++;
    // path[path_index++] = make_pair(start_row, start_col);

    // Check if it's the treasure
    if (maze[start_row][start_col] == 3)
        gotTreasure = true;

    // Check if it's the exit and we have the treasure
    if (maze[start_row][start_col] == 2 && gotTreasure)
    {
        reached = true;
        return;
    }

    // Explore all four directions
    if (!reached)
        find_paths_with_treasures(start_row + 1, start_col);
    if (!reached)
        find_paths_with_treasures(start_row - 1, start_col);
    if (!reached)
        find_paths_with_treasures(start_row, start_col + 1);
    if (!reached)
        find_paths_with_treasures(start_row, start_col - 1);

    // Backtrack
    if (!reached)
    {
        path_index--;
        visited[start_row][start_col] = 0;
    }
}

int main()
{
    int start_row = 1, start_col = 0;
    find_paths_with_treasures(start_row, start_col);

    if (reached)
    {
        cout << "Reached the exit with treasure!" << endl;
        cout << "Path: ";
        for (int i = 0; i < path_index; ++i)
        {
            cout << "(" << path[i][0] << "," << path[i][1] << ")";
            if (i < path_index - 1)
                cout << " -> ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}