#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
  int out = 0;
  unordered_set<char> set;
  int l = 0;
  for (int r = 0; r < s.size(); r++)
  {
    while (set.count(s[r]))
    {
      set.erase(s[l]);
      l++;
    }
    set.insert(s[r]);
    int len = r - l + 1;
    if (len > out)
    {
      out = len;
    }
  }
  return out;
}

int main(int argc, char **argv)
{
//  string s = "abcabcbb";
//  string s = "bbbbb";
  string s = "pwwkew";
  int res = lengthOfLongestSubstring(s);
  printf("%d\n", res);
  return 0;
}
