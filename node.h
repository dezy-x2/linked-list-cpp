#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
    private:
        int data;
        Node* nextNode;
    public:
        Node();
        Node(int data, Node* nextNode);
        int getData();
        void setData(int newData);
        Node& getNextNode();
        void setNextNode(Node* newNextNode);
};

#endif