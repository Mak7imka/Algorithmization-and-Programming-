#include "header.h"

void print_matrix(int** matrix, int rows, int n, ostream& out) {
  for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < n; ++j) {
          out << matrix[i][j] << "\t";
      }
      out << endl;
  }
}
