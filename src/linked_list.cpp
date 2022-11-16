#include <linked_list.hpp>
#include <iostream>

Node::Node(int X, int Y, int Key)
{
    x = X;
    y = Y;
    key = Key;
    next = nullptr;
};

List::List(Node* Head)
{
    head = Head;
    tail = Head;
};

List::List(Node* node_arr[], int length)
{
    head = nullptr, tail = nullptr;
    for(int i = 0; i < length; i++)
    {
        push(node_arr[i]);
    }
};

List::List(std::initializer_list<Node*> node_arr)
{
    head = nullptr, tail = nullptr;
    for(Node* node : node_arr)
    {
        push(node);
    }
};

int List::endPop()
{
    Node *temp1 = head, *temp2;

    if(head == nullptr)
    {
        std::cout << "endPop() called, list empty" << std::endl;
        return 0;
    }

    temp2 = head->next;

    if(temp2 == nullptr)
    {
        head = nullptr;
        delete temp1;
        return 1;
    }

    while(temp2->next != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    temp1->next = nullptr;
    tail = temp1;
    delete temp2;

    return 1;
}

int List::endPop(Node* node)
{
    Node *temp1 = head, *temp2;

    if(head == nullptr)
    {
        std::cout << "endPop() called, list empty" << std::endl;
        return 0;
    }

    temp2 = head->next;

    if(temp2 == nullptr)
    {
        *node = *head;
        head = nullptr;
        delete temp1;
        return 1;
    }

    while(temp2->next != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    temp1->next = nullptr;
    tail = temp1;
    *node = *temp2;
    delete temp2;

    return 1;
}

void List::push(Node *node)
{
    if(head == nullptr)
    {
        head = node;
        tail = node;
        return;
    }

    node->next = head;
    head = node;

    Node *current = head;
    while(current->next != nullptr)
    {
        current = current->next;
        current->key++;
    }
}

int List::length()
{
    Node *temp = head;
    int size = 0;

    if(head == nullptr)
    {
        std::cout << "length() called, list empty, returning 0" << std::endl;
    }
    else
    {
        while(temp != NULL)
        {
            temp = temp->next;
            size++;
        }
    }
    return size;
}

void List::printList()
{
    Node *current = head;

    if(current == nullptr)
    {
        std::cout << "List empty" << std::endl;
        return;
    }
    std::cout << "\n";
    while (current != nullptr)
    {
        std::cout << "Key: " << current->key << " | " <<
                     "X: " << current->x << " | " <<
                     "Y: " << current->y << " | " <<
                     "Next: " << ((current->next == nullptr) ? -1 : current->next->key) <<
                     "\n----------------" << std::endl;
        current = current->next;
    }
    std::cout << "Head: " << head->key << " | "
              << "Tail: " << tail->key << std::endl;
}