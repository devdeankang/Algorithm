using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmStudy08
{

// Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/submissions/

    class ValidSudoku
    {
        public bool IsValidSudoku(char[][] board)
        {
            HashSet<char>[] boardSet = new HashSet<char>[27];

            for (int i = 0; i < boardSet.Length; i++)
            {
                boardSet[i] = new HashSet<char>();
            }

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.' && !IsValid(board, i, j, boardSet)) return false;
                }
            }
            return true;
        }

        public bool IsValid(char[][] board, int i, int j, HashSet<char>[] boardSet)
        {
            bool IsValid(int set)
            {
                if (boardSet[set].Contains(board[i][j])) return false;
                boardSet[set].Add(board[i][j]);

                return true;
            }

            return IsValid(i) && IsValid(9 + j) && IsValid(18 + i / 3 * 3 + j / 3);
        }
    }
}
