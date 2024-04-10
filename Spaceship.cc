#include <iostream>
#include <compare>

class List {
    struct Node {
        int data;
        Node* next;

        std::strong_ordering operator<=>(const Node& other) {
            auto n = data <=> other.data;
            if (n != 0) return n;
            if (next == nullptr && other.next == nullptr) { return n; }
            if (next == nullptr) return std::strong_ordering::less;
            if (other.next == nullptr) return std::strong_ordering::greater;

            return next <=> other.next;
        }

        ~Node() { delete next; }
    };

    Node* theList = nullptr;

public:
    ~List() { delete theList; }
    void add(int i) {
        theList = new Node{i, theList};
    }

    int ith(int index) const {
        Node* ptr = theList;
        for (int ctr = 0; ctr < index; ++ctr) {
            if (!ptr) throw std::out_of_range("Index out of range!");
            ptr = ptr->next;
        }

        if (!ptr) throw std::out_of_range("Index out of range!");
        return ptr->data;
    }

    void print() {
        Node* ptr = theList;
        while (ptr != nullptr) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    List myList;
    myList.add(1);
    myList.add(3);
    myList.add(2);

    std::cout << "List contents: ";
    myList.print();

    try {
        std::cout << "Element at index 0: " << myList.ith(0) << std::endl;
        std::cout << "Element at index 1: " << myList.ith(1) << std::endl;
        std::cout << "Element at index 2: " << myList.ith(2) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}