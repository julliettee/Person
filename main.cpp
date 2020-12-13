#include "Person.h"

int main() {
    try{
        Person Eva = Person::GetEva();
        Person Adam = Person::GetAdam();
        Person Kain = Eva.GiveBirth("male", "Kain", &Adam);
        Person Avel = Eva.GiveBirth("male", "Avel", &Adam);
        Kain.Death(&Avel);
        Kain.Death();
        Kain.out();
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        exit(-1);
    }

    return 0;
}


