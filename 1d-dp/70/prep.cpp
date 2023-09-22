#include <stdio.h>

using namespace std;

int climbStairs(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  int one = 1;
  int two = 1;
  n--;
  while (n > 1)
  {
    int next = one + two;
    int tmp = one;
    one = next;
    two = tmp;
    n--;
  }
  return one + two;
}

int main(int argc, char **argv)
{
//  int n = 2;
  int n = 3;
  int res = climbStairs(n);
  printf("%d\n", res);
  return 0;
}
