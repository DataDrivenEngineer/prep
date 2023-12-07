#include <stdio.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct State
{
  int n;
  int cp;
  string s;
};

vector<string> generateParenthesis(int n)
{
  vector<string> res;

  stack<State> st;
  st.push({ n, 0, string("")});

  while (!st.empty())
  {
    State state = st.top();
    st.pop();

    if (state.s.size() == n * 2)
    {
      res.push_back(state.s);
    }

    if (state.n > 0)
    {
      st.push({ state.n - 1, state.cp, state.s + "(" });
    }

    int currentlyOpenedParentheses = n - state.n;
    if (state.cp < currentlyOpenedParentheses)
    {
      st.push({ state.n, state.cp + 1, state.s + ")" });
    }
  }

  return res;
}

int main(int argc, char **argv)
{
  int n = 3;
  vector<string> r = generateParenthesis(n);
  for (auto& s : r)
  {
    printf("%s\n", s.c_str());
  }
  return 0;
}
