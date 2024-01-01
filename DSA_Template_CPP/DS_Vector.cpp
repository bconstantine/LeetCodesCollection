#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30};

    // Basic operations
    vec.push_back(40);  // Add to the end
    vec.pop_back();     // Remove from the end

    // Additional operations
    vec.insert(vec.begin() + 1, 15); // Insert in the middle
    vec.erase(vec.begin() + 2);      // Remove from the middle
    auto it = std::find(vec.begin(), vec.end(), 15); // Find a value
    if (it != vec.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    // Iteration
    for(int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // std::cout << "Hello world";

    return 0;
}
