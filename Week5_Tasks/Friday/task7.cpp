#include <iostream>
#include <algorithm>

int main()
{
    const int size = 9991;
    int arr[size];
    int startValue = 10;
    std::generate(arr, arr + size, [&startValue](){return startValue++;});
    for(int i : arr)
    {
        std::cout<<i<<" ";
        if(i % 10 == 0)
        {
            std::cout<<std::endl;
        }
    }

    return 0;
}