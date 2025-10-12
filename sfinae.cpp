#include <iostream>
#include <type_traits>
#include <vector>

template<typename T, typename = void> 
struct has_size_method 
    : std::false_type {}; // SFINAE primary option

template<typename T>
struct has_size_method <T, std::void_t<decltype(std::declval<T>().size())>>
    : std::true_type{} ; // SFINAE specialization option

template<typename Container>
auto getSize(const Container& s) -> std::enable_if_t<has_size_method<Container>::value, size_t>
{
    return s.size();
}

// Example of implemantation
int main() {
    std::vector<int> v {1, 2, 4, 5};
    std::cout << "Size: " << getSize(v) << '\n';

    // getSize(42); // Compilation Error
    return 0;
}