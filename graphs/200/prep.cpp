#include <stdio.h>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int& res, int i, int j, vector<int>& s, bool ii)
{
  if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && s[i * grid[0].size() + j])
  {
    s[i * grid[0].size() + j] = 0;
    if (grid[i][j] == '1')
    {
      if (!ii)
      {
	ii = true;
	res++;
      }
      dfs(grid, res, i + 1, j, s, ii);
      dfs(grid, res, i - 1, j, s, ii);
      dfs(grid, res, i, j + 1, s, ii);
      dfs(grid, res, i, j - 1, s, ii);
    }
  }
}

int numIslands(vector<vector<char>>& grid)
{
  int res = 0;
  vector<int> s(grid.size() * grid[0].size(), 1);
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      dfs(grid, res, i, j, s, false);
    }
  }
  return res;
}

int main(int argc, char **argv)
{
//  vector<vector<char>> grid = 
//  {
//    { '1','1','1','1','0' },
//    { '1','1','0','1','0' },
//    { '1','1','0','0','0' },
//    { '0','0','0','0','0' }
//  };
  vector<vector<char>> grid = 
  {
    { '1','1','0','0','0' },
    { '1','1','0','0','0' },
    { '0','0','1','0','0' },
    { '0','0','0','1','1' }
  };
  int res = numIslands(grid);
  printf("%d\n", res);
  return 0;
}
