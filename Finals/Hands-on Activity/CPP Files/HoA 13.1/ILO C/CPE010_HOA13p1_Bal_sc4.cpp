#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>                   // Modified Added for measuring execution time
#include "CPE010_HOA13p1_Bal_sc4.h" //Modified the name

const int SIZE = 100;

int main()
{

    // Array of size 100 to hold random integers
    int arr[SIZE];

    // MODIFIED
    // Added a second array to keep the original unsorted values
    // for the multithreaded version
    int arr2[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;

        // MODIFIED
        // Copy each random number into the second array
        arr2[i] = arr[i];
    }

    std::cout << "Original Array:" << std::endl;
    displayArray(arr, SIZE);

    // Original single-threaded Merge Sort
    // MODIFIED
    // Measure the execution time using chrono
    auto start1 = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, SIZE - 1);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);

    std::cout << "\n\nSingle-Threaded Merge Sort:" << std::endl;
    displayArray(arr, SIZE);
    std::cout << "\nExecution Time: " << duration1.count() << " microseconds" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    parallelMergeSort(arr2, 0, SIZE - 1);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);

    std::cout << "\n\nMultithreaded Merge Sort:" << std::endl;
    displayArray(arr2, SIZE);
    std::cout << "\nExecution Time: " << duration2.count() << " microseconds" << std::endl;

    return 0;
}
