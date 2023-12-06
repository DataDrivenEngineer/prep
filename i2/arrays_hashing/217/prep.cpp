#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
  unordered_set<int> s;
  for (auto n : nums)
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
  vector<int> v = {1,1,1,3,3,4,3,2,4,2};
  bool result = containsDuplicate(v);
  printf("%d\n", result);
  return 0;
}
