#include <iostream>
#include <bitset>

int main()
{
    int decimal;
    std::string binary;
    unsigned long binaryConversion;
    std::cout<<"Enter a decimal number: ";
    std::cin>>decimal;
    std::bitset<8> decimaltobinary(decimal);
    std::cout<<"Binary representation: "<<decimaltobinary<<std::endl;
    std::cout<<"Enter 8-bit binary number: ";
    std::cin>>binary;
    std::bitset<8> binarytodecimal(binary);
    binaryConversion = binarytodecimal.to_ulong();
    std::cout<<"Decimal representation: "<<binaryConversion;

    return 0;
}