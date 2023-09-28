#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums)
{
  if (nums.size() == 1) return nums[0];
  vector<int> dpOne(nums.size() + 1, 0);
  vector<int> dpTwo(nums.size() + 1, 0);
  for (int k = 2; k < dpOne.size(); k++)
  {
    dpOne[k] = max(dpOne[k - 1], nums[k - 2] + dpOne[k - 2]);
  }
  for (int k = 2; k < dpTwo.size(); k++)
  {
    dpTwo[k] = max(dpTwo[k - 1], nums[k - 1] + dpTwo[k - 2]);
  }
  return dpOne[dpOne.size() - 1] > dpTwo[dpTwo.size() - 1] ? dpOne[dpOne.size() - 1] : dpTwo[dpTwo.size() - 1];
}

int main(int argc, char **argv)
{
//  vector<int> nums = { 2,3,2 };
//  vector<int> nums = {1,2,3,1};
//  vector<int> nums = {1,2,3};
//  vector<int> nums = {2,1,1,1};
  int res = rob(nums);
  printf("%d\n", res);
  return 0;
}
