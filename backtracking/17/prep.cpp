#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

static unordered_map<char, vector<char>> m =
{
  { '2', { 'a', 'b', 'c' } },
  { '3', { 'd', 'e', 'f' } },
  { '4', { 'g', 'h', 'i' } },
  { '5', { 'j', 'k', 'l' } },
  { '6', { 'm', 'n', 'o' } },
  { '7', { 'p', 'q', 'r', 's' } },
  { '8', { 't', 'u', 'v' } },
  { '9', { 'w', 'x', 'y', 'z' } }
};

void letterCombinationsRecursive(vector<string>& out, string& digits, int i, string& curr)
{
  if (i < digits.size())
  {
    vector<char> letters = m[digits[i]];
    for (auto& l : letters)
    {
      curr += l;
      letterCombinationsRecursive(out, digits, i + 1, curr);
      curr.pop_back();
    }
  }
  else
  {
    out.push_back(curr);
  }
}

vector<string> letterCombinations(string digits)
{
  if (digits.size() == 0) return {};
  vector<string> out;
  string curr;
  letterCombinationsRecursive(out, digits, 0, curr);
  return out;
}

int main(int argc, char **argv)
{
  string digits = "23";
  vector<string> res = letterCombinations(digits);
  for (auto& s : res)
  {
    printf("%s ", s.c_str());
  }
  return 0;
}
