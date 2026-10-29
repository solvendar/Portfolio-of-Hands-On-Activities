
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include <vector>
#include <chrono>

// Linear Search
int search(std::vector<int> &arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

// Binary Search
int binarySearch(std::vector<int> &arr, int target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Worst-Case Binary Search
void testBinarySearch(int SIZE) {
    std::vector<int> dataset(SIZE);

    for (int i = 0; i < SIZE; i++)
        dataset[i] = i;

    int choice = SIZE;
    const int REPEAT = 10000;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < REPEAT; i++)
        binarySearch(dataset, choice, 0, SIZE - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;\
    std::cout << "\nInput Size (N): " << SIZE;
    std::cout << "\nElapsed Time (Average): " << duration.count() / REPEAT << " microseconds\n";
}

// Worst-Case Linear Search
void testLinearSearch(int SIZE) {
    std::vector<int> dataset(SIZE);

    for (int i = 0; i < SIZE; i++)
        dataset[i] = i;

    int choice = SIZE;
    const int REPEAT = 10000;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < REPEAT; i++)
        search(dataset, choice);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    std::cout << "\nInput Size (N): " << SIZE;
    std::cout << "\nElapsed Time (Average): " << duration.count() / REPEAT << " microseconds\n";
}

#endif
