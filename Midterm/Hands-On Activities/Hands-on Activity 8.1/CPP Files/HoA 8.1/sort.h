#ifndef SORT_H
#define SORT_H

template <typename T>
void shellSort(T data[], int maxSize)
{
    for (int gap = maxSize / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < maxSize; i++)
        {
            T temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
            {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

// helper function for mergeSort
template <typename T>
void merge(T data[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T *L = new T[n1];
    T *R = new T[n2];
    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            data[k++] = L[i++];
        else
            data[k++] = R[j++];
    }
    while (i < n1)
        data[k++] = L[i++];
    while (j < n2)
        data[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T data[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

// helper function for quickSort
template <typename T>
int partition(T data[], int left, int right)
{
    T pivot = data[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    T temp = data[i + 1];
    data[i + 1] = data[right];
    data[right] = temp;
    return i + 1;
}

template <typename T>
void quickSort(T data[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(data, left, right);
        quickSort(data, left, pivot - 1);
        quickSort(data, pivot + 1, right);
    }
}
#endif