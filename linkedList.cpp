#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

LinkedList::LinkedList() {
    this->headNode = nullptr;
    cout << "::MEM.ACCESS.CREATE_BLANK.LINKEDLIST" << endl;
}
LinkedList::LinkedList(Node* headNode) {
    cout << "::MEM.ACCESS.CREATE.LINKEDLIST" << endl;
    size = 1;
    this->headNode = headNode;

}
int LinkedList::getSize() {
    return this->size;
}
void LinkedList::add(Node* newNode) {
    if (!headNode) {
        headNode = newNode;
        size++;
        return;
    }
    Node* currNode = headNode->getNextNode();
    while(currNode) {
        if(currNode->getNextNode()) currNode = currNode->getNextNode();
        else break;
    }
    size++;
    currNode->setNextNode(newNode);
}
void LinkedList::add(int data) {
    Node* newNode = new Node(data);
    if (headNode == nullptr) {
        headNode = newNode;
        size++;
        return;
    }
    Node* currNode = headNode;
    while(currNode->getNextNode() != nullptr) {
        cout << "hello to yall" << endl;
        if (currNode->getNextNode()) currNode = currNode->getNextNode();
        else break;
    }
    size++;
    currNode->setNextNode(newNode);
}
Node* LinkedList::get(int at) {
    Node* currNode = headNode;
    for (int i=0; i<at && currNode->getNextNode() != nullptr; i++) {
        currNode = currNode->getNextNode();
    }
    return currNode;
}
Node* LinkedList::pop() {
    Node* prevNode = headNode;
    Node* currNode = headNode->getNextNode();
    while (currNode->getNextNode() != nullptr) {
        prevNode = currNode;
        currNode = currNode->getNextNode();
    }
    return currNode;
}
void LinkedList::printList() {
    cout << "[" << endl;
    Node* currNode = headNode;
    while (currNode != nullptr) {
        cout << "\t";
        currNode->printNode();
        currNode = currNode->getNextNode();
    }
    cout << "]" << endl;
}