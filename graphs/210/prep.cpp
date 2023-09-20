#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool dfs(vector<int>& out, unordered_set<int>& s, unordered_map<int, vector<int>>& m, int i)
{
  if (s.count(i))
  {
    if (m[i].size() > 0)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  else if (m[i].size() == 0)
  {
    s.insert(i);
    out.push_back(i);
    return true;
  }
  else
  {
    s.insert(i);
    for (auto& pre : m[i])
    {
      bool isValid = dfs(out, s, m, pre);
      if (!isValid)
      {
	return false;
      }
    }
    m[i] = {};
    out.push_back(i);
    return true;
  }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
  vector<int> out;
  unordered_map<int, vector<int>> m;
  for (auto& pre : prerequisites)
  {
    m[pre[0]].push_back(pre[1]);
  }
  unordered_set<int> s;
  for (int i = 0; i < numCourses; i++)
  {
    bool isValid = dfs(out, s, m, i);
    if (!isValid)
    {
      return {};
    }
  }
  return out;
}

int main(int argc, char **argv)
{
//  int nc = 2;
//  vector<vector<int>> pre = { { 1,0 } };
//  int nc = 4;
//  vector<vector<int>> pre = { { 1,0 }, { 2,0 }, { 3,1 }, { 3,2 }};
  int nc = 1;
  vector<vector<int>> pre = {};
  vector<int> res = findOrder(nc, pre);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
