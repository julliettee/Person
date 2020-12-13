#include "Person.h"

int main() {
    try {
        //Person::GetEva();
        Person Eva = Person::GetEva();
        Person Adam = Person::GetAdam();
        //Adam = Eva;
        Person Kain = Eva.GiveBirth(Genders::male, "Kain", &Adam);
        Person Avel = Eva.GiveBirth(Genders::male, "Avel", &Adam);
        std::cout << Kain.GetName() << std::endl;
        std::cout << Kain.GetGender() << std::endl;
        std::cout << Kain.GetStatus() << std::endl;
        Kain.Death(&Avel);
        Kain.GetParents();
        Eva.GetChildren(&Adam);
        //std::cout << Kain;
        Adam.out();
        Adam.GetChildren();
    }
    catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        exit(-1);
    }
    return 0;
}


