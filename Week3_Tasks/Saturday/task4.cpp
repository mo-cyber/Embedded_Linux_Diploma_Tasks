#include <iostream>
#include <string>

//using namespace std;

int main()
{
    std::string vowel = "aeiouAEIOU";
    char a;
    std::cout<<"Enter a character: ";
    std::cin>>a;
    if (vowel.find(a) != std::string::npos)
    {
        std::cout<<a<<" is a vowel.";
    }
    else
    {
        std::cout<<a<<" is not a vowel.";
    }

    return 0;
}