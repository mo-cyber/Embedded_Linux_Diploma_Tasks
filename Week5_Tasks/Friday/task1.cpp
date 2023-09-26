#include <iostream>

int main()
{
    char ch;
    std::cout<<"Enter a character: ";
    std::cin>>ch;
    // if(ch >= 48 && ch <= 57)
    // {
    //     std::cout<<"It is a digit.";
    // }
    // else
    // {
    //     std::cout<<"It is not a digit.";
    // }
    if(isdigit(ch))
    {
        std::cout<<"It is a digit.";
    }
    else
    {
        std::cout<<"It is not a digit.";
    }

    return 0;
}