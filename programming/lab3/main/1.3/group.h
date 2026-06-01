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