#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int SUBJECTS = 5;

struct Student {
  unsigned int id;
  string surname;
  int grades[SUBJECTS];
};

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

void sortStudents(Student arr[], int size) {
    sort(arr, arr + size, [](const Student& a,const Student& b){
      return a.surname < b.surname;
    });
}

void printAll(const Student arr[], int size) {
  cout << "All students:\n";
  for (int i = 0; i < size; ++i) printStudent(arr[i]);
}

void searchEvenSum(const Student arr[], int size) {
  cout << "\nStudents with even sum of grades:\n";
  for (int i = 0; i < size; ++i) {
  if (evenSum(&arr[i])) {
    printStudent(arr[i]);
  }
}
}

int main() {
  Student arr[] = {
      {1001, "Pisarenko", {90, 80, 85, 75, 70}},
      {1002, "Makarenko", {88, 92, 80, 76, 84}},
      {1003, "Shevchenko", {99, 91, 87, 93, 95}}
  };
  const int size = sizeof(arr) / sizeof(Student);

  sortStudents(arr, size);
  printAll(arr, size);
  searchEvenSum(arr, size);
  return 0;
}
