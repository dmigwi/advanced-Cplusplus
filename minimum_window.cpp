#include <iostream>   
#include <algorithm>    
#include <vector> 

using Number = long long;

void minWindow(const std::vector<Number>& data, Number winSize) {
    auto start = data.begin()-1;
    auto end  = start+winSize;
    
    auto minElemIt = start;
    Number minElem = 0;
    
    do {
        ++start;
        ++end; 
        if (start == data.begin() || (start-1) == minElemIt) {
            minElemIt = std::min_element(start, end);
         } else if (*(end-1) < *minElemIt) {
            minElemIt = end-1;
        }

        minElem = minElem ^ (*minElemIt);
    } while (end != data.end());
    std::cout << minElem << '\n'; 
}

int main () {
    size_t n; 
    Number k;
    std::cin >> n >> k;
    
    Number x, a, b,c;
    std::cin >> x >> a >> b >> c;

    // if a consecutive array is generated from start to end then its minimum
    // window is equal to:
    if (x == 0 &&  static_cast<Number>(n) < c){
        std::cout << static_cast<Number>(n)-k << '\n'; 
        return 0;
    }
    
    std::vector<Number> input(n);
    input[0] = x;
    
    for (size_t i {1}; i < n; ++i) {
        input[i] = ((input[i-1]*a) + b) % c;
    }

    
    minWindow(input, k);
  
  return 0;
}