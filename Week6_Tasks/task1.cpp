#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cout<<"Enter a string: ";
    getline(std::cin, str);
    std::cout<<str;

    return 0;
}