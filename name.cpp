#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t q {};
    std::cin >> q;

    std::vector<std::pair<std::string, std::string>> data (q);
    size_t len {};
    // Read all the data
    for (auto& entry : data) {
        std::cin >> len;
        std::cin.ignore();                          // ignore any pending characters
        std::getline(std::cin, entry.first, ' ');   // first string 
        std::getline(std::cin, entry.second, '\n'); // second string 
    }

    // process the data 2D anagram matching list
    for (auto& entry : data) {
        std::sort(entry.first.begin(), entry.first.end());
        std::sort(entry.second.begin(), entry.second.end());

        std::cout << ((entry.first == entry.second) ? "YES" : "NO") << '\n';
    }
}