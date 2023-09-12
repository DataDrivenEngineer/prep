#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int getMinRecursive(vector<int> nums, int l, int r)
{
  if (l > r)
  {
    return INT_MIN;
  }
  int mid = l + (r - l) / 2;
  if (l == r)
  {
    return nums[l];
  }
  if (nums[mid] > nums[l] && nums[mid] > nums[r])
  {
    return nums[mid + 1];
  }
  if (nums[mid] > nums[r])
  {
    return getMinRecursive(nums, mid + 1, r);
  }
  else
  {
    return getMinRecursive(nums, 0, mid - 1);
  }
}

int getMin(vector<int> nums)
{
  return getMinRecursive(nums, 0, nums.size() - 1);
}

int main(int argc, char **argv)
{
//  vector<int> nums = { 3,4,5,1,2};
//  vector<int> nums = { 4,5,6,7,0,1,2 };
  vector<int> nums = {11,13,15,17};
  int res = getMin(nums);
  printf("%d\n", res);
  return 0;
}
