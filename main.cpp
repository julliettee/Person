#include "Person.h"

int main() {
    try {
        Person Eva = Person::GetEva();
        Person Adam = Person::GetAdam();
        Person Kain = Eva.GiveBirth(Person::Genders::male, "Kain", &Adam);
        Person Avel = Eva.GiveBirth(Person::Genders::male, "Avel", &Adam);
        Kain.Death(&Avel);
        std::cout <<"All about Kain: " << std::endl << Kain;
        std::cout << std::endl;
        std::cout <<"All about Eva: " << std::endl << Eva;
        std::cout << std::endl;
        Eva.GetChildren(&Adam);
        std::cout << std::endl;
        std::cout << "All about Adam:" << std::endl;
        Adam.out();
        Adam.GetChildren();
    }
    catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        exit(-1);
    }
    return 0;
}


