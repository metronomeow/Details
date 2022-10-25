#pragma once

#include <string>

enum class PersonType {
  undefined, ///< хтото
  student,///<чтото
  professor,
  staff,
};

/*!
 \brief Parent class

 this is a base class ха
*/

class Person {
protected:
  int         age;
  PersonType  type;
  std::string name;
public:
  Person(const std::string &_name, int _age, PersonType _type = PersonType::undefined);
public:
  const std::string GetName();
  int               GetAge();
  PersonType        GetType();
public:
  virtual void PrintInfo() = 0;
};

class Student : public Person {
public:
  Student(const std::string& _name, int _age);
public:
  void PrintInfo() override final;
};

class Professor : public Person {
public:
  Professor(const std::string& _name, int _age);
public:
  void PrintInfo() override final;
};

class Staff : public Person {
public:
  Staff(const std::string& _name, int _age);
public:
  void PrintInfo() override final;
};
