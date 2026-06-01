#include "header.h"

// Fill matrix from list
void fill_matrix_from_list(Node* head, int** matrix, int rows, int n) {
  Node* curr = head;
  for (int i = 0; i < rows && curr; ++i) {
      for (int j = 0; j < n && curr; ++j) {
          matrix[i][j] = curr->value;
          curr = curr->next;
      }
  }
}
