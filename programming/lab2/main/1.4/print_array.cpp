#include "header.h"

void print_array(int* arr, int size, ostream& out) {
  for (int i = 0; i < size; ++i)
      out << arr[i] << "\t";
  out << endl;
}
