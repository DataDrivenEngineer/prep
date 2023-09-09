#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

bool checkInclusion(string s1, string s2)
{
  if (s1.size() > s2.size())
  {
    return false;
  }
  unordered_map<char, int> m;
  int matches = 0;
  for (auto& c : s1)
  {
    m[c]++;
  }
  int l = 0;
  unordered_map<char, int> m2;
  for (int i = 0; i < s1.size() - 1; i++)
  {
    m2[s2[i]]++;
    if (m.find(s2[i]) != m.end() && m[s2[i]] >= m2[s2[i]])
    {
      matches++;
    }
  }
  for (int r = s1.size() - 1; r < s2.size(); r++)
  {
    m2[s2[r]]++;
    if (m.find(s2[r]) != m.end() && m[s2[r]] >= m2[s2[r]])
    {
      matches++;
    }
    if (matches == s1.size())
    {
      return true;
    }
    else
    {
      if (m.find(s2[l]) != m.end() && m[s2[l]] >= m2[s2[l]])
      {
	matches--;
      }
      m2[s2[l]]--;
      l++;
    }
  }
  return false;
}

int main(int argc, char **argv)
{
  string s1 = "adc";
  string s2 = "dcda";
//  string s1 = "ab";
//  string s2 = "eidbaooo";
//  string s2 = "eidboaoo";
//  string s1 = "hello";
//  string s2 = "ooolleoooleh";
//  string s1 = "ky";
//  string s2 = "ainwkckifykxlribaypk";
  bool res = checkInclusion(s1, s2);
  printf("%d\n", res);
  return 0;
}
