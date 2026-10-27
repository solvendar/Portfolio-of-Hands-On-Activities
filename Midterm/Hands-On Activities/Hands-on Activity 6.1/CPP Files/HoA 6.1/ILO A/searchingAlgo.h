#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H
#include "node.h"
#include <iostream>

template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[])
{
    int i = 0;
    while (i <= maxSize)
    {
        if (dataFind == data[i])
        {
            std::cout << "Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout << "the search is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node<T> *node, T dataFind)
{

    // CREATE A LOOP THAT ITERATES UNTIL THE NODE REACHES THE END (NULLPTR)
    while (node != nullptr)
    {
        // CREATE AN IF CONDITION THAT WILL COMPARE THE SEARCH ITEM TO THE CURRENT NODE DATA
        if (node->data == dataFind)
        {
            std::cout << "the search was success.\n";
            return;
        }
        // ITERATOR OR / MOVING OF NDOE
        node = node->next;
    }
    // DISPLAY IF UNSUCCESSFUL
    std::cout << "the search was unsuccessful.\n";
}

template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize)
{
    int low = 0, up = maxSize - 1, middle;
    while (low <= up)
    {
        middle = (int)((low + up) / 2);
        if (dataFind == data[middle])
        {
            std::cout << "searching is success.\n";
            return;
        }
        else if (dataFind > data[middle])
        {
            low = middle + 1;
        }
        else
        {
            up = middle - 1;
        }
    }
    std::cout << "search element was not found.";
}

// create a helper function to get the middle code
template <typename T>
Node<T> *getMiddle(Node<T> *start, Node<T> *last)
{
    // use two pointers
    // slow moves one node at a time
    // fast moves two at a time

    Node<T> *slow = start;
    Node<T> *fast = start;

    // create a loop until fast reaches the end
    // or reaches the last node of the current search range

    while (fast != last && fast->next != last)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
template <typename T>

void binarySearchLL(Node<T> *node, T dataFind)
{

    Node<T> *last = nullptr;

    while (start != last)
    {
        // middle element
        Node<T> middle = getMiddle(start, last);

        if (middle->data == dataFind)
        {
            std::cout << "the data was found.\n";
            return;
        }
        else if (middle->data > dataFind)
        {
            last = middle;
        }
        else
        {
            start = middle->next;
        }
    }
    std::cout << "search element was not found.\n";
}
#endif