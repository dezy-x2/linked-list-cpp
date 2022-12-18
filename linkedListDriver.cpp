#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

int main() {
    LinkedList myList = LinkedList();
    myList.add(10);
    myList.add(12);
    cout << myList.get(0)->getData() << endl;
    cout << myList.get(1)->getData() << endl;
}