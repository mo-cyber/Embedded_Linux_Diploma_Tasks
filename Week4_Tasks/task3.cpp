#include <iostream>

int main()
{
    int size = 10, numberDeleted;
    int arr[size];
    std::cout<<"Enter 10 elements of an array: ";
    for(int i = 0; i<size; i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"Enter the number you want to delete: ";
    std::cin>>numberDeleted;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == numberDeleted)
        {
            size--;
            for(int j = i; j < size; j++)
            {
                arr[j] = arr[j+1];
            }
            i--;
        }
    }
    if (size == 10)
    {
        std::cout<<"The number you want to delete is not found";
    }
    else
    {
        std::cout<<"Deleted array: ";
        for(int i = 0; i < size; i++)
        {
            std::cout<<arr[i]<<" ";
        }
    }
    return 0;
}