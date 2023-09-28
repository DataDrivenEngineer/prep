#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

//void robRecursive(int ci, vector<int>& nums, int& maxSum, int currSum, unordered_set<int>& s)
//{
//  if (ci == nums.size())
//  {
//    if (currSum > maxSum)
//    {
//      maxSum = currSum;
//    }
//  }
//  else if (ci < nums.size())
//  {
//    if (!s.count(ci))
//    {
//      s.insert(ci);
//      if (ci - 1 >= 0)
//      {
//	s.insert(ci - 1);
//      }
//      if (ci + 1 < nums.size())
//      {
//	s.insert(ci + 1);
//      }
//      robRecursive(ci + 1, nums, maxSum, currSum + nums[ci], s);
//      s.erase(ci);
//      s.erase(ci - 1);
//      s.erase(ci + 1);
//    }
//    robRecursive(ci + 1, nums, maxSum, currSum, s);
//  }
//}

int rob(vector<int>& nums)
{
  // bottom-up dp
  vector<int> dp(nums.size() + 2);
  for (int i = 0; i < nums.size(); i++)
  {
    dp[i + 2] = max(dp[i + 2 - 2] + nums[i], dp[i + 2 - 1]);
  }
  return dp[dp.size() - 1];

  // top-down dp
//  int maxSum = 0;
//  unordered_set<int> s;
//  robRecursive(0, nums, maxSum, 0, s);
//  return maxSum;
}

int main(int argc, char **argv)
{
//  vector<int> nums = { 2,7,9,3,1 };
  vector<int> nums = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
//  vector<int> nums = {0};
  int res = rob(nums);
  printf("%d\n", res);
  return 0;
}
