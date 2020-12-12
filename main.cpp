#include "Person.h"

const std::string Male = "male";
const std::string Female = "female";
const std::string NameEva = "Eva";
const std::string NameAdam = "Adam";
int main() {
    try{
        Person Adam = Person(Male, NameAdam);
        Person Eva = Person(Female, NameEva);
        Person Kain = Person(Male, "Kain");
        Adam.out();
        Eva.out();
        Kain.out();
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}


