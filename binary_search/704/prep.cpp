#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int searchRecursive(vector<int>& nums, int target, int l, int r)
{
  if (l > r)
  {
    return -1;
  }
  int mid = (l + r) / 2;
  if (nums[mid] == target)
  {
    return mid;
  }
  else if (nums[mid] < target)
  {
    return searchRecursive(nums, target, mid + 1, r);
  }
  else
  {
    return searchRecursive(nums, target, l, mid - 1);
  }
}

typedef struct
{
  int l;
  int r;
} State;

int searchIterative(vector<int>& nums, int target)
{
  stack<State> st;
  st.push({ 0, static_cast<int>(nums.size() - 1)});
  while(!st.empty())
  {
    State s = st.top();
    st.pop();
    if (s.l <= s.r)
    {
      int mid = s.l + (s.r - s.l) / 2;
      if (nums[mid] == target)
      {
	return mid;
      }
      else if (nums[mid] < target)
      {
	st.push({ mid + 1, s.r});
      }
      else
      {
	st.push({ s.l, static_cast<int>(mid - 1)});
      }
    }
  }
  return -1;
}

int searchTwoPointers(vector<int>& nums, int target)
{
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return -1;
}

int search(vector<int>& nums, int target)
{
//  return searchRecursive(nums, target, 0, nums.size() - 1);
//  return searchIterative(nums, target);
  return searchTwoPointers(nums, target);
}

int main(int argc, char **argv)
{
  vector<int> nums = { -1, 0, 3, 5, 9, 12};
  int target = 9;
//  vector<int> nums = {5};
//  int target = -5;
  int res = search(nums, target);
  printf("%d\n", res);
  return 0;
}
