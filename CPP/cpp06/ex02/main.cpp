#include <iostream>
#include "Base.hpp"
#include "A.hpp"

int main() {
    Base* instance = generate();
    
    identify(instance);
    identify(*instance);
    
    delete instance; // Clean up dynamically allocated memory
    return 0;
}