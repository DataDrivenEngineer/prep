#include <stdio.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Recursive start
void generateRecursiveBacktracking(vector<string>& out, string s, int n, int co, int cc)
{
  if ((co == n) && (cc == n))
  {
    out.push_back(s);
    return;
  }
  if (cc < co)
  {
    generateRecursiveBacktracking(out, s + ")", n, co, cc + 1);
  }
  if (co < n)
  {
    generateRecursiveBacktracking(out, s + "(", n, co + 1, cc);
  }
}
// Recursive end

// Iterative start
typedef struct
{
  int co;
  int cc;
  string s;
} State;

void generateIterativeBacktracking(vector<string>& out, int n)
{
  stack<State> st;
  st.push({ 0, 0, string("")});
  while (!st.empty())
  {
    State state = st.top();
    st.pop();
    if (state.cc == n && state.co == n)
    {
      out.push_back(state.s);
    }
    if (state.cc < state.co)
    {
      st.push({ state.co, state.cc + 1, state.s + ")" });
    }
    if (state.co < n)
    {
      st.push({ state.co + 1, state.cc, state.s + "(" });
    }
  }
}
// Iterative end

vector<string> generateParentheses(int n)
{
  vector<string> out;
  string s = string("");
//  generateRecursiveBacktracking(out, s, n, 0, 0);
  generateIterativeBacktracking(out, n);
  return out;
}

int main(int argc, char **argv)
{
  int n = 3;
  vector<string> res = generateParentheses(n);
  for (auto& s : res)
  {
    printf("%s\n", s.c_str());
  }
  return 0;
}
