#pragma once

#include <vector>

#include "Person.hpp"

class DataBase {
  std::vector<Person*> persons;
public:
 ~DataBase();
public:
  void Insert(PersonType _type, const std::string &_name, int _age);
  void List(PersonType _type = PersonType::undefined);
  /*!
  Function for counting
  \param[in] _type Type of note
  \return is return
  */
  int  Count(PersonType _type = PersonType::undefined);
  void Clear();
};
