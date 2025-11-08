#include <iostream>
#include <vector>
#include <algorithm>

struct Info {
    std::vector<int> arr;
    int x;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n {};
    std::cin >> n;

    std::vector<Info> data (n);
    for (auto& elem : data) {
        size_t count {};
        std::cin >> count;
        elem.arr.resize(count);

        for (auto& value : elem.arr) {
            std::cin >> value;
        }

        std::cin >> elem.x;
    }

    for (auto elem : data) {
        bool isFound {false};

        auto [min, max] = std::minmax_element(elem.arr.begin(), elem.arr.end());
        
        isFound = (*min <= elem.x) && (*max >= elem.x);
        std::cout << ((isFound) ? "YES" : "NO") << '\n';
    }

    return 0;
}