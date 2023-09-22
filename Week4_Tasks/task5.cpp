#include <iostream>

int main()
{
    int size = 5;
    int arr[size];
    std::cout<<"Enter 5 elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            std::cout<<arr[i]<<" even"<<std::endl;
        }
        else
        {
            std::cout<<arr[i]<<" odd"<<std::endl;
        }
    }

    return 0;
}