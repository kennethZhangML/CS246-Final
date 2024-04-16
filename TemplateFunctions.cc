#include <iostream>
#include <vector>
#include <algorithm>

int min(int a, int b) { return a < b ? a : b; }

template<typename T>
T min(T a, T b) { return (a < b ? a : b); }

// Recall: for_each function 
template <typename Iter, typename Fn>
Iter foreach(Iter first, Iter last, Fn f) {
    while (first != last) {
        f(*first);
        ++first;
    }
    return first;
}

template <typename Iter, typename T>
Iter find(Iter first, Iter last, const T& val) {
    while (first != last) {
        if (*first == val) {
            return first;
        }
        ++first;
    }
    return last;
}

template<typename InIter, typename OutIter>
OutIter copy(InIter first, InIter last, OutIter result) {
    while (first != last) {
        *result = *first;
        ++first;
        ++result;
    }

    return result;
}

template<typename InIter, typename OutIter, typename Fn>
OutIter vectorTransform(InIter first, InIter last, OutIter result, Fn f) {
    while (first != last) {
        *result = f(*first);
        ++first;
        ++result;
    }
    return result;
}

int duple(int i) { return 2 * i; }

class Plus1 {
public:
    int operator()(int i) { return i + 1; }
};

class Plus {
    int n;
public:
    Plus(int n) : n{n} {}
    int operator()(int n) { return n + this->n; }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::vector<int> w{0, 0, 0, 0};
    std::vector<int> z{0, 0, 0, 0};
    std::vector<int> y{0, 0, 0, 0};

    Plus1 p;
    std::cout << p(4) << std::endl; // prints 5 

    std::cout << "Vector Transform: Template Function" << std::endl;
    vectorTransform(v.begin(), v.begin() + 4, w.begin(), duple);
    for (auto val : w) {
        std::cout << val << std::endl;
    }

    std::cout << "Vector Transform: Function Object with Classes" << std::endl;
    vectorTransform(v.begin(), v.begin() + 4, z.begin(), Plus1{});

    for (auto val : z) {
        std::cout << val << std::endl;
    }

    std::cout << "Vector Transform: Function Generic Plus" << std::endl;
    vectorTransform(v.begin(), v.begin() + 4, y.begin(), Plus{4});

    for (auto val : y) {
        std::cout << val << std::endl;
    }

    return 0;
}