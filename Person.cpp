#include "Person.h"

static long GlobalID = 0;
std::set<std::string> Genders = {"male", "female"};

// region help-functions
void Person::out(){
    std::cout << "Id: " <<  id_ << std::endl;
    std::cout << "Name: " <<  name_ << std::endl;
    std::cout << "Gender: " <<  gender_ << std::endl;
    if (id_ > 1) {
        long mother_id = (*mother_).id_;
        std::cout << "Mother: " << mother_id << std::endl;
        long father_id = (*father_).id_;
        std::cout << "Father: " << father_id << std::endl;
    }
}
// endregion
// region Birth
Person::Person(std::string gender, std::string name, Person* mother, Person* father){
    if (Genders.find(gender) == Genders.end()){
        throw std::exception("Wrong value!");
    }
    if (GlobalID > 1){
        if (mother == nullptr){
            throw std::exception("Who is the mother of this person?");
        }
    }
    id_ = GlobalID++;
    gender_ = gender;
    //status_ = "alive";
    name_ = name;
    mother_ = mother;
    father_ = father;
}

// endregion
