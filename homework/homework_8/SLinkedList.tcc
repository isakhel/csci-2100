template <typename Object>
SLinkedList<Object>::~SLinkedList() {
    while (!empty()) removeFront();
}

template <typename Object>
const Object& SLinkedList<Object>::front() const {
    if (empty()) throw std::runtime_error("List is empty!");
    return head->elem;
}

template <typename Object>
void SLinkedList<Object>::addFront(const Object& e) {
    Node* newNode = new Node(e, head);
    head = newNode;
}

template <typename Object>
void SLinkedList<Object>::removeFront() {
    if (empty()) throw std::runtime_error("List is empty!");
    Node* old = head;
    head = old->next;
    delete old;
}


template <typename Object>
int SLinkedList<Object>::size() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

template <typename Object>
void SLinkedList<Object>::print() const {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    while (current != nullptr) {
        std::cout << current->elem << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
