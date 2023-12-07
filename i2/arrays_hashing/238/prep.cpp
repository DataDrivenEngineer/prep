#include <stdio.h>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> nums)
{
  vector<int> prefix(nums.size(), 1);
  prefix[0] = nums[0];
  vector<int> postfix(nums.size());
  postfix[nums.size() - 1] = nums[nums.size() - 1];

  for (int i = 1; i < nums.size(); i++)
  {
    prefix[i] = prefix[i - 1] * nums[i];
  }

  for (int i = nums.size() - 2; i >= 0; i--)
  {
    postfix[i] = postfix[i + 1] * nums[i];
  }

  vector<int> res(nums.size());
  res[0] = postfix[1];
  res[nums.size() - 1] = prefix[nums.size() - 2];
  for (int i = 1; i < nums.size() - 1; i++)
  {
    res[i] = prefix[i - 1] * postfix[i + 1];
  }

  return res;
}

int main(int argc, char **argv)
{
//  vector<int> nums = { 1,2,3,4 };
  vector<int> nums = {-1,1,0,-3,3};
  vector<int> res = productExceptSelf(nums);
  for (auto n : res)
  {
    printf("%d ", n);
  }
  return 0;
}
