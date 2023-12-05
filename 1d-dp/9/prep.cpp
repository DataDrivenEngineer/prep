#include <stdio.h>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
  int ml = 0, mr = 0;
  int maxLen = 0;
  int l, r;
  for (int i = 0; i < s.size(); i++)
  {
    l = r = i;
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
      if (r - l + 1 > maxLen)
      {
	ml = l;
	mr = r;
	maxLen = r - l + 1;
      }
      l--;
      r++;
    }
    l = i;
    r = i + 1;
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
      if (r - l + 1 > maxLen)
      {
	ml = l;
	mr = r;
	maxLen = r - l + 1;
      }
      l--;
      r++;
    }
  }
  return s.substr(ml, mr - ml + 1);
}

int main(int argc, char **argv)
{
//  string s = "babad";
//  string s = "bb";
//  string s = "abcba";
//  string s = "ac";
  string s = "abb";
  string res = longestPalindrome(s);
  printf("%s\n", res.c_str());
  return 0;
}
