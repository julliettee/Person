#include "Person.h"

static long GlobalID = 0;
std::set <std::string> Genders = {"male", "female"};


// region help-functions
void Person::out(){
    std::cout << "Id: " << id_ << std::endl;
    std::cout << "Gender: " << gender_ << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Status: " << status_ << std::endl;
}
// endregion

// region Constructor
Person::Person(std::string gender, std::string name, Person* mother, Person* father){
    if (Genders.find(gender) == Genders.end()){
        throw std::exception("Wrong value of gender.");
    }
    if (mother != nullptr){
        Person person = *mother;
        if (person.gender_ == "male"){
            throw std::exception("Man can't give birth.");
        }
    }
    if (father != nullptr){
        Person person = *father;
        if (person.gender_ == "female"){
            throw std::exception("The gender of father should be 'male'.");
        }
    }
    id_ = GlobalID++;
    name_ = name;
    gender_ = gender;
    status_ = "Alive";
    mother_ = mother;
    father_ = father;
}
// endregion
// region destructor
Person::~Person(void) = default;
// endregion

