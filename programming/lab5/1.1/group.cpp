#include "group.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

Group::Group() : index(0) {}
Group::Group(int index) : index(index) {}

void Group::addStudent(const Student& student) {
    students.push_back(student);
}

void Group::sortByAverage() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.averageGrade() > b.averageGrade(); 
    });
}

void Group::findEvenGradeSumStudents() const {
    std::cout << "\nStudents with even sum of grades:\n";
    std::for_each(students.begin(), students.end(), [](const Student& s) {
        if (s.hasEvenGradeSum()) std::cout << s << "\n";
    });
}

void Group::showPriorityQueue() const {
    std::priority_queue<Student, std::vector<Student>, 
        std::function<bool(const Student&, const Student&)>> pq(
            [](const Student& a, const Student& b) {
                return a.averageGrade() < b.averageGrade();
            });

    for (const auto& s : students) {
        pq.push(s);
    }

    std::cout << "\nPriority Queue (avg grade descending):\n";
    while (!pq.empty()) {
        std::cout << pq.top() << "\n";
        pq.pop();
    }
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Group Index: " << group.index << "\n";
    for (const auto& student : group.students) {
        os << student << "\n";
    }
    return os;
}
