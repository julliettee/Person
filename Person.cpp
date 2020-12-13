#include "Person.h"

static long GlobalID = 0;
long capacity = 2;
std::set <std::string> Genders = {"male", "female"};
std::map<Person*, Person*> AllDeath;
std::map <std::pair<Person*, Person*>,  std::vector<Person*>> ChildrenOfCouple;

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
            std::cout << "Killed by " << (*AllDeath[this]).name_ << std::endl;
        }
    }
}
// endregion
// region FirstPeople
bool EvaGetting = false;
bool AdamGetting = false;
bool HaveGod = false;

Person Person::CreateEva(Person &Eva) {
    Eva.id_ = GlobalID++;
    Eva.gender_ = "female";
    Eva.name_ = "Eva";
    Eva.status_ = "Alive";
    Eva.clone_ = true;
    return Eva;
}

Person Person::CreateAdam(Person &Adam) {
    Adam.id_ = GlobalID++;
    Adam.gender_ = "male";
    Adam.name_ = "Adam";
    Adam.status_ = "Alive";
    Adam.clone_ = true;
    return Adam;
}

Person HolySpirit;
Person Person::Adam = CreateAdam(HolySpirit);
Person Person::Eva = CreateEva(HolySpirit);


Person Person::GetEva() {
    if (EvaGetting){
        throw std::exception("Person Eva already created.");
    }
    EvaGetting = true;
    capacity++;
    return Eva;
}
Person Person::GetAdam() {
    if (AdamGetting){
        throw std::exception("Person Adam already created.");
    }
    AdamGetting = true;
    capacity++;
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
    if (clone_){
        if (capacity){
            capacity--;
        }
        else{
            throw std::exception("Stop making clone army");
        }
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
        if ((*mother).gender_ == "male"){
            throw std::exception("The gender of mother should be 'female'.");
        }
    }
    if (father != nullptr){
        if ((*father).gender_ == "female"){
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
    (mother -> children_).push_back(this);
    (father -> children_).push_back(this);
    ChildrenOfCouple[std::make_pair(mother, father)].push_back(this);
    ChildrenOfCouple[std::make_pair(father, mother)].push_back(this);
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
std::ostream& operator <<(std::ostream& out, const Person& other){
    out << other.name_;
    out << "(" << other.id_ <<", " << other.gender_ << ", " << other.status_ << ")" << std::endl;
    out << "Parents:" << std::endl;
    out << "Mother ";
    if (other.mother_ == nullptr){
        out << "Unknown, ";
    }
    else{
        out << (other.mother_) -> name_ << ", ";
    }
    out  << "Father ";
    if (other.father_ == nullptr){
        out << "Unknown ";
    }
    else{
        out << (other.father_) -> name_ << " ";
    }
    out << std::endl;
    return out;
}
// endregion
// region Actions
Person Person::GiveBirth(std::string gender, std::string name, Person *father) {
    if ((*this).status_ == "Dead" || (*father).status_ == "Dead"){
        throw std::exception("Dead person can't give birth.");
    }
    return Person(gender, name, this, father, false);
}
void Person::Death(Person* killer) {
    if ((*this).status_ == "Dead"){
        throw std::exception("This person already dead.");
    }
    if (killer != nullptr){
        if ((*killer).status_ == "Dead"){
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
        std::cout << (*mother_).name_ << " is mother" << std::endl;
    }
    if (father_ == nullptr){
        std::cout << "Unknown father" << std::endl;
    }
    else{
        std::cout << (*father_).name_ << " is father" << std::endl;
    }
}
void Person::GetChildren() {
    if ((this -> children_).empty()){
        std::cout << "There are no children of this person" << std::endl;
    }
    else{
        std::cout << "Children of " << (this -> name_) << ":" << std::endl;
        for(auto child: children_){
            std::cout << *child;
        }
    }
}
void Person::GetChildren(Person* parent) {
    if (ChildrenOfCouple.find(std::make_pair(this, parent)) == ChildrenOfCouple.end()){
        std::cout << "There are no children of this couple" << std::endl;
    }
    else{
        std::cout << "Children of " << (this -> name_) <<  " and " << (parent->name_) << ":" << std::endl;
        for(auto child: ChildrenOfCouple[std::make_pair(this, parent)]){
            std::cout << *child;
        }
    }
}
// endregion
// region destructor
Person::~Person(void) = default;
// endregion

