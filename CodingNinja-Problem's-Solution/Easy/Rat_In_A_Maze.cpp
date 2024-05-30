#include <bits/stdc++.h>

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &arr)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{

    // base condition
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 Choices - D, L, R, U

    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('D');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('L');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('R');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('U');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;

    if (arr[0][0] == 0)
    {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = arr;

    // initialize with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(arr, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}


// EXPLANATION :

/*

Algorithm to find all possible paths from the top-left corner to the bottom-right corner in a maze represented by a 2D grid. Let's break down the code step by step:

1. `#include <bits/stdc++.h>`: This is a directive that includes a large standard C++ library. While it's commonly used to simplify coding in competitive programming and quick coding tasks, it's not a recommended practice for production code due to potential portability and compilation issues.

2. `bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &arr)`: This function checks whether a given cell `(x, y)` is safe to visit in the maze. It returns `true` if the cell is within bounds, hasn't been visited before, and contains a value of `1`. Otherwise, it returns `false`.

3. `void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)`: This is the recursive DFS function that explores all possible paths through the maze. It takes the maze grid `arr`, its size `n`, a vector `ans` to store the found paths, the current position `(x, y)`, a 2D vector `visited` to mark visited cells, and the current path `path`.

   - The base condition checks if the current position is at the bottom-right corner of the maze. If so, it adds the current path to the `ans` vector and returns.
   
   - The current cell `(x, y)` is marked as visited in the `visited` vector.
   
   - The function explores four possible directions: down, left, right, and up. For each valid direction, it adds the corresponding direction character to the `path`, recursively calls the `solve` function for the new position, and then removes the last character from the `path` after the recursive call. This backtracking mechanism is used to explore all possible paths.
   
   - After exploring all directions from the current cell, it marks the current cell as unvisited in the `visited` vector to allow other paths to explore it.

4. `vector<string> searchMaze(vector<vector<int>> &arr, int n)`: This is the main function that initiates the maze path search.

   - It checks if the top-left corner of the maze is accessible (i.e., contains a value of `1`). If not, it returns an empty vector `ans`.
   
   - It initializes the starting position `(srcx, srcy)` at the top-left corner of the maze.
   
   - It initializes a 2D vector `visited` to keep track of visited cells. Initially, all cells are marked as unvisited (0).
   
   - It initializes an empty string `path`.
   
   - It calls the `solve` function to start exploring paths from the starting position. The found paths are stored in the `ans` vector.
   
   - Finally, it sorts the `ans` vector and returns it.

Overall, this code performs a depth-first search to explore all possible paths in a maze and returns a sorted list of these paths. Each path is represented by a sequence of characters (D for down, L for left, R for right, U for up) indicating the directions to follow from the top-left corner to the bottom-right corner of the maze.

*/