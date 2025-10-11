// #include <string>
// #include <vector>
// #include <iterator>

// template <typename T>
// struct Storage {
//     Storage(T t) : t_(t) {}

//     template<std::input_iterator It>
//     Storage(It begin, It end) : t_(begin,end) {}

//     T t_;
// };

// // Constructor match -> Template instance
// Storage(const char*) -> Storage<std::string>;

// // Deduction guides can be templated
// template<std::input_iterator It>
// Storage(It,It) -> Storage<std::vector<
//     typename std::iterator_traits<It>::value_type>>;

// int main() {
//     Storage a{10};
//     // decltype(a) == Storage<int>
//     // no guide required, deduced from Storage(T t)

//     static_assert(std::is_same_v<decltype(a), Storage<int>>);

//     Storage b{"Hello World!"};
//     // decltype(b) == Storage<std::string>
//     // follows the const char* guide

//     static_assert(std::is_same_v<decltype(b), Storage<std::string>>);

//     std::vector<int> data{1, 2, 3, 4, 5, 6};
//     Storage c{data.begin(), data.end()};
//     // Storage<std::vector<int>> - follows the double iterator guide

//     static_assert(std::is_same_v<decltype(c), Storage<std::vector<int>>>);
// }