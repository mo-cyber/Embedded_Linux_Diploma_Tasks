#include <iostream>

int main()
{
    int a = 10, b = 30;
    if(a < 20 and a > 5)
    {
        std::cout<<"a smaller than 20 and bigger than 5."<<std::endl;
    }
    if(b < 20 or a > 20)
    {
        std::cout<<"b smaller than 20 or a bigger than 20"<<std::endl;
    }

    return 0;
}