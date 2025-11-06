#include <iostream>
#include <vector>
#include <string>

using Map2D = std::vector<std::vector<char>>;

bool findDrawableCell(const Map2D& data) {
    std::vector<char> neighbours
    for (size_t y {0}; y < data.size(); ++y) {
        for (size_t x {0}; x < data.size(); ++x) {
            if (data[x][y] == '.') { // if it is white cell
                // Handle Top cells
                if (y > 0)
                // Handle Right cells
                // Handle Bottom cells
                // Handle Left cells
            }
        }
    }
    return false;
}

int main() {
    // I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t tests;
    std::cin >> tests;

    std::vector<Map2D> cases (tests);

    // Load Input data
    for (auto& c : cases) {
        int len {};
        std::cin >> len;
        c.resize(len);

        for (auto& r : c) {
            for (auto& elem : r) {
                std::cin >> elem;
            }
        }
    }

    // Process the data
    for (auto& c : cases) {
        // find a white cell
        // int x {}, y {};
        bool isFound {false};
        for (size_t x {0}; x < c.size(); ++x) {
            if (isFound) // Exit the for loop prematurely if search condition matches
                break;
            for (size_t y {0}; y < c.size(); ++y) {
                if (isFound) 
                    break;
                if (c[x][y] == '.') { // if it is white cell
                    // Handle Top cells
                    // Handle Right cells
                    // Handle Bottom cells
                    // Handle Left cells
                }
            }
        }
    }
}