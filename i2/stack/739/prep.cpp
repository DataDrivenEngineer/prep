#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

struct State
{
  int i;
  int v;
};

vector<int> dailyTemperatures(vector<int>& temperatures)
{
  vector<int> r(temperatures.size());
  stack<State> s;
  s.push({ 0, temperatures[0] });

  for (int i = 1; i < temperatures.size(); i++)
  {
    while (!s.empty() && s.top().v < temperatures[i])
    {
      State st = s.top();
      s.pop();
      r[st.i] = i - st.i;
    }

    s.push({ i, temperatures[i] });
  }

  return r;
}

int main(int argc, char **argv)
{
//  vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
//  vector<int> temperatures = {30,40,50,60};
  vector<int> temperatures = {30,60,90};
  vector<int> res = dailyTemperatures(temperatures);
  for (auto n : res)
  {
    printf("%d ", n);
  }
  return 0;
}
