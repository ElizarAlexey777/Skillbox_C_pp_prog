#include <iostream>

int main() {
    std::cout << "Diagonal Matrix" << std::endl;
    std::cout << std::endl;

    int M[4][4];

    std::cout << "Enter numbers into the matrix: " << std::endl;
    for (auto & i : M) {
        for (int & j : i) {
            std::cin >> j;
        }
    }
    std::cout << "Input Matrix: " << std::endl;
    for (auto & i : M) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                M[i][j] = 0;
            }
        }
    }

    std::cout << "Diagonal Matrix: " << std::endl;
    for (auto & i : M) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
