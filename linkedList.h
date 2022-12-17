#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
using namespace std;

class LinkedList {
    private:
        int size;
        Node* headNode;
    public:
        LinkedList();
        LinkedList(Node* headNode);
        void add(Node* newNode);
        Node* get(int at);
        Node* pop();
};

#endif