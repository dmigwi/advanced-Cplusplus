#include <iostream>
#include <array>
#include <numeric>
#include <iostream>

int main () {
    // std::variant
    std::variant<int, double> v {12};
    std::cout << "1: " << std::get<int>(v) << " " << std::get<0>(v) << '\n';
    // std::cout << "2: " << std::get<double>(v) << " " << std::get<1>(v) << '\n'; // Error: std::bad_variant_access: bad_variant_access
    v = 12.0;
    //std::cout << "3: " << std::get<int>(v) << " " << std::get<0>(v) << '\n'; // Error: std::bad_variant_access: bad_variant_access
    std::cout << "41: " << std::get<double>(v) << " " << std::get<1>(v) << '\n';

    // Prefix sum algorithms
    const std::array<int, 3> a{ 1, 2, 3 };
    std::cout << "\nInclusive sum: ";
    std::inclusive_scan(std::cbegin(a), std::cend(a), std::ostream_iterator<int>{ std::cout, " " }, std::plus<>{}); // 1 3 6
    std::cout << "\nExclusive sum: ";
    std::exclusive_scan(std::cbegin(a), std::cend(a), std::ostream_iterator<int>{ std::cout, " " }, 0, std::plus<>{}); // 0 1 3

    const auto times_ten = [](const auto n) { return n * 10; };
    std::cout << "\nTransform Inclusive sum: ";
    std::transform_inclusive_scan(std::cbegin(a), std::cend(a), std::ostream_iterator<int>{ std::cout, " " }, std::plus<>{}, times_ten); // 10 30 60
    std::cout << "\nTransform Exclusive sum: ";
    std::transform_exclusive_scan(std::cbegin(a), std::cend(a), std::ostream_iterator<int>{ std::cout, " " }, 0, std::plus<>{}, times_ten); // 0 10 30

    return 0;
}