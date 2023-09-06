#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isValid(vector<vector<string>>& board)
{
  unordered_set<string> s = unordered_set<string>(9);
  // row
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
//      printf("board[i][j]: %s\n", board[i][j].c_str());
//      printf("board[i][j].compare(string(\".\")): %d\n", board[i][j].compare(string(".")));
      if (board[i][j].compare(string(".")) == 0) continue;
//      printf("s.count(board[i][j]): %d\n", s.count(board[i][j]));
      if (s.count(board[i][j]))
      {
	return false;
      }
      s.insert(board[i][j]);
    }
    s.clear();
  }

  s.clear();
  // column
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[j][i].compare(string(".")) == 0) continue;
      if (s.count(board[j][i]))
      {
	return false;
      }
      s.insert(board[j][i]);
    }
    s.clear();
  }

  s.clear();
  // subbox 
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      for (int li = i; li < i + 3; li++)
      {
	for (int lj = j; lj < j + 3; lj++)
	{
//	  printf("i: %d, j: %d, li: %d, lj: %d\n", i, j, li, lj);
//	    printf("board[lj][li]: %s\n", board[lj][li].c_str());
//	    printf("board[lj][li].compare(string(\".\")): %d\n", board[lj][li].compare(string(".")));
//	  printf("s.count(board[lj][li]): %d\n", s.count(board[lj][li]));
	  if (board[lj][li].compare(string(".")) == 0) continue;
	  if (s.count(board[lj][li]))
	  {
	    return false;
	  }
	  s.insert(board[lj][li]);
	}
      }
      s.clear();
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  vector<vector<string>> board = {{string("5"),string("3"),string("."),string("."),string("7"),string("."),string("."),string("."),string(".")},{string("6"),string("."),string("."),string("1"),string("9"),string("5"),string("."),string("."),string(".")},{string("."),string("9"),string("8"),string("."),string("."),string("."),string("."),string("6"),string(".")},{string("8"),string("."),string("."),string("."),string("6"),string("."),string("."),string("."),string("3")},{string("4"),string("."),string("."),string("8"),string("."),string("3"),string("."),string("."),string("1")},{string("7"),string("."),string("."),string("."),string("2"),string("."),string("."),string("."),string("6")},{string("."),string("6"),string("."),string("."),string("."),string("."),string("2"),string("8"),string(".")},{string("."),string("."),string("."),string("4"),string("1"),string("9"),string("."),string("."),string("5")},{string("."),string("."),string("."),string("."),string("8"),string("."),string("."),string("7"),string("9")}};
  bool res = isValid(board);
  printf("%d\n", res);
  return 0;
}
