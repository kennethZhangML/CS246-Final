#include <iostream>

class Base {
public:
    virtual void function1() {
        std::cout << "Base::function1()" << std::endl;
    }
    virtual void function2() {
        std::cout << "Base::function2()" << std::endl;
    }
    virtual ~Base() {} 
};

class D1 : public Base {
public:
    void function1() override {
        std::cout << "D1::function1()" << std::endl;
    }
};

class D2 : public Base {
public:
    void function2() override {
        std::cout << "D2::function2()" << std::endl;
    }
};

int main() {
    Base* basePtr;
    D1 d1;
    D2 d2;

    basePtr = &d1;
    basePtr->function1(); 
    basePtr->function2(); 

    basePtr = &d2;
    basePtr->function1();
    basePtr->function2(); 

    return 0;
}
