#include <iostream>
#include <vector>
#include <algorithm>

struct Info {
    std::vector<int> arr;
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

        std::sort(elem.arr.begin(), elem.arr.end());
    }

    // process the values
    for (auto elem : data) {
        int x = -1, y = -1;

        bool mod_is_even = false;
        for (size_t i {0}; i < elem.arr.size() && !mod_is_even; ++i) {
            for (size_t k {i+1}; k < elem.arr.size(); ++k){
                int modX = (elem.arr[k] % elem.arr[i]);
                if (modX % 2 == 0) { // zero is not even.
                    x = elem.arr[i];
                    y = elem.arr[k];
                    mod_is_even = true;
                    break;
                };
            }
        }

        if (mod_is_even)
            std::cout << x << ' ' << y << '\n';
        else 
            std::cout << -1 << '\n';
    }

    return 0;
}