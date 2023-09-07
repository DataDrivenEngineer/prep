#include <stdio.h>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
  vector<int> out;
  int i = 0;
  int j = numbers.size() - 1;
  while (i <= j)
  {
    if (numbers[i] + numbers[j] == target)
    {
      out.insert(out.begin(), { i + 1, j + 1});
      return out;
    }
    else if (numbers[i] + numbers[j] < target)
    {
      i++;
    }
    else
    {
      j--;
    }
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = {2,7,11,15};
  int target = 9;
  vector<int> res = twoSum(nums, target);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
