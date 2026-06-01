#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric> 

class Group;

class Student {
private:
    unsigned int id;
    std::string surname;
    std::vector<int> grades;
    Group* group;

public:
    Student();
    Student(unsigned int id, const std::string& surname, const std::vector<unsigned int>& grades);

    unsigned int getId() const;
    const std::string& getSurname() const;
    const std::vector<int>& getGrades() const;
    Group* getGroup() const;

    void setId(unsigned int id);
    void setSurname(const std::string& surname);
    void setGrades(const std::vector<int>& grades);
    void setGroup(Group* group);

    double averageGrade() const;
    bool hasEvenGradeSum() const;

    bool operator<(const Student& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif
