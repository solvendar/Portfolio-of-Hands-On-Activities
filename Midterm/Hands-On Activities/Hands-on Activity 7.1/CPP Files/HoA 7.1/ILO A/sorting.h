#ifndef SORTING_H
#define SORTING_H
#include <iostream>
template <typename T>
void bubbleSort(T arr[], int MAX_SIZE)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
int routineSmallest(T arr[], int K, int MAX_SIZE)
{
    int position;
    T smallestElem = arr[K];
    position = K;
    for (int j = K + 1; j < MAX_SIZE; j++)
    {
        if (arr[j] < smallestElem)
        {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int MAX_SIZE)
{
    int POS;
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        POS = routineSmallest(arr, i, MAX_SIZE);
        std::swap(arr[i], arr[POS]);
    }
}
// insertion sort while loop
template <typename T>
void insertionSort(T arr[], int MAX_SIZE)
{
    int k = 1, j, temp;
    while (k < MAX_SIZE)
    {
        temp = arr[k];
        j = k - 1;
        while (temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

// insertion sort for loop
template <typename T>
void insertionSortForLoop(T arr[], int MAX_SIZE)
{
    for (int k = 1; k < MAX_SIZE; k++)
    {
        T temp = arr[k];
        int j = k - 1;
        for (int j = k - 1; j >= 0 && temp <= arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
#endif