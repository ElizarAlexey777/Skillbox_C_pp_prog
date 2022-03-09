#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Task 3" << std::endl;
    std::cout << std::endl;

    std::vector<int> integers(20);

    std::cout << "Enter the numbers: " << std::endl;
    for (int i = 19; i >= 0; i--) {
        std::cin >> integers[i];
    }

    int inp = 0;
    std::cin >> inp;
    while (inp != -1) {
        integers.back() = inp;
        std::rotate(integers.rbegin(),integers.rbegin() + 1,integers.rend());
        std::cin >> inp;
    }

    std::cout << "Edited database: ";
    for (int integer : integers) {
        std::cout << integer << ' ';
    }
    return 0;
}
