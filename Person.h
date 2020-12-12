#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include <string>

class Person{
public:

private:
    long id;
    std::string name;
    Person* mother;
    Person* father;
};
#endif //PERSON_PERSON_H
