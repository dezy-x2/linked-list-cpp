#include <iostream>
#include "node.h"
using namespace std;

/**
 * @brief Construct a new Node:: Node object (default)
 * 
 */
Node::Node() {
    this->nextNode = nullptr;
    cout << "::MEM.ACCESS.CREATE_BLANK.NODE" << endl;
}
/**
 * @brief Construct a new Node:: Node object
 * 
 * @param data[int] data for the node to carry
 */
Node::Node(int data) {
    this->nextNode = nullptr;
    this->data = data;
    cout << "::MEM.ACCESS.CREATE.NODE:DATA=" << data << endl;
}
/**
 * @brief Construct a new Node:: Node object
 * 
 * @param data[int] data for the node to carry
 * @param nextNode[Node*] the next node in the chain
 */
Node::Node(int data, Node* nextNode) {
    this->data = data;
    this->nextNode = nextNode;
    cout << "::MEM.ACCESS.CREATE.NODE:DATA=" << data << endl;
}
/**
 * @brief returns the data
 * 
 * @return [int] - data stored in the node
 */
int Node::getData() {
    return data;
}
/**
 * @brief changes the data stored in this node
 * 
 * @param newData[int]
 */
void Node::setData(int newData) {
    data = newData;
}
/**
 * @brief returns the next node in the chain
 * 
 * @return [Node*] - the next node in the chain
 */
Node* Node::getNextNode() {
    return nextNode;
}
/**
 * @brief sets the next node in the chain
 * 
 * @param newNextNode[*Node] node to be added to the chain
 */
void Node::setNextNode(Node* newNextNode) {
    nextNode = newNextNode;
}
/**
 * @brief prints the node's data nicely
 * 
 */
void Node::printNode() {
    cout << "{data: " << data << "}" << endl;
}