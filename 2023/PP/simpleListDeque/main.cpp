#include <iostream>
#include "Deque.h"

int main() {
    Deque<> list;

    list.pushFront(4);
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(5);
    list.pushFront(3);
    list.pushBack(6);
    list.pushBack(10);
    list.popFront();
    list.popBack();

    std::cout << "List: ";

    for (int i = 0; i < list.getSize(); ++i) {
        std::cout << list.getInfo(i) << " ";
    }

    std::cout << std::endl << std::endl;
    std::cout << "First element: " << list.getFront() << std::endl;
    std::cout << "Last element: " << list.getBack() << std::endl;

    return 0;
}