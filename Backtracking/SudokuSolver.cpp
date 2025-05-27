#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPresent(vector<vector<char>>& board, char num, int x, int y) {
        for(int i = 0; i < 9; i++) {
            if(board[x][i] == num) return true;
        }

        for(int i = 0; i < 9; i++) {
            if(board[i][y] == num) return true;
        }

        int iStart = (x >= 6) ? 6 : ((x >= 3) ? 3 : 0);
        int jStart = (y >= 6) ? 6 : ((y >= 3) ? 3 : 0);
        int iEnd = iStart + 3;
        int jEnd = jStart + 3;
        for(int i = iStart; i < iEnd; i++) {
            for(int j = jStart; j < jEnd; j++) {
                if(board[i][j] == num) return true;
            }
        }
        return false;
    }
    bool sudokuSolverHelper(vector<vector<char>>& board, int x, int y) {
        if(y == 9) {
            x++;
            y = 0;
        }
        if(x == 9) return true;

        if(board[x][y] != '.') {
           return sudokuSolverHelper(board, x, y + 1);
        }

        for(int i = '1'; i <= '9'; i++) {
            if(!isPresent(board, i, x, y)) {
                board[x][y] = i;
                if(sudokuSolverHelper(board, x, y)) {
                    return true;
                }
                board[x][y] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolverHelper(board, 0, 0);
    }
};