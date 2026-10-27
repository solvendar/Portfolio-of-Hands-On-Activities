#ifndef SUPP_H
#define SUPP_H
#include <iostream>

template <typename T>
void selectionSort(T arr[], int MAX_SIZE)
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        int POS = i; // assume the current index position has the smallest number / value
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            if (arr[j] < arr[POS])
            {
                POS = j; // update the index position if a smaller number is found
            }
        }
        std::swap(arr[i], arr[POS]); // swap the smallest number into the correct index position
    }
}
#endif
