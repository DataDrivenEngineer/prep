#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
  vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++)
  {
    for (auto& c : coins)
    {
      if (i - c >= 0)
      {
	dp[i] = min(dp[i], 1 + dp[i - c]);
      }
    }
  }
  return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main(int argc, char **argv)
{
//  vector<int> c = { 1,2,5 };
//  int amount = 11;
//  vector<int> c = {2};
//  int amount = 4;
  vector<int> c = {186,419,83,408};
  int amount = 6249;
//  vector<int> c = {2};
//  int amount = 3;
//  vector<int> c = {1};
//  int amount = 0;
  int res = coinChange(c, amount);
  printf("%d\n", res);
  return 0;
}
