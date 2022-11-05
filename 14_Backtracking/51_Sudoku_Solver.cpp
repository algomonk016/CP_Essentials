/*
Sudoku Solver
  Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to fill the grid with the constraint that every row, column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.
  Implement an efficient sudoku solver that takes in an incomplete board and solves it. In the given board, the incomplete spaces will be 0.
*/ 

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& matrix, int x, int y, int val) {
  for (int j = 0; j < 9; j++) if (matrix[x][j] == val) return false;

  for (int i = 0; i < 9; i++) if (matrix[i][y] == val) return false;

  int smi = x / 3 * 3;
  int smj = y / 3 * 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[smi + i][smj + j] == val) return false;
    }
  }

  return true;
}

bool solveSudoku(vector<vector<int>>& matrix, int i, int j) {
  if (i == 9) return true;

  int ni = 0, nj = 0;
  if (j == 8) {
    ni = i + 1;
    nj = 0;
  } else {
    ni = i;
    nj = j + 1;
  }

  if (matrix[i][j] != 0) {
    if (solveSudoku(matrix, ni, nj)) return true;
  } else {
    for (int po = 1; po <= 9; po++) {
      if (isValid(matrix, i, j, po)) {
        matrix[i][j] = po;
        if (solveSudoku(matrix, ni, nj)) return true;
        matrix[i][j] = 0;
      }
    }
  }

  return false;
}
vector<vector<int>> solve(vector<vector<int>> matrix) {
  solveSudoku(matrix,0,0);
  return matrix;
}