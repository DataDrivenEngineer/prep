#include <stdio.h>
#include <vector>

using namespace std;

int binarySearchRowRecursive(vector<vector<int>> m, int target, int l, int h)
{
  if (l > h)
  {
    return -1;
  }
  int mid = l + (h - l) / 2;
  if (m[mid][0] <= target && m[mid][m[0].size() - 1] >= target)
  {
    return mid;
  }
  else if (m[mid][0] > target)
  {
    return binarySearchRowRecursive(m, target, 0, mid - 1);
  }
  else 
  {
    return binarySearchRowRecursive(m, target, mid + 1, h);
  }
}

bool binarySearchTargetRecursive(vector<int> m, int target, int l, int h)
{
  if (l > h)
  {
    return false;
  }
  int mid = l + (h - l) / 2;
  if (m[mid] == target)
  {
    return true;
  }
  else if (m[mid] < target)
  {
    return binarySearchTargetRecursive(m, target, mid + 1, h);
  }
  else {

    return binarySearchTargetRecursive(m, target, 0, mid - 1);
  }
}


bool binarySearchMatrix(vector<vector<int>> m, int target)
{
  int rowIndex = binarySearchRowRecursive(m, target, 0, m.size() - 1);
  if (rowIndex < 0)
  {
    return false;
  }
  return binarySearchTargetRecursive(m[rowIndex], target, 0, m[rowIndex].size() - 1);
}

int main(int argc, char **argv)
{
  vector<vector<int>> m = { { 1,3,5,7}, { 10,11,16,20}, { 23,30,34,60} };
//  int target = 3;
  int target = 13;
  bool res = binarySearchMatrix(m, target);
  printf("%d\n", res);
  return 0;
}
