#include <stdio.h>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> nums)
{
  vector<int> out;
  vector<int> prefix = {nums[0]};
  for (int i = 1; i < nums.size(); ++i)
  {
    prefix.push_back(nums[i] * prefix[i - 1]);
  }
  vector<int> postfix = vector<int>(nums.size());
  postfix[nums.size() - 1] = nums[nums.size() - 1];
  for (int i = nums.size() - 2; i >= 0; i--)
  {
    postfix[i] = postfix[i + 1] * nums[i];
  }
  out.push_back(postfix[1]);
  for (int i = 1; i < nums.size() - 1; i++)
  {
    out.push_back(prefix[i - 1] * postfix[i + 1]);
  }
  out.push_back(prefix[nums.size() - 2]);
  return out;
}

vector<int> productExceptSelfConstantSpace(vector<int> nums)
{
  vector<int> out;
  for (int i = 0; i < nums.size(); i++)
  {
    int runningSum = 1;
    for (int j = 0; j < nums.size(); j++)
    {
      if (i == j) continue;
      runningSum *= nums[j];
    }
    out.push_back(runningSum);
  }
  return out;
}

int main(int argc, char **argv)
{
//  vector<int> nums = {1, 2, 3, 4};
  vector<int> nums = {-1,1, 0, -3, 3};
  vector<int> res = productExceptSelfConstantSpace(nums);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
