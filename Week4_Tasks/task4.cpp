#include <iostream>

int main()
{
    int size1 = 5, size2 = 5;
    int size3 = size1 + size2;
    int arr1[size1], arr2[size2], arrMerged[size3];
    int mergedIndex = 0;
    std::cout<<"Enter 5 elements of first array: ";
    for(int i = 0; i < size1; i++)
    {
        std::cin>>arr1[i];
        arrMerged[mergedIndex] = arr1[i];
        mergedIndex++;
    }
    std::cout<<"Enter 5 elements of second array: ";
    for(int i = 0; i < size2; i++)
    {
        std::cin>>arr2[i];
        arrMerged[mergedIndex] = arr2[i];
        mergedIndex++;
    }
    std::cout<<"Merged array: ";
    for(int i = 0; i < size3; i++)
    {
        std::cout<<arrMerged[i]<<" ";
    }
    return 0;
}