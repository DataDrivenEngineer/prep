#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s)
{
  transform(s.begin(), s.end(), s.begin(), [] (char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9'))
    {
      return tolower(c);
    }
    else
    {
      return 0;
    }
  });
  int i = 0;
  int j = s.size() - 1;
  while (i <= j)
  {
    if (s[i] == 0)
    {
      i++;
      continue;
    }
    if (s[j] == 0)
    {
      j--;
      continue;
    }
    if (s[i] != s[j])
    {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int main(int argc, char **argv)
{
//  string s = string("A man, a plan, a canal: Panama");
//  string s = string("race a car");
//  string s = string(" ");
  string s = string("0P");
  bool res = isPalindrome(s);
  printf("%d\n", res);
  return 0;
}
