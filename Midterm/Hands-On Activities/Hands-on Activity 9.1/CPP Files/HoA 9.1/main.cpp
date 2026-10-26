#include <iostream>
#include "BST.h"

int main(){
    //create the root node:
    BinarySearchTree<int> tree(20);

    tree.insert(10);
    tree.insert(5);
    tree.insert(70);
    tree.insert(80);
    tree.insert(40);
    tree.insert(50);

    std::cout<<"preOrder:";
    tree.preOrder();
    std::cout<<std::endl;

    std::cout<<"inOrder:";
    tree.inOrder();
    std::cout<<std::endl;

    std::cout<<"postOrder:";
    tree.postOrder();
    std::cout<<std::endl;

    return 0;
}