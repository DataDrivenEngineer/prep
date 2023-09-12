#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

struct TimeMap
{
  unordered_map<string, vector<pair<string, int>>> m;
  TimeMap(): m() {}

  void set(string key, string val, int time)
  {
    m[key].push_back(make_pair(val, time));
  }

  string get(string key, int time)
  {
    string res = string("");
    vector<pair<string, int>>& v = m[key];
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (v[mid].second == time)
      {
	res = v[mid].first;
	break;
      }
      else if (v[mid].second < time)
      {
	res = v[mid].first;
	l = mid + 1;
      }
      else
      {
	r = mid - 1;
      }
    }
    return res;
  }
};

int main(int argc, char **argv)
{
  TimeMap t = TimeMap();
  t.set(string("foo"), string("bar"), 1);
  printf("%s ", t.get(string("foo"), 1).c_str());
  printf("%s ", t.get(string("foo"), 3).c_str());
  t.set(string("foo"), string("bar2"), 4);
  printf("%s ", t.get(string("foo"), 4).c_str());
  printf("%s ", t.get(string("foo"), 5).c_str());
  return 0;
}
