#include <iostream>
#include "linkedList.h"
#include "node.h"
using namespace std;

/**
 * @brief Construct a new Linked List:: Linked List object (default)
 * 
 */
LinkedList::LinkedList() {
    size = 0;
    this->headNode = nullptr;
    cout << "::MEM.ACCESS.CREATE_BLANK.LINKEDLIST" << endl;
}
/**
 * @brief Construct a new Linked List:: Linked List object
 * 
 * @param headNode[Node*] Head node of the linked list
 */
LinkedList::LinkedList(Node* headNode) {
    cout << "::MEM.ACCESS.CREATE.LINKEDLIST" << endl;
    size = 1;
    this->headNode = headNode;
}
/**
 * @brief returns the current size of the linked list
 * 
 * @return [int] - size of the linked list
 */
int LinkedList::getSize() {
    return this->size;
}
/**
 * @brief adds a new node to the linked list either as the head node or just next in the chain
 * 
 * @param newNode[Node*] node to be added to the list
 */
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
/**
 * @brief adds a new node to the linked list either as the head node or just next in the chain
 * 
 * @param data[int] data to be created into a new node to add to the list
 */
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
/**
 * @brief returns a node at the specified index
 * 
 * @param at[int] index at which to retrieve the node
 * @return [Node*] - node at the specified index 
 */
Node* LinkedList::get(int at) {
    if (at >= size) return nullptr;
    Node* currNode = headNode;
    for (int i=0; i<at && currNode->getNextNode() != nullptr; i++) {
        currNode = currNode->getNextNode();
    }
    return currNode;
}
/**
 * @brief deletes the last node of the linked list and returns it
 * 
 * @return [Node*] - the removed node
 */
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
/**
 * @brief prints out the linked list with its data
 * 
 */
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
/**
 * @brief deletes but does not return a node at a specified index
 * 
 * @param at[int] index at which to delete the node
 */
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