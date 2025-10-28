#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    size_t n {};
    std::cin >> n;

    std::vector<std::vector<int>> data (n, std::vector<int>(4, 0));
    
    // Read input
    for (auto& arr : data){
        for (auto& elem : arr)
            std::cin >> elem;
    }

    // process the data
    for (auto& arr : data){
        auto [min, max] = std::minmax_element(arr.cbegin(), arr.cend());
        std::cout << ((*min == *max) ? "YES" : "NO") << '\n';
    }

    return 0;
}