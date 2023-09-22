#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;
    [n]()
    {
        std::cout<<"Square of "<<n<<" : "<<pow(n,2);
    }();

    return 0;
}