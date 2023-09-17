#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

void subsetsWithDupRecursive(vector<vector<int>>& out, vector<int>& nums, int i, unordered_set<int> s, vector<int> curr)
{
  if (i < nums.size())
  {
    if (!s.count(nums[i]))
    {
      curr.push_back(nums[i]);
      subsetsWithDupRecursive(out, nums, i + 1, s, curr);
      curr.pop_back();
    }
    s.insert(nums[i]);
    subsetsWithDupRecursive(out, nums, i + 1, s, curr);
    s.erase(nums[i]);
  }
  else
  {
    out.push_back(curr);
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
  vector<vector<int>> out;
  subsetsWithDupRecursive(out, nums, 0, {}, {});
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 1,2,2 };
  vector<vector<int>> res = subsetsWithDup(nums);
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
