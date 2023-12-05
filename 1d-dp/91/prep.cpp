#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int res = 0;

void numDecodingsRecursive(string& s, int i)
{
  if (i >= s.size())
  {
    res++;
  }
  else
  {
    if (s[i] == '0') return;
    numDecodingsRecursive(s, i + 1);
    if (i + 1 < s.size())
    {
      int n = atoi(s.substr(i, 2).c_str());
      if (n > 0 && n < 27)
      {
	numDecodingsRecursive(s, i + 2);
      }
    }
  }
}

int numDecodings(string s)
{
  if (s[0] == '0') return res;
  numDecodingsRecursive(s, 0);
  return res;
}

int main(int argc, char **argv)
{
//  string s = "12";
//  string s = "226";
//  string s = "06";
//  string s = "10";
//  string s = "2101";
  string s = "10";
  int res = numDecodings(s);
  printf("%d\n", res);
  return 0;
}
