#include <iostream>
#include <algorithm>

int main()
{
    int size = 5;
    int arr[size];

    std::cout<<"Enter 5 elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }

    [&arr, size]()
    {
        std::sort(arr, arr + size);
    }();
    std::cout<<"Array after ascending order: ";
    for(int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<" ";
    }

    [&arr, size]()
    {
        std::sort(arr, arr + size, std::greater<int>());
    }();
    std::cout<<std::endl<<"Array after descending order: ";
    for(int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}