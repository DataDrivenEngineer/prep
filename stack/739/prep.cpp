#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

typedef struct
{
  int index;
  int val;
} State;

vector<int> dailyTemperatures(vector<int> in)
{
  vector<int> out = vector<int>(in.size());
  stack<State> st;
  st.push({ 0, in[0] });
  for (int i = 1; i < in.size(); i++)
  {
    while (!st.empty() && in[i] > st.top().val)
    {
      out[st.top().index] = i - st.top().index;
      st.pop();
    }
    st.push({ i, in[i] });
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<int> in = {73,74,75,71,69,72,76,73};
//  vector<int> in = {30, 40, 50, 60};
//  vector<int> in = {30,60,90};
  vector<int> res = dailyTemperatures(in);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
