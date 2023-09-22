#include <iostream>

int searchNumber(int arr[], int size, int num)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5], size = 5, number, numberIndex;
    std::cout<<"Enter 5 elements of the array: ";
    for(int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"Enter the number you need to search: ";
    std::cin>>number;
    numberIndex = searchNumber(arr, size, number);
    if(numberIndex == -1)
    {
        std::cout<<"Number not found";
    }
    else
    {
        std::cout<<"Number index is "<<numberIndex;
    }
    return 0;
}