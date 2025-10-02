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
        // Appends items to the list by setting the tail to point to the added node
        // and the new tail's "next" to nullptr
        // If list is empty it also sets the head to point to the new node
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
        // Prepends items to the list by first setting the new node's "next" to the head
        // and only then changing the head pointer to the new node (this order is very important)
        // likewise if the list is empty then it just sets both head and tail to the new node
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
        // prints the data stored in each node as it traverses the list until it reaches the end
        // (the nullptr)
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    node* GetNode(int value) {
        // traverses the list until it finds the node with the given value. Returns nullptr if not 
        // found
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
        // Inserts a node after another node. If the list is empty, then it inserts it at the 
        // beginning If the input is nullptr, it prepends the node to the list,
        // otherwise it adds the new node in front of the old one. If that node is last then it 
        // appends it to the list
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
        // Similar functionality as above, doesn't do anything if the list is empty,
        // deletes the head if nullptr is given as an argument 
        //(making sure to delete the temp) to avoid memory leaks
        // deletes the node after the node given in the argument by appropriately reassinging it's
        // next pointers
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
