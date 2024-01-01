#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {10, 20, 30};

    // Basic operations
    dq.push_back(40);   // Add to the end
    dq.push_front(5);   // Add to the front
    dq.pop_back();      // Remove from the end
    dq.pop_front();     // Remove from the front

    // Additional operations
    dq.insert(dq.begin() + 1, 15); // Insert in the middle
    dq.erase(dq.begin() + 2);      // Remove from the middle

    // Iteration
    for(int num : dq) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
