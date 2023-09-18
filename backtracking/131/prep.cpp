#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string& s, int l, int r)
{
  while (l <= r)
  {
    if (s[l] != s[r])
    {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

void dfs(vector<vector<string>>& out, string s, int i, vector<string>& curr)
{
  if (i == s.size())
  {
    out.push_back(curr);
  }
  else
  {
    for (int j = i; j < s.size(); j++)
    {
      bool isPali = isPalindrome(s, i, j);
      if (isPali)
      {
	string ss = string(s.begin() + i, s.begin() + j + 1);
	curr.push_back(ss);
	dfs(out, s, j + 1, curr);
	curr.pop_back();
      }
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> out;
  vector<string> curr;
  dfs(out, s, 0, curr);
  return out;
}

int main(int argc, char **argv)
{
  string s = string("aab");
  vector<vector<string>> res = partition(s);
  for (auto& v : res)
  {
    for (auto& str : v)
    {
      printf("%s ", str.c_str());
    }
    printf("\n");
  }
  return 0;
}
