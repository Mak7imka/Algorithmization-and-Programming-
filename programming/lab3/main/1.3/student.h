#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Group;

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