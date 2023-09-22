#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minCostClimbingStairsRecursive(int i, vector<int>& cost, unordered_map<int, int>& m)
{
  if (i >= cost.size()) return 0;
  if (i == cost.size() - 1) return cost[cost.size() - 1];
  if (i == cost.size() - 2) return cost[cost.size() - 2];
  if (m.find(i) != m.end())
  {
    return m.find(i)->second;
  }
  int ml;
  int mr;
  int mc;
  if (m.find(i + 1) != m.end())
  {
    mc = m.find(i + 1)->second;
  }
  else
  {
    mc = minCostClimbingStairsRecursive(i + 1, cost, m);
    m[i + 1] = mc;
  }
  ml = cost[i] + mc;
  if (m.find(i + 2) != m.end())
  {
    mc = m.find(i + 2)->second;
  }
  else
  {
    mc = minCostClimbingStairsRecursive(i + 2, cost, m);
    m[i + 2] = mc;
  }
  mr = cost[i] + mc;
  return min(ml, mr);
}

int minCostClimbingStairs(vector<int>& cost)
{
  // DP
//  cost.push_back(0);
//  cost.push_back(0);
//  for (int i = cost.size() - 3; i >= 0; i--)
//  {
//    cost[i] = min(cost[i] + cost[i + 1], cost[i] + cost[i + 2]);
//  }
//  return min(cost[0], cost[1]);

  // memoization
  unordered_map<int, int> m;
  int ml = minCostClimbingStairsRecursive(0, cost, m);
  int mr = minCostClimbingStairsRecursive(1, cost, m);
  return min(ml, mr);
}

int main(int argc, char **argv)
{
  vector<int> in = {1,100,1,1,1,100,1,1,100,1};
//  vector<int> in = {0,1,0,0};
  int res = minCostClimbingStairs(in);
  printf("%d\n", res);
  return 0;
}
