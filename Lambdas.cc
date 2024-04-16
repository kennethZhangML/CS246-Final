#include <iostream>
#include <vector> 
#include <algorithm>
#include <ranges>
#include <iterator>

auto even = [](int n) { return (n % 2 == 0); };
auto sqr = [](int n) {return n * n; }; 

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Original vector" << std::endl;
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::vector<int> w;
    std::vector<int> x;
    std::copy_if(v.begin(), v.end(), std::back_inserter(w), even);
    std::transform(w.begin(), w.end(), std::back_inserter(x), sqr);

    std::cout << "Squared even numbers" << std::endl;
    std::copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    auto y = v | std::views::filter(even) | std::views::transform(sqr);
    std::cout << "Squared even numbers using range adaptors" << std::endl;
    for (int num : y) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    return 0;
}