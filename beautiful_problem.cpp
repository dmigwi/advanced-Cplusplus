#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 10'000'000;

struct Info {
    std::vector<int> data;                      // test case data
    std::vector<std::pair<int,int>> range;    // iterator interval;
};

int func(int x, int min, int max) {
    auto result = (x - min) * (x - max);
    if (result >= 0)
        return 1;
    return 0;
}

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

            range.first = --s;  // adjust to zero based index
            range.second = --e; // adjust to zero based index
        }
    }
       
    // Start processing data for each test instance
    for (auto test : values) {
        for (size_t k {0}; k < test.data.size(); ++k) {
            int output = INF;
            auto dataCopy = test.data;

            // Test all the permutations.
            do {
                // For each permutation loop through all ranges and get the min.
                for (auto [s, e]: test.range) {
                    auto [min, max] = std::minmax_element(
                            dataCopy.begin() + s, dataCopy.begin() + e
                        );
                    output = std::min(output, func(test.data[k], *min, *max));
                }
            } while (std::next_permutation(dataCopy.begin(), dataCopy.end()));
            std::cout << output << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}