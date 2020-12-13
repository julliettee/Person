#include "Person.h"

typedef std::pair<Person *, Person *> Couple;
long AntiCloneProtection = 0;
std::map<Person *, Person *> AllDeath;
std::map<Couple, std::vector<Person *>> ChildrenOfCouple;


// region help-functions
void Person::out() {
    std::cout << "Gender: " << (this->GetGender()) << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Status: " << status_ << std::endl;
    if (status_ == "Dead") {
        if (AllDeath[this] == nullptr) {
            std::cout << "Unknown reason of death" << std::endl;
        } else {
            std::cout << "Killed by " << AllDeath[this] -> name_ << std::endl;
        }
    }
}
// endregion
// region Getters
std::string Person::GetGender() const {
    return (gender_ == Genders::male ? "male" : "female");
}
std::string Person::GetName() const{
    return name_;
}
std::string Person::GetStatus() const{
    return status_;
}
// endregion
// region FirstPeople
bool EvaGetting = false;
bool AdamGetting = false;
bool HaveGod = false;
Person Person::HolySpirit;
Person Person::CreateEva(Person& Eva) {
    Eva.gender_ = Genders::female;
    Eva.name_ = "Eva";
    Eva.status_ = "Alive";
    return Eva;
}
Person Person::CreateAdam(Person& Adam) {
    Adam.gender_ = Genders::male;
    Adam.name_ = "Adam";
    Adam.status_ = "Alive";
    return Adam;
}
Person Person::GetEva() {
    if (EvaGetting) {
        throw std::exception("Person Eva already created.");
    }
    EvaGetting = true;
    AntiCloneProtection++;
    return CreateEva(HolySpirit);
}
Person Person::GetAdam() {
    if (AdamGetting) {
        throw std::exception("Person Adam already created.");
    }
    AdamGetting = true;
    AntiCloneProtection++;
    return CreateAdam(HolySpirit);
}
// endregion
// region Constructor
Person::Person() {
    if (HaveGod) {
        throw std::exception("You can't create God.");
    }
    gender_ = Genders::female;
    HaveGod = true;
}

Person::Person(const Person& other) {
    if (this == &other) {
        throw std::exception("You can't do it");
    }
    if (AntiCloneProtection > 0) {
        AntiCloneProtection--;
    } else {
        throw std::exception("Stop making clone army");
    }
    std::cerr << "&";
    name_ = other.name_;
    gender_ = other.gender_;
    status_ = other.status_;
    mother_ = other.mother_;
    father_ = other.father_;
}

Person::Person(Genders gender, std::string& name, Person *mother, Person *father) {
    if (name.empty()) {
        throw std::exception("Name can't be empty.");
    }
    if (mother != nullptr) {
        if (mother -> gender_ == Genders::male) {
            throw std::exception("The gender of mother should be 'female'.");
        }
    }
    if (father != nullptr) {
        if (father -> gender_ == Genders::female) {
            throw std::exception("The gender of father should be 'male'.");
        }
    }
    name_ = name;
    gender_ = gender;
    status_ = "Alive";
    mother_ = mother;
    father_ = father;
    (mother->children_).push_back(this);
    if (father != nullptr) {
        (father->children_).push_back(this);
        ChildrenOfCouple[std::make_pair(mother, father)].push_back(this);
        ChildrenOfCouple[std::make_pair(father, mother)].push_back(this);
    }
}
// endregion
// region Operator
Person& Person::operator = (Person const& other) {
    if (this == &other) {
        throw std::exception("You can't do it.");
    }
    name_ = other.name_;
    gender_ = other.gender_;
    status_ = other.status_;
    mother_ = other.mother_;
    father_ = other.father_;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Person& other) {
    out << other.name_;
    out << "(" << other.GetGender() << ", " << other.status_ << ")" << std::endl;
    out << "Parents:" << std::endl;
    out << "Mother ";
    if (other.mother_ == nullptr) {
        out << "Unknown, ";
    } else {
        out << (other.mother_)->name_ << ", ";
    }
    out << "Father ";
    if (other.father_ == nullptr) {
        out << "Unknown ";
    } else {
        out << (other.father_)->name_ << " ";
    }
    out << std::endl;
    return out;
}
// endregion
// region Actions
Person Person::GiveBirth(Genders gender, std::string name, Person *father) {
    if (status_ == "Dead" || (father != nullptr && father -> status_ == "Dead")) {
        throw std::exception("Dead person can't give birth.");
    }
    return Person(gender, name, this, father);
}

void Person::Death(Person *killer) {
    if (status_ == "Dead") {
        throw std::exception("This person already dead.");
    }
    if (killer != nullptr) {
        if (killer -> status_ == "Dead") {
            throw std::exception("Killer already dead.");
        }
    }
    AllDeath[this] = killer;
    status_ = "Dead";
}
void Person::GetParents() {
    if (mother_ == nullptr) {
        std::cout << "Unknown mother" << std::endl;
    } else {
        std::cout << mother_ -> name_ << " is mother" << std::endl;
    }
    if (father_ == nullptr) {
        std::cout << "Unknown father" << std::endl;
    } else {
        std::cout << father_ -> name_ << " is father" << std::endl;
    }
}

void Person::GetChildren() {
    if (children_.empty()) {
        std::cout << "There are no children of this person" << std::endl;
    } else {
        std::cout << "Children of " << name_ << ":" << std::endl;
        for (auto child: children_) {
            std::cout << *child;
        }
    }
}

void Person::GetChildren(Person *parent) {
    Couple couple = std::make_pair(this, parent);
    if (ChildrenOfCouple.find(couple) == ChildrenOfCouple.end()) {
        std::cout << "There are no children of this couple" << std::endl;
    } else {
        std::cout << "Children of " << name_ << " and " << parent->name_ << ":" << std::endl;
        for (auto child: ChildrenOfCouple[couple]) {
            std::cout << *child;
        }
    }
}
// endregion
// region destructor
Person::~Person(void) = default;
// endregion

