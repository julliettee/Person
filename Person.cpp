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


// region FirstPeople
bool EvaCreation = false;
bool AdamCreation = false;
bool EvaGetting = false;
bool AdamGetting = false;
void Person::SetEva(std::string gender, std::string name) {
    if (EvaCreation){
        throw std::exception("Person Eva already created.");
    }
    id_ = GlobalID++;
    gender_ = gender;
    name_ = name;
    status_ = "Alive";
}
Person CreateEva(Person &Eva){
    Eva.SetEva("female", "Eva");
    EvaCreation = true;
    return Eva;
}
void Person::SetAdam(std::string gender, std::string name) {
    if (AdamCreation){
        throw std::exception("Person Adam already created.");
    }
    id_ = GlobalID++;
    gender_ = gender;
    name_ = name;
    status_ = "Alive";
}
Person CreateAdam(Person &Adam){
    Adam.SetAdam("male", "Adam");
    AdamCreation = true;
    return Adam;
}
static Person CreateGod(Person &God){
    return God;
}
Person God = CreateGod(God);
static Person Adam = CreateAdam(God);
static Person Eva = CreateEva(God);

Person Person::GetEva() {
    if (EvaGetting){
        throw std::exception("Person Eva already created.");
    }
    EvaGetting = true;
    return Eva;
}
Person Person::GetAdam() {
    if (AdamGetting){
        throw std::exception("Person Adam already created.");
    }
    AdamGetting = true;
    return Adam;
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

