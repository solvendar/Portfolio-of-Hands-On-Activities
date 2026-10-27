#include <iostream>
#include "sort.h"
#include <cstdlib> // for generating random integers

const int maxSize = 100;

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
        if ((i + 1) % 20 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

int main()
{
    int unsortedArr[maxSize] = {};
    int shellSortArr[maxSize] = {};
    int mergeSortArr[maxSize] = {};
    int quickSortArr[maxSize] = {};

    // randomly generate an array of integers
    srand(612);
    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    for (int i = 0; i < maxSize; i++)
    {
        shellSortArr[i] = unsortedArr[i];
        mergeSortArr[i] = unsortedArr[i];
        quickSortArr[i] = unsortedArr[i];
    }

    // shell sort
    std::cout << "Shell Sort: \n";
    shellSort(shellSortArr, maxSize);
    displayArr(shellSortArr);

    // merge sort
    std::cout << "Merge Sort: \n";
    mergeSort(mergeSortArr, 0, maxSize - 1);
    displayArr(mergeSortArr);

    // quick sort
    std::cout << "Quick Sort: \n";
    quickSort(quickSortArr, 0, maxSize - 1);
    displayArr(quickSortArr);

    return 0;
}