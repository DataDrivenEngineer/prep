#include <stdio.h>
#include <vector>

using namespace std;

int gasStations(vector<int>& gas, vector<int>& cost)
{
  int curr = 0;
  for (int i = 0; i < gas.size(); i++)
  {
    curr = curr + gas[i] - cost[i];
  }
  int l = 0;
  int r = gas.size() - 1;
  while (l < gas.size())
  {
    curr = curr + gas[l] - cost[l];
    if (curr >= 0) {
      return l;
    }
    curr = curr - gas[l] + cost[r];
    l += 1;
    r = (r + 1) % gas.size();
  }
  return -1;
}

int main(int argc, char **argv)
{
//  vector<int> gas {1,2,3,4,5};
//  vector<int> cost {3,4,5,1,2};
  vector<int> gas {2,3,4};
  vector<int> cost {3,4,3};
  int r = gasStations(gas, cost);
  printf("%d", r);
  return 0;
}
