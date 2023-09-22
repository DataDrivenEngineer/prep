#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

bool isEdge(string& w, vector<string>& wl, int i, unordered_map<int, vector<int>>& m)
{
  int numOfDiff = 0;
  for (int k = 0; k < w.size(); k++)
  {
    if (w[k] != wl[i][k])
    {
      numOfDiff++;
      if (numOfDiff > 1)
      {
	return false;
      }
    }
  }
  return true;
}

void buildGraph(string& beginWord, vector<string>& wordList, unordered_map<int, vector<int>>& m)
{
  for (int i = 0; i < wordList.size(); i++)
  {
    if (isEdge(beginWord, wordList, i, m))
    {
      m[-1].push_back(i);
    }
  }
  for (int i = 0; i < wordList.size(); i++)
  {
    for (int j = 0; j < wordList.size(); j++)
    {
      if (i == j) continue;
      if (isEdge(wordList[i], wordList, j, m))
      {
	m[i].push_back(j);
      }
    }
  }
}

struct State
{
  int i;
  int len;
};

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
  int maxLen = 0;
  unordered_map<int, vector<int>> m;
  buildGraph(beginWord, wordList, m);
  deque<State> dq;
  dq.push_back({ -1, 1 });
  unordered_set<int> s;
  while (!dq.empty())
  {
    State st = dq.front();
    dq.pop_front();
    if (!s.count(st.i))
    {
      s.insert(st.i);
      if (st.i >= 0 && wordList[st.i].compare(endWord) == 0)
      {
	if (st.len > maxLen)
	{
	  maxLen = st.len;
	}
      }
      for (auto& e : m[st.i])
      {
	dq.push_back({ e, st.len + 1 });
      }
    }
  }
  return maxLen;
}

using namespace std;

int main(int argc, char **argv)
{
  string bw = "hit";
  string ew = "cog";
  vector<string> wl = { "hot", "dot", "dog", "lot", "log", "cog" };
//  vector<string> wl = { "hot", "dot", "dog", "lot", "log" };
  int res = ladderLength(bw, ew, wl);
  printf("%d\n", res);
  return 0;
}
