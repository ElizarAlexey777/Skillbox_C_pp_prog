#include <iostream>
#include <vector>

int main() {
    std::cout << "Multiplication of a matrix by a vector" << std::endl;
    std::cout << std::endl;

    std::vector<float> V(4);
    float matrix[4][4];

    std::cout << "Enter vector elements: " << std::endl;
    for (int i = 0; i < 4; i++) std::cin >> V[i];

    std::cout << "Enter matrix elements: " << std::endl;
    for (auto & i : matrix) {
        for (float & j : i) {
            std::cin >> j;
        }
    }

    float R[4];
    for (int i = 0; i < 4; i++) {
        float summa = 0.f;
        for (int j = 0; j < 4; j++) {
            summa += matrix[i][j] * V[i];
        }
        R[i] = summa;
    }

    for (float i : R) {
        std::cout << i << ' ';
    } std::cout << std::endl;
    return 0;
}
