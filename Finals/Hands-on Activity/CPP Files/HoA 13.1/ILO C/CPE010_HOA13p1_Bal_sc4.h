
#ifndef CPE010_HOA13P1_BRAGANZA_SC4_H
#define CPE010_HOA13P1_BRAGANZA_SC4_H

#include <iostream>
#include <thread> // Added to use std::thread for multithreading

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

/*
A.2. Merge Sort
General Algorithm
The general pseudo-code for the merge sort technique is given below.
Declare an array Arr of length N
If N=1, Arr is already sorted
If N>1,
Left = 0, right = N-1
Find middle = (left + right)/2
Call merge_sort(Arr,left,middle) =>sort first half recursively
Call merge_sort(Arr,middle+1,right) => sort second half recursively
Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.
Exit
*/

// Merge Sort (CREDITS TO PROGRAMIZ)

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
    // Create L <- A[p..q] and M <- A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];

    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = p;

    // Until we reach either end of either L and M, pick the smaller element
    // and place it in the correct position in the main array
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from L
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements from M
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] M;
}

// Original single-threaded Merge Sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Find the middle point to divide the array
        int m = l + (r - l) / 2;

        // Sort both halves recursively using the original algorithm
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// MODFIED PART
void parallelMergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // MODFIED
        // Create two threads to sort separate halves of the array
        // Each thread runs the original mergeSort() function
        std::thread T1(mergeSort, arr, l, m);
        std::thread T2(mergeSort, arr, m + 1, r);

        // MODFIED
        // Wait for both threads to finish sorting their halves
        T1.join();
        T2.join();

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

#endif
