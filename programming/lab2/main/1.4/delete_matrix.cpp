#include "header.h"

// Free matrix memory
void delete_matrix(int** matrix, int rows) {
  for (int i = 0; i < rows; ++i)
      delete[] matrix[i];
  delete[] matrix;
}
