#include <iostream>
#include <numeric>

template <typename First, typename... Args>
auto sum(First first, Args... args) -> decltype(first) {
    const auto values = {first, args...}; 
    std::cout << typeid(values).name() << '\n'; // type is std::initializer_list

    return std::accumulate(values.begin(), values.end(), First{0});
}

int main () {
    std::cout << "sum(1, 2, 3, 4, 5) = " << sum (1, 2, 3, 4,5 ) << '\n';   // Print 15
    std::cout << "sum(1, 2, 3) = " << sum (1, 2, 3) << '\n';               // Print 6
    std::cout << "sum(1.5, 2.0, 3.7) = " << sum(1.5, 2.0, 3.7) << '\n';   // Print 7.2
}