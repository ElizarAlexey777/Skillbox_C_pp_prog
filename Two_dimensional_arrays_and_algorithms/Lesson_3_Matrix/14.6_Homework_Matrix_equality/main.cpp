#include <iostream>

int main() {
    std::cout << "Matrix equality" << std::endl;
    std::cout << std::endl;

    int matrix_a[4][4];
    int matrix_b[4][4];

    bool equal = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            std::cout << "Enter a number into the first matrix: " << std::endl;
            std::cin >> matrix_a[i][j];
            std::cout << "Enter a number into the second matrix: " << std::endl;
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
