#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mp = {{"apple", 5}, {"banana", 10}};

    // Basic operations
    mp["orange"] = 20; // Add a key-value pair
    mp.erase("banana"); // Remove a key-value pair

    // Additional operations
    if (mp.find("apple") != mp.end()) { // Find a key-value pair
        std::cout << "apple found" << std::endl;
    }

    // Iteration
    for(auto& pair : mp) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }
    for(auto pair : mp) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    return 0;
}
