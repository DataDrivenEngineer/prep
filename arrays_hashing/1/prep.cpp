#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
  vector<int> ret;
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); ++i)
  {
    m.insert(make_pair(nums[i], i));
  }

  for (int i = 0; i < nums.size(); ++i)
  {
    auto it = m.find(target - nums[i]);
    if (it != m.end() && it->second != i)
    {
      ret.insert(ret.end(), { i, it->second });
      return ret;
    }
  }

  return ret;
}

int main(int argc, char **argv)
{
  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> res = twoSum(nums, target);
  for (int& r : res)
  {
    printf("%d ", r);
  }
  return 0;
}
