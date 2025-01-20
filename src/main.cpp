#include "header.hpp"

extern const int g_number;
// extern constexpr int g_number; // Error! Forwards constexpr is not allowed

int main() {
    std::cout << "The g_number: " << g_number << std::endl;

    Example example1;
    example1.Print();

    // Print as example1
    example1.AccessNumber();

    // Print as example2
    Example example2;
    example2.AccessNumber();

    return 0;
}
