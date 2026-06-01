#include "group.h"
#include <algorithm>

Group::Group() : index(0), studentCount(0) {}
Group::Group(int index) : index(index), studentCount(0) {}
Group::~Group() {
    for (int i = 0; i < studentCount; ++i) {
        delete students[i];
    }
}

void Group::setIndex(int index) { this->index = index; }
int Group::getIndex() const { return index; }

Student* Group::operator[](int i) const {
    if (i >= 0 && i < studentCount) return students[i];
    return nullptr;
}

void Group::addStudent(Student* student) {
    if (studentCount < MAX_STUDENTS) {
        students[studentCount++] = student;
        student->setGroup(this);
    }
}

void Group::sortBySurname() {
    std::sort(students, students + studentCount, [](Student* a, Student* b) {
        return *a < *b;
    });
}

void Group::findEvenGradeSumStudents() const {
    std::cout << "\nStudents with even sum of grades:\n";
    for (int i = 0; i < studentCount; ++i) {
        int sum = 0;
        const int* grades = students[i]->getGrades();
        for (int j = 0; j < students[i]->getGradesCount(); ++j) {
            sum += grades[j];
        }
        if (sum % 2 == 0)
            std::cout << *students[i] << "\n";
    }
}

Group& Group::operator=(const Group& other) {
    if (this == &other) return *this;

    for (int i = 0; i < studentCount; ++i) delete students[i];

    index = other.index;
    studentCount = other.studentCount;
    for (int i = 0; i < studentCount; ++i) {
        students[i] = new Student(*other.students[i]);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Group Index: " << group.index << "\n";
    for (int i = 0; i < group.studentCount; ++i) {
        os << *group.students[i] << "\n";
    }
    return os;
}