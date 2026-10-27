#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h>  //will be used for searching function
#include "sorting.h"

const int MAX_SIZE = 100;

int arr[MAX_SIZE];

void displayArr(int arr[]);

int main()
{
    std::cout << "Sorting Algorithms Testing: " << std::endl;
    //  create an array with unsorted list with 100 maximum size
    int unsortedArr[MAX_SIZE];
    // use the time (0) as seed for random values
    srand(time(0));
    // populate the array with random random values
    for (int i = 0; i < MAX_SIZE; i++)
    {
        unsortedArr[i] = rand() % 100;
    }
    displayArr(unsortedArr);

    std::cout << "bubbleSort Testing: " << std::endl;
    bubbleSort(unsortedArr, MAX_SIZE);
    displayArr(unsortedArr);

    std::cout << "selectionSort Testing: " << std::endl;
    selectionSort(unsortedArr, MAX_SIZE);
    displayArr(unsortedArr);

    std::cout << "insertionSort Testing: " << std::endl;
    insertionSort(unsortedArr, MAX_SIZE);
    displayArr(unsortedArr);

    std::cout << "insertionSortForLoop Testing: " << std::endl;
    insertionSortForLoop(unsortedArr, MAX_SIZE);
    displayArr(unsortedArr);
}
void displayArr(int arr[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
