#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void combinationSumRecursive(vector<vector<int>>& out, vector<int>& candidates, int target, vector<int> curr, int cs, int ci)
{
  if (cs < target)
  {
    for (int i = ci; i < candidates.size(); i++)
    {
      if (cs + candidates[i] <= target)
      {
	curr.push_back(candidates[i]);
	combinationSumRecursive(out, candidates, target, curr, cs + candidates[i], i);
	curr.pop_back();
      }
    }
  }
  else if (cs == target)
  {
    out.push_back(curr);
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
  vector<vector<int>> out;
  combinationSumRecursive(out, candidates, target, {}, 0, 0);
  return out;
}

int main(int argc, char **argv)
{
  vector<int> candidates = { 2,3,6,7 };
  int target = 7;
  vector<vector<int>> res = combinationSum(candidates, target);
  for (auto& v : res)
  {
    for (auto& n : v)
    {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
