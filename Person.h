#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <iostream>
#include <string>
#include <set>

class Person{
public:
    virtual ~Person();
private:
    long id_;
    std::string name_;
    std::string gender_;
    std::string status_;
    Person* mother_;
    Person* father_;
    Person(std::string, std::string, Person* = nullptr, Person* = nullptr);
};
#endif //PERSON_PERSON_H
