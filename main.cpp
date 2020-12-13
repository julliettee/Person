#include "Person.h"

int main() {
    try{
        Person Eva = Person::GetEva();
        Person Adam = Person::GetAdam();
        Person Kain = Eva.GiveBirth("male", "Kain", &Adam);
        Person Avel = Person(Eva);
        Kain.Death(&Avel);
        Kain.GetParents();
        Kain.out();
    }
    catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;
        exit(-1);
    }

    return 0;
}


