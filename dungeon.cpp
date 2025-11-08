#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using Num = long long;

struct Info {
    std::multiset<Num> swords;
    std::vector<std::pair<Num,Num>> monsters;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n {};
    std::cin >> n;

    std::vector<Info> data (n);
    for (auto& elem : data) {
        size_t n, m {};

        std::cin >> n >> m;
        int value {};
        for (size_t i {0}; i < n; ++i) {
            std::cin >> value;
            elem.swords.insert(value);
        }

        elem.monsters.resize(m);

        for (auto& value : elem.monsters) { std::cin >> value.first; }
        for (auto& value : elem.monsters) { std::cin >> value.second; }

        // sort monsters by descending order so as to kill strong one first.
        std::sort(elem.monsters.begin(), elem.monsters.end(), [](auto A, auto B){
            if (A.first != B.first) return A.first < B.first;
            return A.second > B.second;
        }); 
    }
   
    for (auto elem : data) {
        Num killed = 0;
        for (auto [b, c] : elem.monsters) {
            auto it = elem.swords.lower_bound(b);
            if (it == elem.swords.end()) {
                continue;
            }

            ++killed;
            Num x = *it;
            elem.swords.erase(it);
            if (c > 0) {
                elem.swords.insert(std::max(x, c));
            } 
        }
        std::cout << killed << '\n';
    }

    return 0;
}
