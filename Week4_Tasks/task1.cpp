#include <iostream>
#include <algorithm>

int maxArray(int arr[], int size)
{
    return (*std::max_element(arr, arr + size));
}

int main()
{
    int arr[5], size = 5, max;
    std::cout<<"Enter 5 elements of an array: ";
    for (int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }
    max = maxArray(arr,size);
    std::cout<<"Max number = "<<max;

    return 0;
}