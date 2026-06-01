#include "header.h"

// Free memory of the list
void clear(Node*& head) {
  while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
  }
}
