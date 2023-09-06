#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> topMostFrequent(vector<int>& nums, int k)
{
  vector<int> out;
  unordered_map<int, int> numToFreq;
  for (auto& n : nums)
  {
    numToFreq[n]++;
  }
  map<int, int, greater<int>> freqToNum;
  for (auto& it : numToFreq)
  {
    freqToNum[it.second] = it.first;
  }
  auto it = freqToNum.begin();
  for (int i = 0; i < k; ++i)
  {
    out.push_back(it->second);
    it++;
  }
  return out;
}

int main(int argc, char **argv)
{
  vector<int> nums = { 1, 1, 1, 2, 3 };
  int k = 2;
  vector<int> res = topMostFrequent(nums, k);
  for (auto& n : res)
  {
    printf("%d ", n);
  }
  printf("\n");
  return 0;
}
