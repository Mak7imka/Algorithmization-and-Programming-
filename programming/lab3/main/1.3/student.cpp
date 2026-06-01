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
