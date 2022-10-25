#include "Person.hpp"

#include <iostream>

/******** Person ********/

Person::Person(const std::string& _name, int _age, PersonType _type) : age(_age), type(_type), name(_name) {
}

const std::string Person::GetName() {
  return name;
}

int Person::GetAge() {
  return age;
}

PersonType Person::GetType() {
  return type;
}

/******** Student ********/

Student::Student(const std::string& _name, int _age) : Person(_name, _age, PersonType::student) {
}

void Student::PrintInfo() {
  std::cout << "Student : " << name << " aged " << age << std::endl;
}

/******** Professor ********/

Professor::Professor(const std::string& _name, int _age) : Person(_name, _age, PersonType::professor) {
}

void Professor::PrintInfo() {
  std::cout << "Professor : " << name << " aged " << age << std::endl;
}

/******** Staff ********/

Staff::Staff(const std::string& _name, int _age) : Person(_name, _age, PersonType::staff) {
}

void Staff::PrintInfo() {
  std::cout << "Staff : " << name << " aged " << age << std::endl;
}
