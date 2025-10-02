#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) : data(val), next(nullptr) {}
};

class SLinkedList {
private:
    node* head;
    node* tail;

public:
    // Constructor
    SLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~SLinkedList() {
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void ListAppend(int elem) {
        node* newNode = new node(elem);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void ListPrepend(int elem) {
        node* newNode = new node(elem);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void ListDisplay() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    node* GetNode(int value) {
        node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    
    void InsertAfter(node* curNode, int elem) {
        node* newNode = new node(elem);

        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
            return;
        }

        if (curNode == nullptr) { 
        
            newNode->next = head;
            head = newNode;
            return;
        }

        newNode->next = curNode->next;
        curNode->next = newNode;

        if (curNode == tail) { 
            tail = newNode;
        }
    }

    void RemoveAfter(node* curNode) {
        if (head == nullptr) return; 

        if (curNode == nullptr) {
            // remove head
            node* temp = head;
            head = head->next;
            if (head == nullptr) { 
                tail = nullptr;
            }
            delete temp;
            return;
        }

        node* target = curNode->next;
        if (target != nullptr) {
            curNode->next = target->next;
            if (target == tail) {
                tail = curNode;
            }
            delete target;
        }
    }
};

// Minimal driver
int main() {
    SLinkedList lst;
    lst.ListAppend(30);
    lst.ListAppend(40);
    lst.ListPrepend(20);
    lst.ListPrepend(10);
    lst.ListDisplay();  

    node* p = lst.GetNode(30);
    if (p) lst.InsertAfter(p, 35);
    lst.ListDisplay();  

    lst.RemoveAfter(p);     
    lst.RemoveAfter(nullptr); 
    lst.ListDisplay();  
    return 0; 
}
