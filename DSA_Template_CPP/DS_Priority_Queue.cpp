#include <iostream>
#include <queue>
#include <functional> // For std::greater

int main() {
    // Max heap (descending order)
    std::priority_queue<int> maxHeap;

    // Min heap (ascending order)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements
    for (int num : {10, 5, 20}) {
        maxHeap.push(num);
        minHeap.push(num);
    }

    // Print and pop from max heap
    std::cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    // Print and pop from min heap
    std::cout << "Min Heap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
