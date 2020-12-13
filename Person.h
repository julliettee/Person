#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <iostream>
#include <string>
#include <set>
#include <map>

class Person{
public:
    Person();
    Person(const Person&);
    void SetEva(std::string, std::string);
    void SetAdam(std::string, std::string);
    void Death(Person* = nullptr);
    void GetParents();
    Person& operator =(Person const& other);
    Person GiveBirth(std::string, std::string, Person*);
    static Person GetEva();
    static Person GetAdam();
    virtual ~Person();
    void out();
private:
    long id_ = -1;
    bool clone_ = true;
    std::string name_;
    std::string gender_;
    std::string status_;
    Person* mother_ = nullptr;
    Person* father_ = nullptr;
    Person(std::string, std::string, Person* = nullptr, Person* = nullptr, bool clone = true);
};
#endif //PERSON_PERSON_H
