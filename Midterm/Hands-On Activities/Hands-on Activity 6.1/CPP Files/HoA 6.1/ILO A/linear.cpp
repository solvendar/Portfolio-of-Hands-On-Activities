#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h>  //will be used for our searching function
#include "searchingAlgo.h"

const int max_Size = 50;

int main()
{

    // generate random values:
    int dataset[max_Size];
    srand(time(0));
    for (int i = 0; i < max_Size; i++)
    {
        dataset[i] = rand();
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int choice;
    std::cout << "Indicate the number to search: ";
    std::cin >> choice;

    linearSearchArr(max_Size, choice, dataset);

    // CREATE A NODE FOR YOUR NAME
    // [J]->[i]->[M]->[L]->[O]->[R]->[D]->NULL

    /*Node<char> *name1 = new_node('J');
    Node<char> *name2 = new_node('I');
    Node<char> *name3 = new_node('M');
    Node<char> *name4 = new_node('L');
    Node<char> *name5 = new_node('O');
    Node<char> *name6 = new_node('R');
    Node<char> *name7 = new_node('D');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    linearSearchLL(name1, 'D');
    linearSearchLL(name1, 'X');

    // generate a sorted list for the array:
    int dataset2[max_Size];
    for (int i = 0; i < max_Size; i++)
    {
        dataset2[i] = i;
        std::cout << dataset2[i] << " ";
    }

    binarySearchArr(11, dataset2, max_Size);
    binarySearchArr(11111, dataset2, max_Size);

    Node<char> *name1 = new_node('A');
    Node<char> *name2 = new_node('B');
    Node<char> *name3 = new_node('C');
    Node<char> *name4 = new_node('D');
    Node<char> *name5 = new_node('E');
    Node<char> *name6 = new_node('F');
    Node<char> *name7 = new_node('G');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    binarySearchLL(name1, 'G');
    binarySearchLL(name1, 'X');*/
}