#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& grid, int& res, int i, int j, vector<int>& s)
{
  if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && s[i * grid[0].size() + j])
  {
    s[i * grid[0].size() + j] = 0;
    if (grid[i][j] == 1)
    {
      res++;
      dfs(grid, res, i, j - 1, s);
      dfs(grid, res, i, j + 1, s);
      dfs(grid, res, i - 1, j, s);
      dfs(grid, res, i + 1, j, s);
    }
  }
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
  int maxIsland = 0;
  int localMax = 0;
  vector<int> s(grid.size() * grid[0].size(), 1);
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      dfs(grid, localMax, i, j, s);
      if (localMax > maxIsland)
      {
	maxIsland = localMax;
      }
      localMax = 0;
    }
  }
  return maxIsland;
}

int main(int argc, char **argv)
{
  vector<vector<int>> grid = 
  {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}
  };
  int res = maxAreaOfIsland(grid);
  printf("%d\n", res);
  return 0;
}
