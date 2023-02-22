#include <iostream>
#include <vector>
using namespace std;

// Tc: 9^n
// Sc: O(1)   bc 9*9 ki grid hogi and max 81 fill krne hoge which is constant

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == val)
            return false;

        // col check
        if (board[i][col] == val)
            return false;

        // 3*3 matrix check  //tricky dry run if not get
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // cell empty
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;

                        // recursive call
                        bool aageSolutionPossible = solve(board);

                        if (aageSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{

    return 0;
}