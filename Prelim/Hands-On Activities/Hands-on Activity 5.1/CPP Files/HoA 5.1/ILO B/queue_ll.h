#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

// create a class node
template <typename T>
class qNode
{
public:
    T data;
    qNode *next;
};

// creating the new node
template <typename T>
qNode<T> *new_node(T newData)
{

    // allocate a space for the new node
    qNode<T> *newNode = new qNode<T>;
    // store the newData to the newNode
    newNode->data = newData;
    // point the newNode next to null
    newNode->next = nullptr;
    return newNode;
}

// enqueue
template <typename T>
void enqueue(T newData, qNode<T> **frontPtr, qNode<T> **backPtr)
{

    // create a new node
    qNode<T> *newNode = new_node(newData);

    // inserting into an empty queue
    //  how do we know if the queue is empty?
    //  check if the queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr)
    {

        // assign the frontPtr to the newNode
        (*frontPtr) = newNode;

        // assign the backPtr to the newNode
        (*backPtr) = newNode;
        return;
    }
    // if not then insert at the back
    // point the back next to the newNode
    (*backPtr)->next = newNode; // LINKS THE CURRENT BACK TO THE NEW NODE
    // the newNode will be the new backPtr
    (*backPtr) = newNode; // ASSIGNS THE BACKPTR TO THE NEW NODE
}

// dequeue
template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr)
{

    // check if the queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr)
    {
        std::cout << "The queue is empty. Nothing to dequeue" << std::endl;
        return;
    }
    // create a temporary variable to store the node to be deleted
    // creating a temporaty pointer
    qNode<T> *tempPtr = nullptr;

    // store the front pointer to the temporary pointer
    // check if the queue has only 1 item
    tempPtr = (*frontPtr);

    // check if the queue is 1 node left
    if ((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr)
    {

        // return only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete tempPtr;
        return;
    }

    // update the frontPtr
    (*frontPtr) = (*frontPtr)->next;

    // point the tempPtr->next to null
    tempPtr->next = nullptr;

    // delete the node
    delete tempPtr;
}

// display all
template <typename T>
void display(qNode<T> *frontPtr)
{

    // catch if the queue is empty
    if (frontPtr == nullptr)
    {
        std::cout << "The queue is empty.\n";
        return;
    }

    //  temp pointer to store the front Ptr
    qNode<T> *temp = frontPtr;

    // create a loop that will print the tempPtr->data
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << "\n";
}

// isEmpty
template <typename T>
bool isEmpty(qNode<T> **frontPtr, qNode<T> **backPtr)
{
    if (*frontPtr == nullptr && *backPtr == nullptr)
    {
        std::cout << "The queue is empty" << std::endl;
        return true;
    }
    return false;
}
#endif