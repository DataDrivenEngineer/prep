def isValidSudoku(board):
    for row in range(0, len(board), 3):
        for col in range(0, len(board[0]), 3):
            seenDigits = set()
            for subRow in range(row, row + 3, 1):
                for subCol in range(col, col + 3, 1):
                    if board[subRow][subCol] == '.':
                        continue
                    elif board[subRow][subCol] in seenDigits:
                        return False
                    else:
                        seenDigits.add(board[subRow][subCol])
    return True


board = [["5","3",".",".","7",".",".",".","."],
         ["6",".",".","1","9","5",".",".","."],
         [".","9","8",".",".",".",".","6","."],
         ["8",".",".",".","6",".",".",".","3"],
         ["4",".",".","8",".","3",".",".","1"],
         ["7",".",".",".","2",".",".",".","6"],
         [".","6",".",".",".",".","2","8","."],
         [".",".",".","4","1","9",".",".","5"],
         [".",".",".",".","8",".",".","7","9"]]

print(isValidSudoku(board))