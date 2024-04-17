#include <iostream>
#include <vector>
#include <utility>

template<typename T> class unique_ptr {
    T* ptr;

public:
    unique_ptr(T *p) : ptr{p} {}

    ~unique_ptr() { delete ptr; }

    unique_ptr(const unique_ptr<T> &other) = delete;

    unique_ptr<T> &operator=(const unique_ptr<T> &other) = delete;

    unique_ptr(unique_ptr<T> &&other) : ptr{other.ptr} { other.ptr = nullptr; }

    unique_ptr<T> &operator=(unique_ptr<T> &&other) {
        using std::swap;
        swap(ptr, other.ptr);
        return *this;
    }

    T &operator*() { return *ptr; }
    T &operator->() { return ptr; }
};

class C {
    int x;
public:
    C (int x) : x{x} { std::cout << "Ctor running with x = " << x << std::endl; }
    ~C() { std::cout << "Dtor running." << std::endl; }

    void print() { std::cout << "Value of x: " << x << std::endl; }
};

int main() {
    unique_ptr<C> p{new C{10}};
    (*p).print();

    // Move Assignment: Transfer Ownership to q 
    unique_ptr<C> q = std::move(p);

    (*q).print();

    // Move Assignment: Transfer Ownership back to p
    p = std::move(q);
    (*p).print();

}