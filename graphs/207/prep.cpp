#include <stdio.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool dfs(int i, unordered_map<int, vector<int>>& m, unordered_set<int>& s)
{
  if (s.count(i))
  {
    return false;
  }
  if (m[i].size() == 0)
  {
    return true;
  }
  s.insert(i);
  for (auto& pre : m[i])
  {
    if (!dfs(pre, m, s))
    {
      return false;
    }
  }
  m[i] = {};
  s.erase(i);
  return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
  unordered_map<int, vector<int>> m;
  for (auto& p : prerequisites)
  {
    m[p[0]].push_back(p[1]);
  }
  unordered_set<int> s;
  for (int i = 0; i < numCourses; i++)
  {
    if (!dfs(i, m, s))
    {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  int nc = 2;
  vector<vector<int>> pre = { {1,0}, {0,1} };
  bool res = canFinish(nc, pre);
  printf("%d\n", res);
  return 0;
}
