#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
  map<map<int,int>, vector<string>> countsToStrings;

  for (auto& s : strs)
  {
    map<int, int> charToCount;

    for (auto c : s)
    {
      charToCount[c - 'a']++;
    }

    auto it = countsToStrings.find(charToCount);
    if (it != countsToStrings.end())
    {
      it->second.push_back(s);
    }
    else
    {
      countsToStrings[charToCount] = vector<string> { s };
    }
  }

  vector<vector<string>> out;
  for (auto it : countsToStrings)
  {
    out.push_back(it.second);
  }

  return out;
}

int main(int argc, char **argv)
{
  vector<string> strs = { string("eat"),string("tea"),string("tan"),string("ate"),string("nat"),string("bat") };
  vector<vector<string>> r = groupAnagrams(strs);
  for (auto& vs : r)
  {
    for (auto& s : vs)
    {
      printf("%s ", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
