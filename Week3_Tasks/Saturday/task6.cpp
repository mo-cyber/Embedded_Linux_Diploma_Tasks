#include <iostream>

int main()
{
    int num, sum = 0;
    std::cout<<"Enter an integer: ";
    std::cin>>num;
    std::string numStr = std::to_string(num);
    for(char ch : numStr)
    {
        int digit = ch - '0';
        sum += digit;
    }
    std::cout<<"Summation = "<<sum;

    return 0;
}