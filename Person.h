#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <iostream>
#include <string>
#include <set>

class Person{
public:
    void SetEva(std::string, std::string);
    void SetAdam(std::string, std::string);
    Person operator =(Person &other);
    static Person GetEva();
    static Person GetAdam();
    virtual ~Person();
    void out();

private:
    long id_ = -1;
    bool clone_ = 1;
    std::string name_ = "God";
    std::string gender_ = "male";
    std::string status_ = "Alive";
    Person* mother_ = nullptr;
    Person* father_ = nullptr;
    Person(std::string, std::string, Person* = nullptr, Person* = nullptr, bool clone = 1);
};
#endif //PERSON_PERSON_H
