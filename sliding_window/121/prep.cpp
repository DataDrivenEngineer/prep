#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int maxProfit(vector<int>& prices)
{
  int max = INT_MIN;
  int l = 0;
  int r = 1;
  while (r < prices.size() && l < r)
  {
    int curProfit = prices[r] - prices[l];
    if (curProfit > max)
    {
      max = curProfit;
    }
    if (curProfit < 0)
    {
      l = r;
    }
    r++;
  }
  if (max < 0)
  {
    return 0;
  }
  else
  {
    return max;
  }
}

int main(int argc, char **argv)
{
  vector<int> in = { 7,1,5,3,6,4 };
  int res = maxProfit(in);
  printf("%d\n", res);
  return 0;
}
