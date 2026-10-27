#include <iostream>
#include <queue>

// function declarations
void display(std::queue<char> copyQ);

int main()
{

    // create queue object
    std::queue<char> myQ;

    myQ.push('K');
    myQ.push('R');
    myQ.push('B');

    display(myQ);
    std::cout << "current front is: " << myQ.front() << std::endl;
    std::cout << "current back is: " << myQ.back() << std::endl;
    display(myQ);

    // use the dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();

    // check the queue if it is empty
    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;
    return 0;
}

// note only use the member functions of the queue STL
void display(std::queue<char> copyQ)
{

    // loop until empty using the copy directly
    while (!copyQ.empty())
    {

        // display the front
        std::cout << copyQ.front();

        // dequeue the front
        copyQ.pop();
    }

    // add a new line
    std::cout << std::endl;
}