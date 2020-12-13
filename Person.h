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
    Person();
    Person(const Person&);
    std::string GetGender() const;
    std::string GetStatus() const;
    std::string GetName() const;
    void Death(Person* = nullptr);
    void GetParents();
    void GetChildren();
    void GetChildren(Person*);
    Person& operator =(Person const& other);
    Person GiveBirth(Genders, std::string, Person*);
    friend std::ostream& operator <<(std::ostream&, const Person&);
    static Person GetEva();
    static Person GetAdam();
    virtual ~Person();
    void out();
private:
    long id_ = -1;
    bool clone_ = true;
    std::string name_;
//    std::string gender_;
    Genders gender_;
    std::string status_;
    Person* mother_ = nullptr;
    Person* father_ = nullptr;
    std::vector <Person*> children_;
    static Person Adam;
    static Person Eva;
    static Person CreateEva(Person &Eva);
    static Person CreateAdam(Person &Adam);
    Person(Genders, std::string, Person* = nullptr, Person* = nullptr, bool clone = true);

};
#endif //PERSON_PERSON_H
