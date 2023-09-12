#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int minHoursRecursive(vector<int> bananas, int hours, int totalBananas, int l, int h, int min)
{
  if (l > h)
  {
    return min;
  }
  int mid = l + (h - l) / 2;
  int howManyBananasWithMid = mid * hours;
  if (howManyBananasWithMid < totalBananas)
  {
    return minHoursRecursive(bananas, hours, totalBananas, mid + 1, h, min);
  }
  else
  {
    if (mid < min)
    {
      min = mid;
    }
    return minHoursRecursive(bananas, hours, totalBananas, 0, mid - 1, min);
  }
}

int minHours(vector<int> bananas, int hours)
{
  int l = INT_MAX;
  int h = INT_MIN;
  int totalBananas = 0;
  for (auto& n : bananas)
  {
    totalBananas += n;
    if (n < l)
    {
      l = n;
    }
    if (n > h)
    {
      h = n;
    }
  }

  // recursive
//  return minHoursRecursive(bananas, hours, totalBananas, l, h, INT_MAX);

  // iterative
  int min = INT_MAX;
  while (l <= h)
  {
    int mid = l + (h - l) / 2;
    int howManyBananasWithMid = mid * hours;
    if (howManyBananasWithMid < totalBananas)
    {
      l++;
    }
    else
    {
      if (mid < min)
      {
	min = mid;
      }
      h--;
    }
  }
  return min;
}

int main(int argc, char **argv)
{
  // total: 27
  vector<int> bananas = { 3,6,7,11 };
  int h = 8;
  sort(bananas.begin(), bananas.end());
  int res = minHours(bananas, h);
  printf("%d\n", res);
  return 0;
}
