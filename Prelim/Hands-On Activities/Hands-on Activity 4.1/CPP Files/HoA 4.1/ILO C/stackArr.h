#ifndef STACKARR_H
#define STACKARR_H
#include <iostream>

const int maxSize = 10;
char stackArr[maxSize];
int top = -1;

// obsevers
bool isFull();
bool isEmpty();
void Top();

// transformer
void pop();
void push(char newData); // to accept character parameter

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top == maxSize - 1);
}

void Top()
{
    if (isEmpty())
    {
        std::cout << "Stack is Empty" << std::endl;
        return;
    }
    // else
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

void push(char newData)
{

    // error catching
    if (isFull())
    {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }
    // storing to the stack
    stackArr[++top] = newData;
}

void pop()
{
    // error catching
    if (isEmpty())
    {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }
    // else
    // to remove the element from the stack
    top--;
}
#endif