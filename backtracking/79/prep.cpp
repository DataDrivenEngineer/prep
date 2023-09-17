#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool existRecursive(vector<vector<char>>& board, string& word, int i, int j, vector<int>& vij, int ci)
{
  if (ci == word.size() - 1)
  {
    return true;
  }
  if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && vij[i * board[0].size() + j])
  {
    ci++;
    if (ci < word.size() && word[ci] == board[i][j])
    {
      vij[i * board[0].size() + j] = 0;
      bool existsLeft = existRecursive(board, word, i, j - 1, vij, ci);
      bool existsRight = existRecursive(board, word, i, j + 1, vij, ci);
      bool existsTop = existRecursive(board, word, i - 1, j, vij, ci);
      bool existsBottom = existRecursive(board, word, i + 1, j, vij, ci);
      vij[i * board[0].size() + j] = 1;
      return existsLeft || existsRight || existsTop || existsBottom;
    }
  }
  return false;
}

bool exist(vector<vector<char>>& board, string word)
{
  vector<int> vij = vector<int>(board.size() * board[0].size(), 1);
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      bool found = existRecursive(board, word, i, j, vij, -1);
      if (found)
      {
	return true;
      }
    }
  }
  return false;
}

int main(int argc, char **argv)
{
  vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'} };
  string word = string("ABCCED");
//  string word = string("SEE");
  bool res = exist(board, word);
  printf("%d\n", res);
  return 0;
}
