#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct State
{
  int i;
  int v;
};

int largestRectangleArea(vector<int>& heights)
{
  stack<State> s;
  int maxSquare = 0;

  for (int i = 0; i < heights.size(); i++)
  {
    int start = i;
    while (!s.empty() && heights[i] < s.top().v)
    {
      State st = s.top();
      s.pop();
      maxSquare = max(maxSquare, st.v * (i - st.i));
      start = st.i;
    }
    s.push({ start, heights[i] });
  }

  while (!s.empty())
  {
    State st = s.top();
    s.pop();
    maxSquare = max(maxSquare, st.v * ((int) heights.size() - st.i));
  }

  return maxSquare;
}

int main(int argc, char **argv)
{
//  vector<int> heights = { 2,1,5,6,2,3 };
//  vector<int> heights = {2,4};
//  vector<int> heights = {1,1};
  vector<int> heights = {2,1,0, 2};
  int r = largestRectangleArea(heights);
  printf("%d", r);
  return 0;
}
