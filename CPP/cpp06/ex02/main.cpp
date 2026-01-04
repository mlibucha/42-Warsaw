#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "Generator.hpp"
#include "Identifier.hpp"

int main() {
    Base* instance = generate();
    
    identify(instance);
    identify(*instance);
    
    delete instance;
    return 0;
}