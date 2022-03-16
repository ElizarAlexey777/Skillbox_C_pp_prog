#include <iostream>

int main() {
    std::cout << "Matrix equality" << std::endl;
    std::cout << std::endl;

    int matrix_a[4][4];
    int matrix_b[4][4];

    std::cout << "Enter numbers in the first matrix: " << std::endl;
    for (auto & i : matrix_a) {
        for (int & j : i) {
            std::cin >> j;
        }
    }

    bool equal = true;
    std::cout << "Enter numbers into the second matrix: " << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix_b[i][j];
            if (matrix_a[i][j] != matrix_b[i][j]) {
                equal = false;
            }
        }
    }

    std::cout << "First matrix: " << std::endl;
    for (auto & i : matrix_a) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "Second matrix: " << std::endl;
    for (auto & i : matrix_b) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    if (equal) {
        std::cout << "First matrix equals second matrix" << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "The first matrix does not equal the second matrix" << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
