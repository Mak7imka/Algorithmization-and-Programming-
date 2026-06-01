#include "header.h"

// Create dynamic matrix
int** create_matrix(int rows, int n) {
  int** matrix = new int*[rows];
  for (int i = 0; i < rows; ++i) {
      matrix[i] = new int[n]{ 0 };
  }
  return matrix;
}
