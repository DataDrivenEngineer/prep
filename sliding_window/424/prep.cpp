#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k)
{
  int out = 0;
  unordered_map<char, int> m;
  int l = 0;
  for (int r = 0; r < s.size(); r++)
  {
    m[s[r]]++;
    int mostFreq = 0;
    for (const auto& it : m)
    {
      if (it.second > mostFreq)
      {
	mostFreq = it.second;
      }
    }
    int windowLen = r - l + 1;
    if (windowLen - mostFreq <= k)
    {
      out = windowLen;
    }
    else
    {
      m[s[l]]--;
      l++;
    }
  }
  return out;
}

int main(int argc, char **argv)
{
//  string s = "AABABBA";
//  int k = 1;
  string s = "ABAB";
  int k = 2;
  int res = characterReplacement(s, k);
  printf("%d\n", res);
  return 0;
}
