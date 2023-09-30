#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
  vector<int> out;
  if (p.size() > s.size()) return out;
  unordered_map<char, int> m;
  for (auto& c : p)
  {
    m[c]++;
  }
  int l = 0;
  int r = 0;
  int zc = 0;
  while (r < s.size())
  {
    if (m.find(s[r]) != m.end())
    {
      int prev = m[s[r]];
      m[s[r]]--;
      if (m[s[r]] == 0)
	zc++;
      else if (prev == 0)
	zc--;
      if (zc == m.size())
      {
	out.push_back(l);
      }
    }
    r++;
    if (r - l == p.size())
    {
      if (m.find(s[l]) != m.end())
      {
	int prev = m[s[l]];
	m[s[l]]++;
	if (m[s[l]] == 0)
	  zc++;
	else if (prev == 0)
	  zc--;
	if (zc == m.size())
	{
	  out.push_back(l);
	}
      }
      l++;
    }
  }
  return out;
}

int main(int argc, char **argv)
{
//  string s = "cbaebabacd";
//  string p = "abc";
  string s = "baa";
  string p = "aa";
  vector<int> res = findAnagrams(s, p);
  for (auto& n : res)
  {
    printf("%d\n", n);
  }
  return 0;
}
