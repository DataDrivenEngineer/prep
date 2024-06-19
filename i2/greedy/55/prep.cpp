#include <stdio.h>
#include <vector>

using namespace std;

bool jumpGame(vector<int>& nums)
{
  int r = nums.size() - 1;
  int l = r;
  while (l >= 0)
  {
    if (nums[l] >= r - l)
    {
      r = l;
    }
    l--;
  }
  return r == 0;
}

int main(int argc, char **argv)
{
//  vector<int> nums { 2,3,1,1,4 };
  vector<int> nums {3,2,2,0,4};
  bool r = jumpGame(nums);
  printf("%d", r);
  return 0;
}
