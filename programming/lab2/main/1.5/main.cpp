#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int SUBJECTS = 5;

struct Student {
    unsigned int id;
    string surname;
    int grades[SUBJECTS];
};

struct Node {
    Student* data;
    Node* prev;
    Node* next;
};

void addNode(Node*& head, Node*& tail, Student* student) {
    Node* newNode = new Node;
    newNode->data = student;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void printStudent(const Student& info) {
    cout << "ID: " << info.id << ", Surname: " << info.surname << ", Grades: ";
    for (int g : info.grades) cout << g << " ";
    cout << "\n";
}

int gradeSum(const Student* info) {
    int sum = 0;
    for (int grade : info->grades) 
        sum += grade;
    return sum;
}

bool evenSum(const Student* info) {
    return gradeSum(info) % 2 == 0;
}

void sortStudents(Node* head) {
    Node* current = head;
    while (current) {
        Node* minNode = current;
        Node* temp = current->next;
        while (temp) {
            if (temp->data->surname < minNode->data->surname) {
                minNode = temp;
            }
            temp = temp->next;
        }
        swap(current->data, minNode->data);
        current = current->next;
    }
}

void printAll(Node* head) {
    cout << "All students:\n";
    Node* current = head;
    while (current) {
        printStudent(*(current->data));
        current = current->next;
    }
}

void searchEvenSum(Node* head) {
    cout << "\nStudents with even sum of grades:\n";
    Node* current = head;
    while (current) {
        if (evenSum(current->data)) {
            printStudent(*(current->data));
        }
        current = current->next;
    }
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    addNode(head, tail, new Student{1001, "Pisarenko", {90, 80, 85, 75, 70}});
    addNode(head, tail, new Student{1002, "Makarenko", {88, 92, 80, 76, 84}});
    addNode(head, tail, new Student{1003, "Shevchenko", {99, 91, 87, 93, 95}});

    sortStudents(head);
    printAll(head);
    searchEvenSum(head);

    deleteList(head);
    return 0;
}