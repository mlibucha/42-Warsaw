#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identifier.hpp"
#include <iostream>

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}