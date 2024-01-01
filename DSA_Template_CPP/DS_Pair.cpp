#include <iostream>
#include <utility>

int main() {
    std::pair<std::string, int> pr = {"apple", 5};
    std::pair<int,int> a = std::make_pair(10, 10);

    // Operations
    pr.first = "banana"; // Modify first element
    pr.second = 10;      // Modify second element

    std::cout << pr.first << " => " << pr.second << std::endl;

    return 0;
}
