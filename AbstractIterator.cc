#include <iostream>
#include <stdexcept>

class AbstractIterator {
public:
    virtual ~AbstractIterator() {}
    virtual int& operator*() const = 0;
    virtual AbstractIterator& operator++() = 0;
    virtual bool operator!=(const AbstractIterator& other) const = 0;
};

class List {
    int* elements;
    int size;

public:
    List(int* arr, int n) : elements(arr), size(n) {}

    class Iterator : public AbstractIterator {
        int* current;

    public:
        Iterator(int* ptr) : current(ptr) {}

        int& operator*() const override {
            return *current;
        }

        Iterator& operator++() override {
            ++current;
            return *this;
        }

        bool operator!=(const AbstractIterator& other) const override {
            const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
            if (!otherIterator) {
                throw std::runtime_error("Iterator types mismatch");
            }
            return current != otherIterator->current;
        }
    };

    Iterator begin() {
        return Iterator(elements);
    }

    Iterator end() {
        return Iterator(elements + size);
    }
};

void foreach(AbstractIterator& start, AbstractIterator& end, void (*f)(int&)) {
    while (start != end) {
        f(*start);
        ++start;
    }
}

void inc(int& i) { ++i; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    List myList(arr, sizeof(arr)/sizeof(arr[0]));

    auto start = myList.begin();
    auto end = myList.end();
    foreach(start, end, inc);

    for (auto elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
