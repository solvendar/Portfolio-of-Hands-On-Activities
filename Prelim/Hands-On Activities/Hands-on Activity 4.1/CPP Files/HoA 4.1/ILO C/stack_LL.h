#ifndef STACK_LL_H
#define STACK_LL_H
#include <iostream>

template <typename T>
class sNode
{

public:
    T data;
    sNode *next;
};

// global top/head pointer for tracking the stack
sNode<char> *head = nullptr;

// Observers
bool list_Empty();
void list_Top();

// Transformers
void list_push(char newData);
void list_pop();

// allocate a new node
template <typename T>
sNode<T> *new_node(T newData)
{

    sNode<T> *newNode = new sNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// function implementation
bool list_Empty()
{
    return (head == nullptr);
}

void list_Top()
{
    if (list_Empty())
    {
        std::cout << "Stack is Empty" << std::endl;
        return;
    }
    std::cout << "The top element is: " << head->data << std::endl;
}

void list_push(char newData)
{
    sNode<char> *newNode = new_node(newData);

    // set the new node next to point to the current head
    newNode->next = head;

    // update the head pointer to become this new node
    head = newNode;
}

void list_pop()
{
    if (list_Empty())
    {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }

    // keep track of the node that want to delete
    sNode<char> *temp = head;

    // advance the head pointer to the next lower node
    head = head->next;

    // delete the memory of the popped node
    delete temp;
}

#endif
