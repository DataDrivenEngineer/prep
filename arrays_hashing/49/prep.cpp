#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool isAnagram(string& s, string& t)
{
  if (s.size() != t.size())
  {
    return false;
  }

  unordered_map<char, int> sf;
  for (char& c : s)
  {
    sf[c]++;
  }

  unordered_map<char, int> tf;
  for (char& c : t)
  {
    tf[c]++;
  }

  for (auto& it : tf)
  {
    if (it.second != sf[it.first])
    {
      return false;
    }
  }
  return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
  vector<vector<string>> out;
  unordered_set<int> visited;
  for (int i = 0; i < strs.size(); ++i)
  {
    if (!visited.count(i))
    {
      vector<string> anagrams = { strs[i] };
      for (int j = 0; j < strs.size(); ++j)
      {
	if (!visited.count(j) && (strs[i].compare(strs[j]) != 0))
	{
	  if (isAnagram(strs[i], strs[j]))
	  {
	    anagrams.push_back(strs[j]);
	    visited.insert(j);
	  }
	}
      }
      out.push_back(anagrams);
    }
    visited.insert(i);
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> res = groupAnagrams(strs);
  for (auto& v : res)
  {
    for (auto& s : v)
    {
      printf("%s ", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
