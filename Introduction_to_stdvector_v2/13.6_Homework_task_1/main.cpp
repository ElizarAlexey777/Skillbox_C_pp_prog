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

    int ind_del = 0;
    for (int i = 0; i < integers.size(); i++) {
        if (integers[i] != del_num) {
            integers[ind_del] = integers[i];
            ind_del++;
        }
    }
    integers.resize(del_num);

    std::cout << "Edited vector: ";
    for (int integer : integers) {
        std::cout << integer << ' ';
    }
    return 0;
}
