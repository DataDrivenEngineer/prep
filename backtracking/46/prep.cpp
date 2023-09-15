#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

void permuteRecursive(vector<vector<int>>& out, vector<int>& nums, unordered_set<int> s, vector<int> curr)
{
  if (curr.size() < nums.size())
  {
    for (int i = 0; i < nums.size(); i++)
    {
      if (!s.count(nums[i]))
      {
	s.insert(nums[i]);
	curr.push_back(nums[i]);
	permuteRecursive(out, nums, s, curr);
	s.erase(nums[i]);
	curr.pop_back();
      }
    }
  }
  else
  {
    out.push_back(curr);
  }
}

vector<vector<int>> permute(vector<int>& nums)
{
  vector<vector<int>> out;
  permuteRecursive(out, nums, {}, {});
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 1, 2, 3 };
  vector<vector<int>> res = permute(nums);
  for (auto& v : res)
  {
    for (auto& n : v)
    {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
