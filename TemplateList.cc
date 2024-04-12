#include <iostream>
#include <string>

template<typename T> class Stack {
    T arr[10];
    int size = 10;

public:
    void push(T data) {
        arr[size++] = data;
    }

    T pop() {
        return arr[--size];
    }

    bool empty() {
        return size == 0;
    }
};


template<class T> class List {
    struct Node {
        int data;
        Node *next;
    };

    Node* theList = nullptr;

public:
    ~List() {
        Node* current = theList;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int data) {
        theList = new Node{data, theList};
    }

    T ith(int index) {
        int ctr = 0;
        Node* ptr = theList;
        while (ctr <= index && ptr != nullptr) {
            if (ctr == index) return ptr->data;
            ++ctr;
            ptr = ptr->next;
        }
        throw std::out_of_range("Index out of bounds");
    }

    class Iterator {
        Node* current;

    public:
        Iterator(Node* node) : current{node} {}

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        T& operator*() const {
            return current->data;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(theList);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

int main() {
    List<int> myList1;
    myList1.add(5);
    myList1.add(10);
    myList1.add(15);

    std::cout << "Outputting items..." << std::endl;
    for (auto elem : myList1) {
        std::cout << elem << std::endl;
    }

    return 0;
}