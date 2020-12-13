#include "Person.h"

int main() {
    try{
        Person Eva = Person::GetEva();
        Person Adam = Person::GetAdam();
        Eva = Eva;
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        exit(-1);
    }

    return 0;
}


