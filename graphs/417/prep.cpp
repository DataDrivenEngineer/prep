#include <stdio.h>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& heights, vector<int>& s, int i, int j, int ph)
{
  if (i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size() && s[i * heights[0].size() + j] && heights[i][j] >= ph)
  {
    s[i * heights[0].size() + j] = 0;
    dfs(heights, s, i + 1, j, heights[i][j]);
    dfs(heights, s, i - 1, j, heights[i][j]);
    dfs(heights, s, i, j + 1, heights[i][j]);
    dfs(heights, s, i, j - 1, heights[i][j]);
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
  vector<vector<int>> out;
  vector<int> p(heights.size() * heights[0].size(), 1);
  vector<int> a(heights.size() * heights[0].size(), 1);
  for (int j = 0; j < heights[0].size(); j++)
  {
    dfs(heights, a, heights.size() - 1, j, heights[heights.size() - 1][j]);
    dfs(heights, p, 0, j, heights[0][j]);
  }
  for (int i = 0; i < heights.size(); i++)
  {
    dfs(heights, a, i, heights[0].size() - 1, heights[i][heights[0].size() - 1]);
    dfs(heights, p, i, 0, heights[i][0]);
  }
  for (int i = 0; i < p.size(); i++)
  {
    if (p[i] == 0 && a[i] == 0)
    {
      out.push_back({ i / (int) heights[0].size(), i % (int) heights[0].size() });
    }
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<vector<int>> heights = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
  vector<vector<int>> res = pacificAtlantic(heights);
  for (auto& v : res)
  {
    for (auto& n : v)
    {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
