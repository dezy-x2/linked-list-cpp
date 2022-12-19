#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

int main() {
    LinkedList myList = LinkedList();
    myList.add(10);
    myList.add(12);
    myList.add(14);
    myList.add(16);
    myList.printList();
    myList.deleteNode(0);
    myList.printList();
    myList.add(18);
    myList.printList();
}