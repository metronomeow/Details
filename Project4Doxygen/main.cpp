#include "DataBase.hpp"

#include <iostream>

void PrintPrompt();

int main(int argc, char* argv[]) {
  DataBase db;
  std::string command;
  char buf[256];
  while (true) {
    PrintPrompt();
    std::cin.getline(buf, 256);
    command = buf;
    if (command == "bye")
      break;
    if (command.substr(0, 3) == "add") {
      PersonType type = PersonType::undefined;
      if (command.substr(0, 8) == "add-stud")
        type = PersonType::student;
      if (command.substr(0, 8) == "add-prof")
        type = PersonType::professor;
      if (command.substr(0, 8) == "add-staf")
        type = PersonType::staff;
      size_t pos = command.find_first_of(' ');
      command.erase(0, pos + 1);
      pos = command.find_first_of(' ');
      //system("cls");
      db.Insert(type, command.substr(0, pos), atoi(command.substr(pos + 1).c_str()));
      continue;
    }
    if (command.substr(0, 3) == "lst") {
      //system("cls");
      if (command == "lst-all")
        db.List();
      if (command == "lst-students")
        db.List(PersonType::student);
      if (command == "lst-professors")
        db.List(PersonType::professor);
      if (command == "lst-staff")
        db.List(PersonType::staff);
      continue;
    }
    if (command.substr(0, 3) == "cnt") {
      //system("cls");
      if (command == "cnt-all")
        std::cout << db.Count() << std::endl;
      if (command == "cnt-students")
        std::cout << db.Count(PersonType::student) << std::endl;
      if (command == "cnt-professors")
        std::cout << db.Count(PersonType::professor) << std::endl;
      if (command == "cnt-staff")
        std::cout << db.Count(PersonType::staff) << std::endl;
      continue;
    }
    std::cout << "__error__ : Unrecognized command : " << command << std::endl;
  }
}

void PrintPrompt() {
  std::cout 
    << "Enter command for action:" << std::endl
    << '\t' << (char)249 << " add-student <name> <age>    : to add a new student"           << std::endl
    << '\t' << (char)249 << " add-professor <name> <age>  : to add a new professor"         << std::endl
    << '\t' << (char)249 << " add-staff <name> <age>      : to add a new staff"             << std::endl
    << '\t' << (char)249 << " lst-all                     : to list all resords"            << std::endl
    << '\t' << (char)249 << " lst-students                : to list only student records"   << std::endl
    << '\t' << (char)249 << " lst-professors              : to list only professor records" << std::endl
    << '\t' << (char)249 << " lst-staff                   : to list only staff records"     << std::endl
    << '\t' << (char)249 << " cnt-all                     : to count all persons"           << std::endl
    << '\t' << (char)249 << " cnt-students                : to count students only"         << std::endl
    << '\t' << (char)249 << " cnt-professors              : to count professors only"       << std::endl
    << '\t' << (char)249 << " cnt-staff                   : to count staff only"            << std::endl
    << '\t' << (char)249 << " bye                         : to exit program"                << std::endl
    << ">"
  ;
}
