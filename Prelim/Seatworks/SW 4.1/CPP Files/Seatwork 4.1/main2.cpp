#include <iostream>
#include <stack>

// DEFINITION CHOICE
// #define maxSize 10 (method 1)
// const int maxSize = 10; (method 2)
// const maxSize_t = 10;

// global variable
#define maxSize 10
int stackArr[maxSize];
int top = -1, newData;

// function prototype
// Top, Push, isEmpty, isFull

// observer
bool isEmpty();
bool isFull();
void Top(); // T always capital
void DisplayAll();

// transformer operators
void push();
void pop();

int main()
{

    while (true)
    {

        int choice;

        std::cout << "================================================\n";
        std::cout << "                Stack Operations: " << std::endl;
        std::cout << "[1] push" << std::endl;
        std::cout << "[2] pop" << std::endl;
        std::cout << "[3] isEmpty" << std::endl;
        std::cout << "[4] isFull" << std::endl;
        std::cout << "[5] Top" << std::endl;
        std::cout << "[6] Display All" << std::endl;
        std::cout << std::endl;
        std::cout << "Input your choice ";
        std::cin >> choice;

        switch (choice)
        {

        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            Top();
            break;
        case 6:
            DisplayAll();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    }
    return 0;
}
// function definition
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

    // prints the top element
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

void push()
{

    // error catching
    if (isFull())
        std::cout << "Stack Overflow!" << std::endl;
    return;

    // ask the user what they want to insert:
    std::cout << "what do you want to push? ";
    std::cin >> newData;

    // storing to the stack
    stackArr[++top] = newData;
}
void pop()
{

    // error catching
    if (isEmpty())
        std::cout << "Stack Underflow!" << std::endl;
    return;

    // check if empty
    std::cout << "Popping " << stackArr[top] << std::endl;

    // to remove the element from the stack
    top--;
}

void DisplayAll()
{

    // error checking
    if (isEmpty())
        std::cout << "The Stack is empty" << std::endl;
    return;

    // displaying the stack and the LIFO principle
    std::cout << "The Elements of Stack from top to bottom " << std::endl;
    for (int i = top; i >= 0; i--)
    {
        std::cout << stackArr[i] << std::endl;
    }
}