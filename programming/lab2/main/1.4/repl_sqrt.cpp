#include "header.h"

// Replace positive elements with sqrt
void replace_positive_with_sqrt(int** matrix, int rows, int n) {
  for (int i = 0; i < rows; ++i)
      for (int j = 0; j < n; ++j)
          if (matrix[i][j] > 0)
              matrix[i][j] = static_cast<int>(sqrt(matrix[i][j]));
}
