#include <stdio.h>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evaluate(vector<string> in)
{
  stack<string> st;
  st.push(in[0]);
  for (int i = 1; i < in.size(); i++)
  {
    if (in[i].compare(string("*")) == 0)
    {
      int r = stoi(st.top());
      st.pop();
      int l = stoi(st.top());
      st.pop();
      st.push(to_string(l * r));
    }
    else if (in[i].compare(string("/")) == 0)
    {
      int r = stoi(st.top());
      st.pop();
      int l = stoi(st.top());
      st.pop();
      st.push(to_string(l / r));
    }
    else if (in[i].compare(string("+")) == 0)
    {
      int r = stoi(st.top());
      st.pop();
      int l = stoi(st.top());
      st.pop();
      st.push(to_string(l + r));
    }
    else if (in[i].compare(string("-")) == 0)
    {
      int r = stoi(st.top());
      st.pop();
      int l = stoi(st.top());
      st.pop();
      st.push(to_string(l - r));
    }
    else
    {
      st.push(in[i]);
    }
  }
  return stoi(st.top());
}

int main(int argc, char **argv)
{
//  vector<string> in = {"2","1","+","3","*"};
  vector<string> in = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  int res = evaluate(in);
  printf("%d\n", res);
  return 0;
}
