#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> lst = {10, 20, 30};

    // Basic operations
    lst.push_back(40);  // Add to the end
    lst.push_front(5);  // Add to the front
    lst.pop_back();     // Remove from the end
    lst.pop_front();    // Remove from the front

    // Additional operations
    auto it = lst.begin();
    std::advance(it, 1); // Move iterator to the middle
    lst.insert(it, 15);  // Insert in the middle
    lst.remove(20);      // Remove a specific value

    // Iteration
    for(int num : lst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto it2 = lst.end();
    // Move to the last element
    it2 = std::prev(it2);

    // Check if it's the last element
    if (std::next(it2) == lst.end()) {
        std::cout << "It's the last element: " << *it2 << std::endl;
    }

    // Move to the previous element
    it2 = std::prev(it2);

    // Check if it's the first element
    if (it2 == lst.begin()) {
        std::cout << "It's the first element: " << *it2 << std::endl;
    }

    std::cout << "Total element: " << lst.size() << "\n";

    return 0;
}
