#include "header.h"

int* max_in_rows(int** matrix, int rows, int n) {
  int* result = new int[rows];
  for (int i = 0; i < rows; ++i) {
      int max_val = matrix[i][0];
      for (int j = 1; j < n; ++j) {
          if (matrix[i][j] > max_val)
              max_val = matrix[i][j];
      }
      result[i] = max_val;
  }
  return result;
}
