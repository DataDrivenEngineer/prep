#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
  vector<int> v;
  v.reserve(2);
  unordered_map<int, int> m;

  for (int i = 0; i < nums.size(); ++i)
  {
    auto it = m.find(target - nums[i]);
    if (it != m.end())
    {
      v.push_back(it->second);
      v.push_back(i);
      break;
    }
    else
    {
      m[nums[i]] = i;
    }
  }
  return v;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 2,7,11,15 };
  int target = 9;
  vector<int> r = twoSum(nums, target);
  for (auto& v : r)
  {
    printf("%d ", v);
  }
  return 0;
}
