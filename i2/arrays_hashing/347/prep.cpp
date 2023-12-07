#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFreq(vector<int> nums, int k)
{
  unordered_map<int, int> m;
  vector<vector<int>> freq(nums.size() + 1);

  for (auto n : nums)
  {
    m[n]++;
  }

  for (auto it : m)
  {
    freq[it.second].push_back(it.first);
  }

  vector<int> res;
  res.reserve(k);

  for (int i = freq.size() - 1; i >= 0; i--)
  {
    for (auto n : freq[i])
    {
      if (k-- > 0)
      {
	res.push_back(n);
      }
    }
}

  return res;
}

int main(int argc, char **argv)
{
//  vector<int> nums = { 1,1,1,2,2,3 };
  vector<int> nums = { 1 };
  int k = 1;
  vector<int> res = topKFreq(nums, k);
  for (auto n : res)
  {
    printf("%d ", n);
  }
  return 0;
}
