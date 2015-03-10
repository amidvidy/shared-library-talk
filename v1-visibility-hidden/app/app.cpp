#include <iostream>

#include <factorial.hpp>

int main(int, char**) {
    factorial::calculator fact{factorial::options{}};

    std::cout << fact(20) << std::endl;
}
