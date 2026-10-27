#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main()
{

    // C P Q
    DoubleList<char> *head = createNode('C');
    DoubleList<char> *second = createNode('P');
    DoubleList<char> *third = createNode('E');

    // connecting the node
    // connect the node to the next node
    head->next = second;
    second->prev = head;

    // node to node
    second->next = third;
    third->prev = second;

    // traversal
    std::cout << "Testing the dllTraverse List" << std::endl;
    dllTraverse(head);
    // insert at the head
    std::cout << "Testing the dllInsertHead" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);
    // insert at the end
    std::cout << "Testing the dllInsertEnd" << std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);
    // general insert
    std::cout << "Testing the dllGenIns" << std::endl;
    dllGenIns('E', head->next->next);
    dllTraverse(head);
    // delete a node
    std::cout << "Testing the dllDelNode" << std::endl;
    dllDelNode('C', &head);
    dllTraverse(head);
    std::cout << "Deleting all nodes\n";
    dllDelList(&head);
    dllTraverse(head);
    return 0;
}