#include <iostream>
#include <vector>


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
        integers.push_back(inp);
        for (int i = 0; i < integers.size(); i++) {
            integers[i] = integers[i + 1];
        }
        integers.pop_back();
        std::cin >> inp;
    }

    std::cout << "Edited database: ";
    for (int integer : integers) {
        std::cout << integer << ' ';
    }
    return 0;
}
