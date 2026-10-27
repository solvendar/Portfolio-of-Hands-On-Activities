#include <iostream>
#include "stackList.h"

int main()
{

    std::cout << "--- PUSHING 'C' 'P' 'E' ONTO THE STACK ---\n";

    // push
    push<char>('C');
    push<char>('P');
    push<char>('E');

    // Display the current top
    Top<char>(); // Top should be 'E'

    std::cout << "\n ---- Display all the elements ----- \n";
    displayALL<char>();
    std::cout << "\n ---- Popping all the elements ----- \n";

    while (!isEmpty<char>())
    {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n ---- Testing the Underflow ----- \n";
    pop<char>();

    return 0;
}
