#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& name, int age) : name(name), age(age) {}
    virtual void display() const {
      cout << "Людина: " << name << ", Вік: " << age << endl;
    }
    virtual ~Person() {}
};

class Citizen : public Person {
protected:
    string passport;
public:
    Citizen(const string& name, int age, const string& passport) : Person(name, age), passport(passport) {}
    void display() const override { 
      cout << "Громадянин: " << name << ", Вік: " << age << ", Паспорт: " << passport << endl;
    }
};

class Student : public Citizen {
protected:
    string university;
    int course;
public:
    Student(const string& name, int age, const string& passport, const string& university, int course) : Citizen(name, age, passport), university(university), course(course) {}
    void display() const override {
      cout << "Студент: " << name << ", Вік: " << age << ", Паспорт: " << passport << ", Університет: " << university << ", Курс: " << course << endl;
    }
};

class Employee : public Citizen {
protected:
    string position;
    double salary;
public:
    Employee(const string& name, int age, const string& passport, const string& position, double salary) : Citizen(name, age, passport), position(position), salary(salary) {}
    void display() const override {
      cout << "Співробітник: " << name << ", Вік: " << age << ", Паспорт: " << passport << ", Посада: " << position << ", Зарплата: " << salary << endl;
    }
};

int main() {
    vector<Person*> people;
  
    people.push_back(new Person("Михайло", 25));
    people.push_back(new Citizen("Олена", 30, "АА123456"));
    people.push_back(new Student("Максим", 18, "ВВ654321", "ХПІ", 1));
    people.push_back(new Employee("Наталя", 40, "СС789012", "Менеджер", 15000.00));

    for (const auto& person : people) {
        person->display();
    }

    for (auto& person : people) {
        delete person;
    }

    return 0;
}
