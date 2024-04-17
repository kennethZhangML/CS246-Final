#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <list>

// forward declaration 
class B; 
class A {
public:
    std::shared_ptr<B> b_ptr;
};

class B {
public:
    std::shared_ptr<A> a_ptr;
};

// forward declaration
class D;

class C {
public:
    std::unique_ptr<D> d_ptr;
};

class D {
public:
    std::unique_ptr<C> c_ptr;
};

// Transfer Ownership 
std::shared_ptr<std::vector<int>> transferOwnership(std::unique_ptr<std::vector<int>> uniqueVector) {
    return std::shared_ptr<std::vector<int>>(std::move(uniqueVector));
}

std::unique_ptr<std::map<std::string, double>> createUniqueMap(std::shared_ptr<std::map<std::string, double>> sharedMap) {
    return std::make_unique<std::map<std::string, double>>(*sharedMap);
}

void funcThrowError() {
    std::unique_ptr<int> ptr(new int(42));
    throw std::runtime_error("Exception occurred during ownership transfer.");
}

void funcThrowError2() {
    std::shared_ptr<int> ptr(new int(42));
    throw std::runtime_error("Exception occurred during ownership transfer.");
}

int main() {
    // Basic Pointer Managements
    std::shared_ptr<int> sharedInt(new int(42));
    std::cout << "Shared INT: " << sharedInt << std::endl;

    std::shared_ptr<std::string> sharedStr(new std::string("My String!"));
    std::cout << "Shared STRING: " << sharedStr << std::endl;

    // creating Dynamically Allocated Array of Floats
    std::unique_ptr<float []> uniqueFloatArr = std::make_unique<float []>(5);
    for (auto i = 0; i < 5; ++i) { uniqueFloatArr[i] = i + 1; }
    for (auto k = 0; k < 5; ++k) { std::cout << uniqueFloatArr[k] << std::endl; }

    // creating Dynamically Allocated Array of Chars
    std::shared_ptr<std::list<char>> sharedChars(new std::list<char>{'a', 'b', 'c'});
    for (char c : *sharedChars) {
        std::cout << c << std::endl;
    }

    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->b_ptr = b;
    b->a_ptr = a;

    std::unique_ptr<C> c(new C);
    std::unique_ptr<D> d(new D);

    try {
        // funcThrowError2();
        funcThrowError();
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}