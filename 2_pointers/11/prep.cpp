#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int mostWater(vector<int> nums)
{
  int out = INT_MIN;
  auto l = nums.begin();
  auto r = nums.end();
  while (l < r)
  {
    int vol = max(*l, *r) * (r - l - 1);
    if (vol > out)
    {
      out = vol;
    }
    if (*l < *r)
    {
      l++;
    }
    else
    {
      r--;
    }
  }
  return out;
}

int main(int argc, char **argv)
{
//  vector<int> nums = {1,8,6,2,5,4,8,3,7};
  vector<int> nums = {1,1};
  int res = mostWater(nums);
  printf("%d\n", res);
  return 0;
}
