#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

const int n = 5;

struct Node {
    int value;
    Node* next;
};

void append(Node*& head, int value);
int count(Node* head);
void clear(Node*& head);
int** create_matrix(int rows, int n);
void fill_matrix_from_list(Node* head, int** matrix, int rows, int n);
void replace_positive_with_sqrt(int** matrix, int rows, int n);
int* max_in_rows(int** matrix, int rows, int n);
void print_matrix(int** matrix, int rows, int n, ostream& out);
void delete_matrix(int** matrix, int rows);
void print_array(int* arr, int size, ostream& out);


#endif
