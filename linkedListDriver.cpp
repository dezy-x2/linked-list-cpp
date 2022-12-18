#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

int main() {
    LinkedList myList = LinkedList();
    myList.add(10);
    myList.add(12);
    myList.printList();
}