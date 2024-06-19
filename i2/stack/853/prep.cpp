#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

int carFleets(vector<int> p, vector<int> s, int target)
{
  unordered_map<int,int> m;
  for (int i = 0; i < p.size(); i++)
  {
    m[p[i]] = (target - p[i]) / s[i];
  }
  sort(p.begin(), p.end(), greater<int>());

  stack<int> st;
  st.push(p[0]);

  for (int i = 1; i < p.size(); i++)
  {
    if (m[st.top()] < m[p[i]])
    {
      st.push(p[i]);
    }
  }

  return st.size();
}

int main(int argc, char **argv)
{
//  int target = 12;
//  vector<int> p = { 10,8,0,5,3 };
//  vector<int> s = {2,4,1,1,3};
  int target = 100;
  vector<int> p = {0,2,4};
  vector<int> s = {4,2,1};
  int r = carFleets(p, s, target);
  printf("%d", r);
  return 0;
}
