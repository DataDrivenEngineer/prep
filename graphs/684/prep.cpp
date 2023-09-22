#include <stdio.h>
#include <vector>

using namespace std;

int find(int val, vector<int>& parent)
{
  if (parent[val] == val)
  {
    return val;
  }
  int par = find(parent[val], parent);
  parent[val] = par;
  return par;
}

void doUnion(int one, int two, vector<int>& parent, vector<int>& rank)
{
  int po = find(one, parent);
  int pt = find(two, parent);
  if (rank[po] < rank[pt])
  {
    parent[po] = pt;
  }
  else if (rank[po] > rank[pt])
  {
    parent[pt] = po;
  }
  else
  {
    parent[po] = pt;
    rank[pt]++;
  }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
  vector<int> parent;
  for (int i = 0; i < edges.size() + 1; i++)
  {
    parent.push_back(i);
  }
  vector<int> rank(parent.size(), 1);
  for (auto& e : edges)
  {
    if (find(e[0], parent) == find(e[1], parent))
    {
      return e;
    }
    doUnion(e[0], e[1], parent, rank);
  }
  return {};
}

int main(int argc, char **argv)
{
  vector<vector<int>> e = { {1,2},{1,3},{2,3} };
//  vector<vector<int>> e = { {1,2},{2,3},{3,4},{1,4},{1,5} };
  vector<int> res = findRedundantConnection(e);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
