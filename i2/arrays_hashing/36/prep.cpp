#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>> board)
{
  int row = 0;
  int col = 0;
  unordered_map<int, int> m;
  while (row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
  {
    m.clear();
    for (int i = row; i < row + 3; i++)
    {
      for (int j = col; j < col + 3; j++)
      {
	if (board[i][j] == '.') continue;
	m[board[i][j]]++;
	if (m[board[i][j]] > 1)
	{
	  return false;
	}
      }
    }

    if (col + 3 < board[0].size())
    {
      col += 3;
    }
    else
    {
      row += 3;
      col = 0;
    }
  }

  return true;
}

int main(int argc, char **argv)
{
  vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
  };
//  vector<vector<char>> board = {
//    {'8','3','.','.','7','.','.','.','.'},
//    {'6','.','.','1','9','5','.','.','.'},
//    {'.','9','8','.','.','.','.','6','.'},
//    {'8','.','.','.','6','.','.','.','3'},
//    {'4','.','.','8','.','3','.','.','1'},
//    {'7','.','.','.','2','.','.','.','6'},
//    {'.','6','.','.','.','.','2','8','.'},
//    {'.','.','.','4','1','9','.','.','5'},
//    {'.','.','.','.','8','.','.','7','9'},
//  };
  bool r = isValid(board);
  printf("%d\n", r);
  return 0;
}