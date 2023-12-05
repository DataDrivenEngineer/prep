#include <stdio.h>
#include <string>

using namespace std;

int countSubstrings(string s)
{
  int res = 0;
  int l, r;
  for (int i = 0; i < s.size(); i++)
  {
    l = r = i;
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
      res++;
      l--;
      r++;
    }
    l = i;
    r = i + 1;
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
      res++;
      l--;
      r++;
    }
  }
  return res;
}

int main(int argc, char **argv)
{
//  string s = "abc";
  string s = "aaa";
  int res = countSubstrings(s);
  printf("%d\n", res);
  return 0;
}
