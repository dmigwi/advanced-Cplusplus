#include <iostream>
#include <vector>

struct Info {
    int scores;
    int div2_entry_req;
    int check_limit;
    size_t rounds;
    std::vector<char> play_order;
};

int main() {
    // I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t tests;
    std::cin >> tests;

    std::vector<Info> cases (tests);

    // Load Input data
    for (auto& c : cases) {
        std::cin >> c.scores >> c.div2_entry_req >> c.check_limit >> c.rounds;
        c.play_order.resize(c.rounds);

        for (auto& r : c.play_order) {
            std::cin >> r;
        }
    }

    // Process the cases
    for (auto& c: cases) {
        int played_rounds {0};

        // Run the play order.
        for (auto&  order : c.play_order) {
            if (order == '1') { // play division 1
                ++played_rounds;
                // c.scores += ;
            } else { // play division 2
                if (c.scores < c.div2_entry_req) {
                    ++played_rounds;
                }
            }
        }
        std::cout << played_rounds << '\n';
    }

    return 0;
}