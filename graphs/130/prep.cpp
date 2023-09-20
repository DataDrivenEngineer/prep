#include <stdio.h>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int i, int j)
{
  if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'O')
  {
    board[i][j] = 'T';
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
  }
}

void solve(vector<vector<char>>& board)
{
  for (int i = 0; i < board.size(); i++)
  {
    if (board[i][0] == 'O')
    {
      dfs(board, i, 0);
    }
  }
  for (int i = 0; i < board.size(); i++)
  {
    if (board[i][board[0].size() - 1] == 'O')
    {
      dfs(board, i, board[0].size() - 1);
    }
  }
  for (int j = 0; j < board[0].size(); j++)
  {
    if (board[0][j] == 'O')
    {
      dfs(board, 0, j);
    }
  }
  for (int j = 0; j < board[0].size(); j++)
  {
    if (board[board.size() - 1][j] == 'O')
    {
      dfs(board, board.size() - 1, j);
    }
  }

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] == 'O')
      {
	board[i][j] = 'X';
      }
      if (board[i][j] == 'T')
      {
	board[i][j] = 'O';
      }
    }
  }
}

int main(int argc, char **argv)
{
//  vector<vector<char>> board = 
//  {
//    { 'X','X','X','X'},
//    { 'X','O','O','X'},
//    { 'X','X','O','X'},
//    { 'X','O','X','X'},
//  };
  vector<vector<char>> board = 
  {
    { 'O','O'},
    { 'O','O'}
  };
  solve(board);
  for (auto& v : board)
  {
    for (auto& c : v)
    {
      printf("%c ", c);
    }
      printf("\n");
  }
  return 0;
}
