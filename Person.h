#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H

#include <iostream>
#include <string>
#include <set>

class Person{
public:
    Person(std::string, std::string, Person* = nullptr, Person* = nullptr);
    void out();
private:
    long id_ = 0;
    //std::string status_;
    std::string name_;
    std::string gender_;
    Person* mother_;
    Person* father_;
};

#endif //PERSON_PERSON_H
