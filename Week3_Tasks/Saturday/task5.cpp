#include <iostream>

int main()
{
    std::cout<<"Multiplication Table:"<<std::endl;
    std::cout<<"+--+--+--+"<<std::endl;
    std::cout<<"|n1|n2|eq|"<<std::endl;
    std::cout<<"+--+--+--+"<<std::endl;
    for(int i = 0; i <= 9; i++)
    {
        std::cout<<i<<"'s Table"<<std::endl;
        std::cout<<"----------"<<std::endl;
        for(int j = 0; j <= 9; j++)
        {
            std::cout<<i<<" x "<<j<<" = "<<i*j<<std::endl;
        }
        std::cout<<"----------"<<std::endl;
    }

    return 0;
}