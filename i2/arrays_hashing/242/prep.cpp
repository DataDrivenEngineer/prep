#include <stdio.h>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
  if (s.size() != t.size())
    return false;
  unordered_map<char, int> m;
  for (auto c : s)
  {
    m[c]++;
  }
  for (auto c : t)
  {
    if (m[c]-- <= 0)
      return false;
  }
  return true;
}

int main(int argc, char **argv)
{
  string s1 = "anagram";
  string s2 = "nagaram";
  bool r = isAnagram(s1, s2);
  printf("%d\n", r);
  return 0;
}
