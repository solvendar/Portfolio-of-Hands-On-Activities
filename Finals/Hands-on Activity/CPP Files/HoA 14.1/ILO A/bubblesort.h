#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <utility>

// Function to perform Bubble Sort
template <typename T>
void bubbleSort(T arr[], int maxSize){

    for(int i = 0; i < maxSize; i++){
        for(int j = i + 1; j < maxSize; j++){
            if(arr[i]>arr[j]){
                std::swap(arr[j],arr[i]);
            }
        }
    }
}

#endif
