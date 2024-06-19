#include <stdio.h>
#include <vector>

using namespace std;

int jumpGame2(vector<int>& nums)
{
  int res = 0;
  int l = 0;
  int r = 0;
  while (r != nums.size() - 1)
  {
    res++;
    int cur = nums[l];
    while (cur > 0)
    {
      r = max(l + cur, r);
      cur--;
    }
    l++;
  }
  return res;
}

int main(int argc, char **argv)
{
//  vector<int> nums {2,3,1,1,4};
  vector<int> nums {2,3,0,1,4};
  int r = jumpGame2(nums);
  printf("%d", r);
  return 0;
}
