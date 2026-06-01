#include "header.h"

// Count number of elements
int count(Node* head) {
  int cnt = 0;
  while (head) {
    cnt++;
    head = head->next;
  }
  return cnt;
}
