#include "header.hpp"

extern const int g_number = 24;
extern constexpr int g_number_2 = 48;

void Example::Print() { std::cout << "Hello World." << std::endl; }

void Example::AccessNumber() const { std::cout << "The static number is now: " << number++ << std::endl; }

void Example::ConstMemFn() const {
    // memberVar = 2; // Error! Const member function cannot make changes to object.
}
