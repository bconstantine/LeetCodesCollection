#include <iostream>
#include <set>

int main() {
    std::set<int> st = {10, 20, 30};

    // Basic operations
    st.insert(40);  // Add an element
    st.erase(20);   // Remove an element

    // Additional operations
    if (st.find(30) != st.end()) { // Find an element
        std::cout << "30 found" << std::endl;
    }

    // Iteration
    for(int num : st) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
