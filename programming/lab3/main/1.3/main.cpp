#include "group.h"

int main() {
    Group group(101);

    int grades1[] = {90, 80, 70};
    int grades2[] = {85, 75, 65};
    int grades3[] = {60, 60, 60};

    Student* s1 = new Student(1, "Ivanov", grades1, 3);
    Student* s2 = new Student(2, "APetrov", grades2, 3);
    Student* s3 = new Student(3, "ASidorov", grades3, 3);

    group.addStudent(s1);
    group.addStudent(s2);
    group.addStudent(s3);

    std::cout << "Initial group:\n" << group;

    group.sortBySurname();
    std::cout << "\nSorted group:\n" << group;
    group.findEvenGradeSumStudents();

    return 0;
}