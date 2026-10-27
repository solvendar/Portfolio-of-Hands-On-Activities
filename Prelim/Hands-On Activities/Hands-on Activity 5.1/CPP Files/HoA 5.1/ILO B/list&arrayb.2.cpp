#include <iostream>
#include "queue_ll.h"
#include "queueArr.h"

int main()
{
    /*
        // queue linked list
        qNode<int> *front = nullptr;
        qNode<int> *back = nullptr;

        enqueue(1, &front, &back);
        std::cout << "front: " << front->data << " back: " << back->data << "\n";
        enqueue(2, &front, &back);
        enqueue(3, &front, &back);
        std::cout << "front: " << front->data << " back: " << back->data << "\n";

        display(front);
        dequeue(&front, &back);
        std::cout << "front: " << front->data << " back: " << back->data << "\n";
        dequeue(&front, &back);
        std::cout << "front: " << front->data << " back: " << back->data << "\n";
        dequeue(&front, &back);
        dequeue(&front, &back);
        display(front);
    */
    // queue array
    // object creation
    queueArr<int> q(5);
    q.Enqueue(1);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(2);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(3);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(4);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(6);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Enqueue(7);
    std::cout << "Front: " << q.Front() << " back: " << q.Back() << "\n";
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    return 0;
}