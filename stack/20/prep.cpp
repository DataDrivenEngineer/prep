#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
  if (s.size() > 0)
  {
    stack<char> st;
    for (auto& c : s)
    {
      if (c == '(' || c == '[' || c == '{')
      {
	st.push(c);
      }
      else
      {
	if (!st.empty())
	{
	  char fromSt = st.top();
	  if ((c == ')' && fromSt != '(') || (c == ']' && fromSt != '[') || (c == '}' && fromSt != '{'))
	  {
	    return false;
	  }
	  st.pop();
	}
	else
	{
	  return false;
	}
      }
    }
  }
  return true;
}

int main(int argc, char **argv)
{
//  string s = "()[]{}";
  string s = "()";
//  string s = "(]";
  bool res = isValid(s);
  printf("%d\n", res);
  return 0;
}
