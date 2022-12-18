#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

LinkedList::LinkedList() {
    size = 0;
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
        if (currNode->getNextNode()) currNode = currNode->getNextNode();
        else break;
    }
    size++;
    currNode->setNextNode(newNode);
}
Node* LinkedList::get(int at) {
    if (at >= size) return nullptr;
    Node* currNode = headNode;
    for (int i=0; i<at && currNode->getNextNode() != nullptr; i++) {
        currNode = currNode->getNextNode();
    }
    return currNode;
}
Node* LinkedList::pop() {
    Node* prevNode = headNode;
    Node* currNode = headNode->getNextNode();
    int i = 0;
    while (currNode->getNextNode() != nullptr) {
        prevNode = currNode;
        currNode = currNode->getNextNode();
        i++;
    }
    deleteNode(i+1);
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
void LinkedList::deleteNode(int at) {
    if (at == 0) {
        Node* toBeDeleted = this->get(0);
        Node* after = this->get(1);
        headNode = nullptr;
        headNode = after;
        delete toBeDeleted;
        return;
    }
    Node* toBeDeleted = this->get(at);
    Node* before = this->get(at-1);
    Node* after = this->get(at+1);
    before->setNextNode(after);
    delete toBeDeleted;
}