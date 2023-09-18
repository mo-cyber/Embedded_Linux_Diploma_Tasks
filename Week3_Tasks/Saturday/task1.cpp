#include <iostream>
int main(){
    std::cout<<"ASCII Code Table:"<<std::endl;
    std::cout<<"+------+------+"<<std::endl;
    std::cout<<"| Char | ASCII |"<<std::endl;
    std::cout<<"+------+------+"<<std::endl;
    for(unsigned char i=0; i<=255; i++)
    {
        int n = i;
        if(i==255)
        {
            break;
        }
        std::cout<<"| "<<i<<" | "<<n<<" |"<<std::endl;
    }

    return 0;
}