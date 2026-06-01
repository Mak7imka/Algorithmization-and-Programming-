#include "group.h"

int main() {
    Group group(101);

    group.addStudent(Student(1, "Ivanov", {90, 80, 70}));
    group.addStudent(Student(2, "Petrov", {85, 75, 65}));
    group.addStudent(Student(3, "Sidorov", {60, 60, 60}));

    std::cout << "Initial group:\n" << group;

    group.sortByAverage();
    std::cout << "\nSorted by average grade:\n" << group;

    group.findEvenGradeSumStudents();
    group.showPriorityQueue();

    return 0;
}


// int* arr = new int[size];
// dellete[] arr;

// std::vector<int> vec(size);