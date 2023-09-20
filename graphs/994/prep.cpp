#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

struct State
{
  int i;
  int j;
  int ct;
};

void bfs(vector<vector<int>>& grid, int i, int j, int& maxTime)
{
  deque<State> dq;
  dq.push_back({ i + 1, j, 1 });
  dq.push_back({ i - 1, j, 1 });
  dq.push_back({ i, j + 1, 1 });
  dq.push_back({ i, j - 1, 1 });
  while (!dq.empty())
  {
    State st = dq.front();
    dq.pop_front();
    if (st.i >= 0 && st.i < grid.size() && st.j >= 0 && st.j < grid[0].size() && grid[st.i][st.j] == 1)
    {
      grid[st.i][st.j] = 2;
      if (st.ct > maxTime)
      {
	maxTime = st.ct;
      }
      dq.push_back({st.i + 1,st.j, st.ct + 1 });
      dq.push_back({st.i - 1,st.j, st.ct + 1 });
      dq.push_back({st.i,st.j + 1, st.ct + 1 });
      dq.push_back({st.i,st.j - 1, st.ct + 1 });
    }
  }
}

int rottenOranges(vector<vector<int>>& grid)
{
  int maxTime = 0;
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      if (grid[i][j] == 2)
      {
	bfs(grid, i, j, maxTime);
      }
    }
  }
  for (int i = 0; i < grid.size(); i++)
  {
    for (int j = 0; j < grid[0].size(); j++)
    {
      if (grid[i][j] == 1)
      {
	return -1;
      }
    }
  }
  return maxTime;
}

int main(int argc, char **argv)
{
//  vector<vector<int>> grid = { { 2,1,1 }, { 1,1,0 }, { 0,1,1 } };
//  vector<vector<int>> grid = { { 2,1,1 }, { 0,1,1 }, { 1,0,1 } };
  vector<vector<int>> grid = { { 0,2} };
  int res = rottenOranges(grid);
  printf("%d\n", res);
  return 0;
}
