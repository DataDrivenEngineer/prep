#include <stdio.h>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
  int s = 0;
  int f = s;
  do
  {
    s = nums[s];
    f = nums[f];
    f = nums[f];
  } while (s != f);
  int s2 = 0;
  do
  {
    s = nums[s];
    s2 = nums[s2];
  } while (s2 != s);
  return s;
}

int main(int argc, char **argv)
{
// vector<int> in = { 1,3,4,2,2};
  vector<int> in = {2,5,9,6,9,3,8,9,7,1};
  int res = findDuplicate(in);
  printf("%d\n", res);
  return 0;
}
