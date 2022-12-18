#include <iostream>
#include "node.h"
using namespace std;

Node::Node() {
    this->nextNode = nullptr;
    cout << "::MEM.ACCESS.CREATE_BLANK.NODE" << endl;
}
Node::Node(int data) {
    this->nextNode = nullptr;
    this->data = data;
    cout << "::MEM.ACCESS.CREATE.NODE:DATA=" << data << endl;
}
Node::Node(int data, Node* nextNode) {
    this->data = data;
    this->nextNode = nextNode;
    cout << "::MEM.ACCESS.CREATE.NODE:DATA=" << data << endl;
}
int Node::getData() {
    return data;
}
void Node::setData(int newData) {
    data = newData;
}
Node* Node::getNextNode() {
    return nextNode;
}
void Node::setNextNode(Node* newNextNode) {
    nextNode = newNextNode;
}
void Node::printNode() {
    cout << "{data: " << data << "}" << endl;
}