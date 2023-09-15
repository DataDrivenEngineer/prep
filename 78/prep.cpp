#include <stdio.h>
#include <vector>

using namespace std;

void subsetsRecursive(vector<vector<int>>& out, vector<int>& nums, int i, vector<int> curr)
{
  if (i < nums.size())
  {
    subsetsRecursive(out, nums, i + 1, curr);
    curr.push_back(nums[i]);
    subsetsRecursive(out, nums, i + 1, curr);
  }
  else
  {
    out.push_back(curr);
  }
}

vector<vector<int>> subsets(vector<int>& nums)
{
  vector<vector<int>> out;
  subsetsRecursive(out, nums, 0, { });
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 1, 2, 3 };
  vector<vector<int>> res = subsets(nums);
  for (const auto& v : res)
  {
    for (const auto& n : v)
    {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
