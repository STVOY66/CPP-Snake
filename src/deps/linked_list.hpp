#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

struct Node
{
    Node(int X = 0, int Y = 0, int Key = 0);
    int x, y;
    int key;
    Node* next;
};

class List
{
public:
    List(Node *Head = nullptr);
    List(Node* node_arr[], int length);
    List(std::initializer_list<Node*> node_arr);

    int endPop();
    int endPop(Node* node);
    void push(Node* node);
    int length();
    void printList();

    Node *head;
    Node *tail;
};

#endif