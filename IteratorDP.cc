#include <iostream>

class List {

    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) : data{data}, next{next} {}
    };

    Node* theList = nullptr;

public:
    class Iterator {
        Node* p;

    public:
        explicit Iterator(Node *p = nullptr) : p{p} {}
        bool operator!=(const Iterator& other) const {
            return p != other.p;
        }

        int& operator*() const {
            return p->data;
        }

        Iterator& operator++() {
            p = p->next;
            return *this;
        }
    };

    ~List() {
        while (theList != nullptr) {
            Node* temp = theList;
            theList = theList->next;
            delete temp;
        }
    };

    void add(int data) {
        theList = new Node{data, theList};
    }

    Iterator begin() const {
        return Iterator(theList);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    List myList;
    myList.add(3);
    myList.add(2);
    myList.add(1);

    std::cout << "Iterating through list:\n";
    for (List::Iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}