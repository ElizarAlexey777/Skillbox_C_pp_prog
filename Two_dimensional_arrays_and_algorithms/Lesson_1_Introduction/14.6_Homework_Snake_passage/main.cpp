#include <iostream>

int main() {
    std::cout << "Snake passage" << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;

    int snake_matrix[5][5];

    int count = 0;
    for (int i = 1; i <= 5; i += 2) {
        for (int j = 0; j < 5; j++) {
            snake_matrix[i-1][j] = count;
            count++;
        }
        for(int j = 4; j >= 0; j--) {
            snake_matrix[i][j] = count;
            count++;
        }
    }

    for (auto & i : snake_matrix) {
        for (int j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}