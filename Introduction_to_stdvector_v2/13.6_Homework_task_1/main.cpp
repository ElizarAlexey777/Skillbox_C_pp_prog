#include <iostream>
#include <vector>

int main() {
    std::cout << "Task 1" << std::endl;
    std::cout << std::endl;

    int n;
    std::cout << "Enter the number of integers you want to write to the vector:" << std::endl;
    std::cin >> n;

    std::vector<int> integers(n);

    std::cout << "Enter the numbers: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> integers[i];
    }

    int del_num;
    std::cout << "Enter the number you want to remove from the vector:" << std::endl;
    std::cin >> del_num;

    for (int i = 0; i < integers.size();) {
        if (integers[i] == del_num) {
            for (int j = i; j < integers.size() - 1; j++) {
                integers[j] = integers[j+1];
            }
            integers.pop_back();
        } else {
            i++;
        }
    }

    std::cout << "Edited vector: ";
    for (int integer : integers) {
        std::cout << integer << ' ';
    }
    return 0;
}
