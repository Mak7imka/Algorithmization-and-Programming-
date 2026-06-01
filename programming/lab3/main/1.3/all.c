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

#ifndef GROUP_H
#define GROUP_H
#include "student.h"

const int MAX_STUDENTS = 50;

class Group {
private:
    int index;
    Student* students[MAX_STUDENTS];
    int studentCount;

public:
    Group();
    Group(int index);
    ~Group();

    void setIndex(int index);
    int getIndex() const;

    Student* operator[](int i) const;

    void addStudent(Student* student);
    void sortBySurname();
    void findEvenGradeSumStudents() const;

    Group& operator=(const Group& other);

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
};

#endif

#include "student.h"
#include "group.h"

Student::Student() : id(0), surname(nullptr), grades(nullptr), gradesCount(0), group(nullptr) {}

Student::Student(unsigned int id, const char* surname, const int* grades, int gradesCount)
    : id(id), gradesCount(gradesCount), group(nullptr) {
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
    this->grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; ++i) {
        this->grades[i] = grades[i];
    }
}

Student::Student(const Student& other)
    : id(other.id), gradesCount(other.gradesCount), group(other.group) {
    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);
    grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; ++i) {
        grades[i] = other.grades[i];
    }
}

Student::~Student() {
    delete[] surname;
    delete[] grades;
}

Student& Student::operator=(const Student& other) {
    if (this == &other) return *this;

    delete[] surname;
    delete[] grades;

    id = other.id;
    gradesCount = other.gradesCount;
    group = other.group;

    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);

    grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; ++i)
        grades[i] = other.grades[i];

    return *this;
}

unsigned int Student::getId() const { return id; }
const char* Student::getSurname() const { return surname; }
const int* Student::getGrades() const { return grades; }
int Student::getGradesCount() const { return gradesCount; }
Group* Student::getGroup() const { return group; }

void Student::setId(unsigned int id) { this->id = id; }
void Student::setSurname(const char* surname) {
    delete[] this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}
void Student::setGrades(const int* grades, int gradesCount) {
    delete[] this->grades;
    this->gradesCount = gradesCount;
    this->grades = new int[gradesCount];
    for (int i = 0; i < gradesCount; ++i)
        this->grades[i] = grades[i];
}
void Student::setGroup(Group* group) { this->group = group; }

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << ", Surname: " << student.surname << ", Grades: ";
    for (int i = 0; i < student.gradesCount; ++i) {
        os << student.grades[i] << ' ';
    }
    return os;
}

bool Student::operator<(const Student& other) const {
    return strcmp(this->surname, other.surname) < 0;
}

bool Student::operator>(const Student& other) const {
    return strcmp(this->surname, other.surname) > 0;
}

bool Student::operator==(const Student& other) const {
    return strcmp(this->surname, other.surname) == 0;
}

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Group; // Наперед оголошуємо клас Group

class Student {
private:
    unsigned int id;
    char* surname;
    int* grades;
    int gradesCount;
    Group* group;

public:
    Student();
    Student(unsigned int id, const char* surname, const int* grades, int gradesCount);
    Student(const Student& other);
    ~Student();

    Student& operator=(const Student& other);

    unsigned int getId() const;
    const char* getSurname() const;
    const int* getGrades() const;
    int getGradesCount() const;
    Group* getGroup() const;

    void setId(unsigned int id);
    void setSurname(const char* surname);
    void setGrades(const int* grades, int gradesCount);
    void setGroup(Group* group);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator==(const Student& other) const;
};

#endif


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