#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

enum class Genders {male,female};

class Person{
public:
    Person(const Person&);
    std::string GetGender() const;
    std::string GetStatus() const;
    std::string GetName() const;
    void Death(Person* = nullptr);
    void GetParents();
    void GetChildren();
    void GetChildren(Person*);
    Person& operator =(Person const& other);
    Person GiveBirth(Genders, std::string, Person* = nullptr);
    friend std::ostream& operator <<(std::ostream&, const Person&);
    static Person GetEva();
    static Person GetAdam();
    virtual ~Person();
    void out();
private:
    Person();
    std::string name_;
    Genders gender_;
    std::string status_;
    Person* mother_ = nullptr;
    Person* father_ = nullptr;
    std::vector <Person*> children_;
    static Person HolySpirit;
    static Person CreateEva(Person &Eva);
    static Person CreateAdam(Person &Adam);
    Person(Genders, std::string&, Person* = nullptr, Person* = nullptr);

};
#endif //PERSON_PERSON_H
