#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
  if (s.size() != t.size())
  {
    return false;
  }

  unordered_map<char, int> mapS;
  for (char& c : s)
  {
    mapS[c]++;
  }

  unordered_map<char, int> mapT;
  for (char& c : t)
  {
    mapT[c]++;
  }

  for (const auto& itS : mapS)
  {
    if (mapT[itS.first] != itS.second)
    {
      return false;
    }
  }

  return true;
}

int main(int argc, char **argv)
{
  string s = string("anagram");
  string t = string("nagaram");
  printf("isAnagram: %d\n", isAnagram(s, t));
  return 0;
}
