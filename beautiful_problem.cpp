#include <iostream>
#include <vector>
#include <algorithm>

struct Info {
    std::vector<int> data;                      // test case data
    std::vector<std::pair<int,int>> range;    // iterator interval;
};

int main () {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n {};
    std::cin >> n;

    std::vector<Info> values (n);

    // Collectively read all the entry data.
    for (auto& test : values) {
        size_t len {}, m {};
        
        std::cin >> len >> m;
        test.data.resize(len);
        test.range.resize(m);

        // Read the Main array
        for (auto& elem : test.data)
            std::cin >> elem;

        // Read the interval array
        for (auto& range : test.range) {
            int s, e {};
            std::cin >> s >> e;

            range.first = s;
            range.second = e;
        }
    }
       
    // Start processing data for each test instance
    for (auto test : values) {
        int max = 0;
        int size = static_cast<int>(test.data.size());
        int min = size;

        for (auto [l, r] : test.range) {
            min = std::min(min, l);
            max = std::max(max, r);
        }

        std::string result (test.data.size(), '0');
        // Test for possible ks 1 <= x <= 0.
        for (int x {1}; x <= size; ++x) {
            bool has_smaller = false, has_larger = false;
                for (int v : test.data) {
                    if (v < x) has_smaller = true;
                    if (v > x) has_larger = true;
                    if (has_smaller && has_larger) break;
                }

                // check if is overlapping.
                if (has_smaller && has_larger) 
                    *(result.begin()+(x - 1)) = '1';
        }
        std::cout << result << '\n';
    }

    return 0;
}