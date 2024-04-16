#include <iostream>

class LinkedList {

    struct Node {
        int data;
        Node* next;

        public:
            Node(int data, Node* next) : data{data}, next{next} {}
    };

    Node* llist = nullptr;

public:
    class Iterator {
        Node* currentNode;
    public:
        explicit Iterator(Node *currentNode = nullptr);
        bool operator!=(const Iterator &other);
        int& operator*() const;
        Iterator& operator++();
    };

    ~LinkedList();
    void addNode(int data);
    Iterator begin() const;
    Iterator end() const;
};

LinkedList::Iterator::Iterator(Node *current) : currentNode{current} {}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
    return this->currentNode != other.currentNode;
}

int& LinkedList::Iterator::operator*() const {
    return this->currentNode->data;
}

LinkedList::Iterator& LinkedList::Iterator::operator++() {
    if (currentNode != nullptr) {
        currentNode = currentNode->next;
    }
    return *this;
}

LinkedList::~LinkedList() {
    while (llist != nullptr) {
        Node *temp = llist;
        llist = llist->next;
        delete temp;
    }
}

void LinkedList::addNode(int data) {
    llist = new Node{data, this->llist};
}

LinkedList::Iterator LinkedList::begin() const {
    return Iterator(this->llist);
}

LinkedList::Iterator LinkedList::end() const {
    return Iterator(nullptr);
}

int main() {

    LinkedList myllist;
    myllist.addNode(1);
    myllist.addNode(2);
    myllist.addNode(3);
    myllist.addNode(4);

    std::cout << "Iterating through myllist: " << std::endl;
    for (LinkedList::Iterator it = myllist.begin(); it != myllist.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}