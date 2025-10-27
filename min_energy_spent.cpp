#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

// https://codeforces.com/problemset/problem/706/C

using Num = long long;
const Num INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false); // prevent sync between c and c++ streams
    std::cin.tie(nullptr);                 // untie cin from cout.

    size_t n;
    std::cin >> n;
    
    // Units of energy to spend per string sorting.
    std::vector<Num> cost (n);
    for(size_t i {0}; i < n; ++i){
        std::cin >> cost.at(i);
    }

    // Ignore characters after int scanning
    std::string ignore {};
    std::getline(std::cin, ignore, '\n');

    // Strings to be sorted lexicographically.
    std::vector<std::string> s (n), rev(n);
    for(size_t i {0}; i < n; ++i){
        std::getline(std::cin, s[i], '\n');

        // reverse each string entry.
        rev[i] = std::string(s[i].rbegin(), s[i].rend());
    }

    // Create a map of all possible costs at normal and reverse costs
    std::vector<std::pair<Num, Num>> dp (n , {INF, INF});
    dp[0] = {0, cost[0]};

    for(size_t i {1}; i < n; ++i){
        if (s[i-1] <= s[i])
            dp[i].first = std::min(dp[i].first, dp[i-1].first);

        if (rev[i-1] <= s[i])
            dp[i].first = std::min(dp[i].first, dp[i-1].second);

        if (s[i-1] <= rev[i])
            dp[i].second = std::min(dp[i].second, dp[i-1].first + cost[i]);
        
        if (rev[i-1] <= rev[i])
            dp[i].second = std::min(dp[i].second, dp[i-1].second + cost[i]);
    }

    Num minCost = std::min(dp[n-1].first, dp[n-1].second);
    if (minCost >= INF)
        std::cout << -1 << '\n';
    else
        std::cout << minCost << '\n';
}
