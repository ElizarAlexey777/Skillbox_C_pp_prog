#include <iostream>

int main() {
    std::cout << "Almost Minecraft" << std::endl;
    std::cout << std::endl;

    int square_landscape_2d[5][5];

    std::cout << "Enter heights of square terrain blocks in 2D representation: " << std::endl;
    for (auto & i : square_landscape_2d) {
        for (int & j : i) {
            do {
                std::cin >> j;
                if (j > 10) std::cout << "Maximum block height is 10. Please try again!" << std::endl;
            } while (j > 10);
        }
    }

    std::cout << "Square landscape in 2D representation: " << std::endl;
    for (auto & i : square_landscape_2d) {
        for (int j : i) {
            std::cout << j << ' ';
        } std::cout << std::endl;
    }

    int square_landscape_3d[5][10][5];

    for (int x = 0; x < 5; x++) {
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < 5; j++) {
                if (i < square_landscape_2d[x][j]) {
                    square_landscape_3d[x][std::abs(i - 9)][j] = 1;
                } else {
                    square_landscape_3d[x][std::abs(i - 9)][j] = 0;
                }
            }
        }
    }

    std::cout << "Square landscape in 3D representation: " << std::endl;
    for (auto & x : square_landscape_3d) {
        for (auto & i : x) {
            for (int j : i) {
                std::cout << j << ' ';
            } std::cout << std::endl;
        } std::cout << std::endl;
    }
    return 0;
}
