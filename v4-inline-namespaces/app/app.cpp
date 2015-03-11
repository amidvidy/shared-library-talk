#include <iostream>

#include <factorial.hpp>

int main(int, char**) {
    auto fact = factorial::calculator{};
    std::cout << fact(20) << std::endl;
}
