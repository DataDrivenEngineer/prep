#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
  sort(nums.begin(), nums.end());
  vector<vector<int>> out;
  for (int i = 0; i < nums.size(); i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r)
    {
      int threeSum = nums[i] + nums[l] + nums[r];
      if (threeSum > 0)
      {
	r--;
      }
      else if (threeSum < 0)
      {
	l++;
      }
      else
      {
	out.push_back({ nums[i], nums[l], nums[r] });
	l++;
	while (nums[l] == nums[l - 1] && l < r)
	{
	  l++;
	}
      }
    }
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector<vector<int>> res = threeSum(nums);
  for (auto& t : res)
  {
    for (auto& n : t)
    {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
