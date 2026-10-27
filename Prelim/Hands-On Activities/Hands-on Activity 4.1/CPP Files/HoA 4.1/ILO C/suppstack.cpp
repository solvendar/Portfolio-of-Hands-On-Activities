#include <iostream>
#include <string>
#include "stackArr.h"
#include "stack_ll.h"

// checker for array implementation
bool checkArr(std::string expr)
{
    top = -1; // reset global array tracker for every new test string

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch); // uses array header push
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty())
                return false;

            char open = stackArr[top]; // read from the global array header
            pop();                     // uses array header pop

            if (ch == ')' && open != '(')
                return false;
            if (ch == '}' && open != '{')
                return false;
            if (ch == ']' && open != '[')
                return false;
        }
    }
    return isEmpty();
}

// checker for linked list implementation
bool checkList(std::string expr)
{
    // clear the remaining nodes in the global head pointer
    while (!list_Empty())
    {
        list_pop();
    }
    head = nullptr;

    for (char ch : expr)
    {

        if (ch == '(' || ch == '{' || ch == '[')
        {
            list_push(ch); // uses linked list header push
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (list_Empty())
                return false;

            char open = head->data; // read from the global head node in the header
            list_pop();             // used the linked list header pop

            if (ch == ')' && open != '(')
                return false;
            if (ch == '}' && open != '{')
                return false;
            if (ch == ']' && open != '[')
                return false;
        }
    }
    return list_Empty();
}

int main()
{

    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"};

    for (std::string expr : expressions)
    {
        std::cout << "Expression for both implementation: " << expr << "\n";

        // array stack implementation
        if (checkArr(expr))
        {
            std::cout << "Array Stack: VALID\n";
        }
        else
        {
            std::cout << "Array Stack: INVALID\n";
        }
        // linked list stack implementation
        if (checkList(expr))
        {
            std::cout << "Linked List Stack: VALID\n";
        }
        else
        {
            std::cout << "Linked List Stack: INVALID\n";
        }
        std::cout << "\n";
    }

    return 0;
}