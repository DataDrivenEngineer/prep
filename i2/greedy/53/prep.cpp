#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarray(vector<int>& nums)
{
  int curr = 0;
  int res = 0;
  for (auto n : nums)
  {
    curr = max(n, n + curr);
    res = max(curr, res);
  }
  return res;
}

int main(int argc, char **argv)
{
//  vector<int> nums {-2,1,-3,4,-1,2,1,-5,4 };
//  vector<int> nums {1};
  vector<int> nums {5,4,-1,7,8};
  int r = maxSubarray(nums);
  printf("%d", r);
  return 0;
}
