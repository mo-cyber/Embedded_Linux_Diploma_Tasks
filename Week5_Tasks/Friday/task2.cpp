#include <iostream>
#include <algorithm>

int main()
{
    int size = 5;
    int arr[size];
    std::cout<<"Enter 5 array elements: ";
    // for (int i = 0; i < size; i++)
    // {
    //     std::cin>>arr[i];
    //     if(arr[i] % 2 == 1)
    //     {
    //         std::cout<<"Not all the array is even.";
    //         return 0;
    //     }
    // }
    // std::cout<<"All the array is even.";

    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    std::all_of(arr, arr + size, [](int i) {return i % 2 == 0;})?std::cout<<"All the array is even.":
                                                            std::cout<<"Not all the array is even.";

    return 0;
}