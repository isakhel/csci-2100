#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename Object>
class SLinkedList {
private:
    struct Node {
        Object elem;
        Node* next;

        Node(const Object& e, Node* n = nullptr)
            : elem(e), next(n) {}
    };

    Node* head;

public:
    // Constructors / Destructor
    SLinkedList() : head(nullptr) {}
    ~SLinkedList();

    // Core operations
    bool empty() const { return head == nullptr; }
    const Object& front() const;
    void addFront(const Object& e);
    void removeFront();

    int size() const;     // return number of nodes
    void print() const;   // print list elements
};

#include "SLinkedList.tcc"

#endif
