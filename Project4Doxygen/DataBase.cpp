#include "DataBase.hpp"

#include <iostream>

DataBase::~DataBase() {
  Clear();
}

void DataBase::Insert(PersonType _type, const std::string &_name, int _age) {
  Person* p = nullptr;
  switch (_type) {
    case PersonType::student:
      p = new Student(_name, _age);
      break;
    case PersonType::professor:
      p = new Professor(_name, _age);
      break;
    case PersonType::staff:
      p = new Staff(_name, _age);
      break;
    default:
      std::cerr << "__err__ : Wrong person type was given." << std::endl;
      return;
  }
  persons.push_back(p);
  std::cout << "One record inserted" << std::endl;
}

std::string PersonTypeToString(PersonType _type) {
  switch (_type) {
    case PersonType::student:
      return "student";
    case PersonType::professor:
      return "professor";
    case PersonType::staff:
      return "staff";
    default:
      return "undefined";
  }
}

void DataBase::List(PersonType _type) {
  if (persons.empty()) {
    std::cout << "0 records found" << std::endl;
    return;
  }

  size_t counter = 0;
  if (_type == PersonType::undefined) {
    std::cout << "Listing database records:" << std::endl;
    for (size_t i = 0; i < persons.size(); ++i)
      std::cout << ++counter << ' ' << persons[i]->GetName() << " [" << PersonTypeToString(persons[i]->GetType()) << "]"  << std::endl;
    if (!counter)
      std::cout << "0 records found" << std::endl;
    return;
  }

  
  std::cout << "Listing database records for type '" << PersonTypeToString(_type) << "':" << std::endl;
  for (size_t i = 0; i < persons.size(); ++i) {
    if (persons[i]->GetType() != _type)
      continue;
    std::cout << ++counter << ' ' << persons[i]->GetName() << std::endl;
  }
  if (!counter)
    std::cout << "0 records found" << std::endl;
}

int DataBase::Count(PersonType _type) {
  if (persons.empty())
    return 0;

  if (_type == PersonType::undefined)
    return persons.size();

  int counter = 0;
  for (size_t i = 0; i < persons.size(); ++i) {
    if (persons[i]->GetType() != _type)
      continue;
    ++counter;
  }
  return counter;
}

void DataBase::Clear() {
  for (size_t i = 0; i < persons.size(); ++i) {
    delete persons[i];
    persons[i] = nullptr;
  }
  persons.clear();
}