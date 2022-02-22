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
        std::rotate(integers.begin(),integers.begin()-1,integers.end());
        integers.back() = inp;
        std::cin >> inp;
    }

    std::cout << "Edited database: ";
    for (int integer : integers) {
        std::cout << integer << ' ';
    }
    return 0;
}
