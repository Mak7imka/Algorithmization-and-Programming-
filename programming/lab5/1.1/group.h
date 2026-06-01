#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <queue>
#include <functional>
#include "student.h"

class Group {
private:
    int index;
    std::vector<Student> students;

public:
    Group();
    Group(int index);

    void addStudent(const Student& student);
    void sortByAverage();
    void findEvenGradeSumStudents() const;

    void showPriorityQueue() const;

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
};

#endif
