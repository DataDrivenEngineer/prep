#include <stdio.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens)
{
  stack<string> st;
  int res = 0;
  
  for (auto& t : tokens)
  {
    if (!(t.compare("+") == 0 || t.compare("-") == 0 || t.compare("*") == 0 || t.compare("/") == 0))
    {
      st.push(t);
    }
    else
    {
      int right = atoi(st.top().c_str());
      st.pop();
      int left = atoi(st.top().c_str());
      st.pop();

      if (t.compare("+") == 0)
      {
	res = left + right;
      }
      if (t.compare("-") == 0)
      {
	res = left - right;
      }
      if (t.compare("*") == 0)
      {
	res = left * right;
      }
      if (t.compare("/") == 0)
      {
	res = left / right;
      }

      st.push(to_string(res));
    }
  }

  return atoi(st.top().c_str());
}

int main(int argc, char **argv)
{
  vector<string> tokens = { string("2"), string("1"), string("+"), string("3"), string("*") };
  int res = evalRPN(tokens);
  printf("%d", res);
  return 0;
}
