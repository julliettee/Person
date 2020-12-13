#include "Person.h"

static long GlobalID = 0;
std::set <std::string> Genders = {"male", "female"};
std::map<Person*, Person*> AllDeath;

// region help-functions
void Person::out(){
    std::cout << "Id: " << id_ << std::endl;
    std::cout << "Gender: " << gender_ << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Status: " << status_ << std::endl;
    if (status_ == "Dead"){
        if (AllDeath[this] == nullptr){
            std::cout << "Unknown reason of death" <<std::endl;
        }
        else{
            Person killer = *AllDeath[this];
            std::cout << "Killed by " << killer.name_ << std::endl;
        }
    }
}
// endregion
// region FirstPeople
bool EvaCreation = false;
bool AdamCreation = false;
bool EvaGetting = false;
bool AdamGetting = false;
bool HaveGod = false;
void Person::SetEva(std::string gender, std::string name) {
    if (EvaCreation){
        throw std::exception("Person Eva already created.");
    }
    id_ = GlobalID++;
    gender_ = gender;
    name_ = name;
    status_ = "Alive";
    clone_ = true;
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
    clone_ = true;
}
Person CreateAdam(Person &Adam){
    Adam.SetAdam("male", "Adam");
    AdamCreation = true;
    return Adam;
}

Person HolySpirit;

static Person Adam = CreateAdam(HolySpirit);
static Person Eva = CreateEva(HolySpirit);

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
Person::Person(){
    if (HaveGod){
        throw std::exception("You can't create God.");
    }
    id_ = -1;
    gender_ = "None";
    HaveGod = true;
}
Person::Person(const Person& other){
    if (this == &other){
        throw std::exception("You can't do it");
    }
    id_ = other.id_;
    name_ = other.name_;
    gender_ = other.gender_;
    status_ = other.status_;
    mother_ = other.mother_;
    father_ = other.father_;
    clone_ = true;
}
Person::Person(std::string gender, std::string name, Person* mother, Person* father, bool clone){
    if (Genders.find(gender) == Genders.end()){
        throw std::exception("Wrong value of gender.");
    }
    if (name.empty()){
        throw std::exception("Name can't be empty.");
    }
    if (mother != nullptr){
        Person person = *mother;
        if (person.gender_ == "male"){
            throw std::exception("The gender of mother should be 'female'.");
        }
    }
    if (father != nullptr){
        Person person = *father;
        if (person.gender_ == "female"){
            throw std::exception("The gender of father should be 'male'.");
        }
    }
    if (clone){
        throw std::exception("You can't make army of clones.");
    }
    id_ = GlobalID++;
    name_ = name;
    gender_ = gender;
    status_ = "Alive";
    mother_ = mother;
    father_ = father;
    clone_ = true;
}
// endregion
// region Operator
Person& Person::operator = (Person const& other) {
    if (this == &other){
        throw std::exception("You can't do it.");
    }
    if (other.clone_){
        throw std::exception("You can't make army of clones.");
    }
    id_ = other.id_;
    name_ = other.name_;
    gender_ = other.gender_;
    status_ = other.status_;
    mother_ = other.mother_;
    father_ = other.father_;
    clone_ = true;
    return (*this);
}
// endregion
// region Actions
Person Person::GiveBirth(std::string gender, std::string name, Person *father) {
    Person mam = *this;
    Person dad = *father;
    if (mam.status_ == "Dead" || dad.status_ == "Dead"){
        throw std::exception("Dead person can't give birth.");
    }
    return Person(gender, name, this, father, false);
}
void Person::Death(Person* killer) {
    Person person = *this;
    if (person.status_ == "Dead"){
        throw std::exception("This person already dead.");
    }
    if (killer != nullptr){
        Person murder = *killer;
        if (murder.status_ == "Dead"){
            throw std::exception("Killer already dead.");
        }
    }
    AllDeath[this] = killer;
    status_ = "Dead";
}
void Person::GetParents() {
    if (mother_ == nullptr){
        std::cout << "Unknown mother" << std::endl;
    }
    else{
        Person mother = *mother_;
        std::cout << mother.name_ << " is mother" << std::endl;
    }
    if (father_ == nullptr){
        std::cout << "Unknown father" << std::endl;
    }
    else{
        Person father = *father_;
        std::cout << father.name_ << " is father" << std::endl;
    }
}
// endregion
// region destructor
Person::~Person(void) = default;
// endregion

