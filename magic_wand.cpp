#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t tests {};
    std::cin >> tests;

    std::vector<std::vector<int>> data (tests);
    // Read all the inputs
    for (auto& arr : data) {
        size_t len {};
        std::cin >> len;

        arr.resize(len);
        for (auto& elem : arr) {
            std::cin >> elem;
        }
    }

    std::cout << "---\n";

    // Process all the inputs
    for (auto& arr : data) {
        std::sort(arr.begin(), arr.end(), [](int a, int b) {
            auto isA_even = (a % 2 == 0);
            auto isB_even = (b % 2 == 0);
            return (isA_even != isB_even) && a <= b;
        });

        // Print the output per test instance.
        std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }

    return 0;
}