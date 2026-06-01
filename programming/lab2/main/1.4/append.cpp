#include "header.h"

// Add element to the end of the list
void append(Node*& head, int value) {
  Node* newNode = new Node{ value, nullptr };
  if (!head) {
    head = newNode;
  } else {
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
  }
}
