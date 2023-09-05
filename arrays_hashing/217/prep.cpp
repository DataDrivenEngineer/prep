#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> nums)
{
  unordered_set<int> s = unordered_set<int>();
  for (auto& n : nums)
  {
    if (s.count(n))
    {
      return true;
    }
    s.insert(n);
  }
  return false;
}

int main(int argc, char **argv)
{
  vector<int> nums = {1, 2, 3, 1};

  printf("result: %d\n", containsDuplicate(nums));
  return 0;
}
