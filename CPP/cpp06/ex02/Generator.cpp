#include "Generator.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random = std::rand() % 3;

    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}