#include <iostream>
#include <numeric>

int main()
{
    const int size = 5;
    int arr[5];
    int sum = 0;
    std::cout<<"Enter 5 elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin>>arr[i];
    }
    sum = std::accumulate(arr, arr + size, sum);
    std::cout<<"Sum of array = "<<sum;

    return 0;
}