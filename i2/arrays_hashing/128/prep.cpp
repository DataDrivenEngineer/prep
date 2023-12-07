#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutiveSequence(vector<int> nums)
{
  unordered_set<int> s(nums.begin(), nums.end());
  int tmpLen = 1;
  int maxLen = 1;

  for (auto n : nums)
  {
    if (!s.count(n - 1))
    {
      tmpLen = 1;
      while (s.count(n + 1))
      {
	tmpLen++;
	n++;
      }

      if (tmpLen > maxLen)
      {
	maxLen = tmpLen;
      }
    }
  }

  return maxLen;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 100,4,200,1,3,2 };
  int r = longestConsecutiveSequence(nums);
  printf("%d\n", r);
  return 0;
}
