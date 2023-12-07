#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
  stack<char> st;

  for (auto c : s)
  {
    if (c == '(' || c == '[' || c == '{')
    {
      st.push(c);
    }
    
    if (c == ')')
    {
      if (st.top() != '(') return false;
      st.pop();
    }

    if (c == ']')
    {
      if (st.top() != '[') return false;
      st.pop();
    }

    if (c == '}')
    {
      if (st.top() != '{') return false;
      st.pop();
    }
  }

  if (!st.empty())
  {
    return false;
  }

  return true;
}

int main(int argc, char **argv)
{
//  string s = string("()");
//  string s = string("()[]{}");
  string s = string("(]");
  bool r = isValid(s);
  printf("%d\n", r);
  return 0;
}
