#include "student.h"

Student::Student() : id(0), group(nullptr) {}

Student::Student(unsigned int id, const std::string& surname, const std::vector<int>& grades)
    : id(id), surname(surname), grades(grades), group(nullptr) {}

unsigned int Student::getId() const { return id; }
const std::string& Student::getSurname() const { return surname; }
const std::vector<int>& Student::getGrades() const { return grades; }
Group* Student::getGroup() const { return group; }

void Student::setId(unsigned int id) { this->id = id; }
void Student::setSurname(const std::string& surname) { this->surname = surname; }
void Student::setGrades(const std::vector<int>& grades) { this->grades = grades; }
void Student::setGroup(Group* group) { this->group = group; }

double Student::averageGrade() const {
    if (grades.empty()) return 0;
    return static_cast<double>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}

bool Student::hasEvenGradeSum() const {
    return std::accumulate(grades.begin(), grades.end(), 0) % 2 == 0;
}

bool Student::operator<(const Student& other) const {
    return surname < other.surname;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << ", Surname: " << student.surname << ", Grades: ";
    for (int grade : student.grades) {
        os << grade << ' ';
    }
    os << "(avg: " << student.averageGrade() << ")";
    return os;
}
