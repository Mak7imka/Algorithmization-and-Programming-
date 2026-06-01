#include <iostream>
#include <vector>

using namespace std;

void heapify(int list[], int listLength, int root) {
  int largest = root;
  int l = 2 * root + 1;
  int r = 2 * root + 2;

  if (l < listLength && list[l] > list[largest])
    largest = l;

  if (r < listLength && list[r] > list[largest])
    largest = r;

  if (largest != root) {
    swap(list[root], list[largest]);

    heapify(list, listLength, largest);
  }
}

void heapSort(int list[], int listLength) {
  for (int i = listLength / 2 - 1; i >= 0; i--)
    heapify(list, listLength, i);

  for (int i = listLength - 1; i >= 0; i--) {
    swap(list[0], list[i]);

    heapify(list, i, 0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
  cout << "\n";
}

int main() {
  int arr[] = {4, 1, 30, 21, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Вихідний масив: ";
  printArray(arr, n);

  heapSort(arr, n);

  cout << "\nВідсортований масив: ";
  printArray(arr, n);

  return 0;
}