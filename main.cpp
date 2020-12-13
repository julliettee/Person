#include "Person.h"

int main() {
    try{
        Person Adam = Person::GetAdam();
        Person Eva = Person::GetEva();
        Adam.out();
        Eva.out();

    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        exit(-1);
    }

    return 0;
}


