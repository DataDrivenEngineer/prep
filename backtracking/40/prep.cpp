#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void combinationSum2Recursive(vector<vector<int>>& out, vector<int>& candidates, int target, int i, int cs, vector<int> curr)
{
  if (cs < target && i < candidates.size())
  {
    if (cs + candidates[i] <= target)
    {
      curr.push_back(candidates[i]);
      combinationSum2Recursive(out, candidates, target, i + 1, cs + candidates[i], curr);
      curr.pop_back();
    }
    i++;
    while (i < candidates.size() && candidates[i] == candidates[i - 1])
    {
      i++;
    }
    combinationSum2Recursive(out, candidates, target, i, cs, curr);
  }
  else if (cs == target)
  {
    out.push_back(curr);
  }
}

typedef struct
{
  int i;
  int cs;
  vector<int> curr;
} State;

vector<vector<int>> combinationSum2Iterative(vector<int>& candidates, int target)
{
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> out;
  stack<State> st;
  st.push({ 0, 0, {} });
  while (!st.empty())
  {
    State s = st.top();
    st.pop();
    if (s.cs < target && s.i < candidates.size())
    {
      if (s.cs + candidates[s.i] <= target)
      {
	s.curr.push_back(candidates[s.i]);
	st.push({ s.i + 1, s.cs + candidates[s.i], s.curr });
	s.curr.pop_back();
      }
      s.i++;
      while (s.i < candidates.size() && candidates[s.i] == candidates[s.i - 1])
      {
	s.i++;
      }
      st.push({ s.i, s.cs, s.curr });
    }
    else if (s.cs == target)
    {
      out.push_back(s.curr);
    }
  }
  return out;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
  // recursive
//  vector<vector<int>> out;
//  sort(candidates.begin(), candidates.end());
//  combinationSum2Recursive(out, candidates, target, 0, 0, {});
//  return out;
  
  // iterative
  return combinationSum2Iterative(candidates, target);
}

int main(int argc, char **argv)
{
  vector<int> candidates = { 10,1,2,7,6,1,5 };
  int target = 8;
  vector<vector<int>> res = combinationSum2(candidates, target);
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
