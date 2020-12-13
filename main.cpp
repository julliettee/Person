#include "Person.h"

int main() {
    try{
        Person Adam = Person::GetAdam();
        Person Eva = Person::GetEva();
        Person Kain = Eva.GiveBirth("male", "Kain", &Adam);
        Person Avel = Eva.GiveBirth("male", "Avel", &Adam);
        Kain.out();
        Avel.out();

    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        exit(-1);
    }

    return 0;
}


