#include <iostream>

#include <factorial.hpp>

int main(int, char**) {
    factorial::calculator fact{};
    std::cout << fact(20) << std::endl;
}
