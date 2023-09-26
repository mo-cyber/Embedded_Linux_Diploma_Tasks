#include <iostream>
#include <algorithm>

int main()
{
    int size = 5;
    int arr[size];
    std::cout<<"Enter 5 array elements: ";
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    std::all_of(arr, arr + size, [](int i) {return i % 2 ==1;})?std::cout<<"No even value in the array":
                                                    std::cout<<"There is even value in the array";

    return 0;
}