#include <iostream>
#include <memory>
#include <fstream>

// Define a simple class C for demonstration
class C {
public:
    C() { std::cout << "C constructor called." << std::endl; }
    ~C() { std::cout << "C destructor called." << std::endl; }
};

// Function to demonstrate unique_ptr ownership transfer
void f(std::unique_ptr<C> p) {
    std::cout << "Inside f() function." << std::endl;
}

// Function to demonstrate shared_ptr
std::shared_ptr<C> g() {
    std::shared_ptr<C> p = std::make_shared<C>();
    std::cout << "Inside g() function." << std::endl;
    return p;
}

int main() {
    // Demonstrate unique_ptr
    {
        std::cout << "--- Demonstrating unique_ptr ---" << std::endl;
        // Creating a unique_ptr with new keyword
        std::unique_ptr<C> p{new C};
        // Creating another unique_ptr by transferring ownership from p
        std::unique_ptr<C> q = std::move(p); // Transferring ownership
        // Trying to copy a unique_ptr (not allowed)
        // std::unique_ptr<C> r = q; // Error: Unique pointers cannot be copied
        
    } // Automatically releases memory when out of scope

    // Demonstrate RAII with ifstream
    {
        std::cout << "--- Demonstrating RAII with ifstream ---" << std::endl;
        {
            std::ifstream inf{"input.txt"}; // Constructor opens the file
            if (inf.is_open()) {
                std::cout << "File opened successfully." << std::endl;
                // Read from the file
            }
        } // Destructor closes the file automatically when out of scope
    }

    // Demonstrate passing unique_ptr to a function
    {
        std::cout << "--- Demonstrating passing unique_ptr to a function ---" << std::endl;
        std::unique_ptr<C> ptr{new C};
        f(std::move(ptr)); // Ownership transferred to the function
        // std::cout << *ptr; // Error: ptr is now a null pointer
    }

    // Demonstrate returning shared_ptr from a function
    {
        std::cout << "--- Demonstrating returning shared_ptr from a function ---" << std::endl;
        auto ptr = g(); // Function returns a shared_ptr
        // Shared ownership allows multiple pointers to the same object
        auto ptr2 = ptr; // Shared ownership
    } // Memory deallocated when all shared_ptrs are out of scope

    return 0;
}
