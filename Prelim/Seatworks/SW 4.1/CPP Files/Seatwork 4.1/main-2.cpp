#include <iostream>
#include <stack>

// Emplace Struct Function
struct Inventory
{
    std::string attributes;
    std::string name;
    Inventory(std::string n, std::string a) : name(n), attributes(a) {} // Constructor for the data inside the struct
};

int main()
{
    // push
    // pop
    // isEmpty
    // isFull
    // Top

    std::stack<char> stack1;

    std::cout << "is the stack empty? " << stack1.empty() << std::endl;
    stack1.push('j');
    std::cout << "current top of stack " << stack1.top() << std::endl;
    stack1.push('i');
    std::cout << "current top of stack " << stack1.top() << std::endl;
    stack1.push('m');
    std::cout << "current top of stack " << stack1.top() << std::endl;
    std::cout << "is the stack empty?" << stack1.empty() << std::endl;
    std::cout << "what is the size of the stack " << stack1.size() << std::endl;

    // declaration stack for two variable
    std::stack<int> xen1;
    std::stack<int> xen2;

    // initialization of what number value inside between stack 1 and 2
    xen1.push(90);
    xen2.push(60);
    // checking
    std::cout << "your current number stack on xen1 is " << xen1.top() << std::endl;
    std::cout << "your current number stack on xen2 is " << xen2.top() << std::endl;

    // swap function
    xen1.swap(xen2);
    // check if the swap was complete
    std::cout << "your current number on stack xen1 now is " << xen1.top() << std::endl;
    std::cout << "your current number on stack xen2 now is " << xen2.top() << std::endl;

    // emplace
    std::stack<Inventory> item;
    // DEFINING
    item.push(Inventory("Sword", "Scorch"));
    // CALLING THE EMPLACE
    item.emplace(Inventory("Sword", "Scorch"));

    std::cout << "The Item available inside your Inventory is: " << item.top().name << " (" << item.top().attributes << ")" << std::endl;

    return 0;
}
