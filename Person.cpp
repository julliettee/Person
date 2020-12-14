#include "Person.h"

typedef std::pair<Person *, Person *> Couple;
long AntiCloneProtection = 0;
long GlobalID = 0;
static std::map<Person *, Person *> AllDeath;
static std::map<Couple, std::vector<Person *>> ChildrenOfCouple;

// region help-functions
void Person::out() {
    std::cout << "Id: " << id_ << std::endl;
    std::cout << "Gender: " << (this->GetGender()) << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Status: " << (this->GetStatus()) << std::endl;
    if (status_ == Status::dead) {
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
    return (status_ == Status::alive ? "Alive" : "Dead");
}
// endregion
// region FirstPeople
bool EvaGetting = false;
bool AdamGetting = false;
bool HaveGod = false;
Person Person::HolySpirit;
Person Person::CreateEva(Person& Eva) {
    Eva.id_ = GlobalID++;
    Eva.gender_ = Genders::female;
    Eva.name_ = "Eva";
    Eva.status_ = Status::alive;
    return Eva;
}
Person Person::CreateAdam(Person& Adam) {
    Adam.id_ = GlobalID++;
    Adam.gender_ = Genders::male;
    Adam.name_ = "Adam";
    Adam.status_ = Status::alive;
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
    id_ = GlobalID++;
    status_ = Status::alive;
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
    id_ = other.id_;
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
    else {
        throw std::exception("Mother can't be empty.");
    }
    if (father != nullptr) {
        if (father -> gender_ == Genders::female) {
            throw std::exception("The gender of father should be 'male'.");
        }
    }
    id_ = GlobalID++;
    name_ = name;
    gender_ = gender;
    status_ = Status::alive;
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
    throw std::exception("You can't make assignment. No clone army is allowed");
}
std::ostream& operator<<(std::ostream& out, const Person& other) {
    out << other.name_;
    out << "(" << other.id_ << ", " <<  other.GetGender() << ", " << other.GetStatus() << ")" << std::endl;
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
    if (status_ == Status::dead || (father != nullptr && father -> status_ == Status::dead)) {
        throw std::exception("Dead person can't give birth.");
    }
    return Person(gender, name, this, father);
}

void Person::Death(Person *killer) {
    if (status_ == Status::dead) {
        throw std::exception("This person already dead.");
    }
    if (killer != nullptr) {
        if (killer -> status_ == Status::dead) {
            throw std::exception("Killer already dead.");
        }
    }
    AllDeath[this] = killer;
    status_ = Status::dead;
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
            std::cout << child -> name_ << "(" << child -> GetGender() << ", " << child -> GetStatus() << ")" << std::endl;
        }
    }
}
// endregion
// region destructor
Person::~Person(void) = default;
// endregion

