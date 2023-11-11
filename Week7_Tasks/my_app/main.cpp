#include <iostream>

// Declare the function defined in the library
extern void hello();

int main() {
    std::cout << "Starting my_app..." << std::endl;
    hello();  // Call the function from the shared library
    return 0;
}
