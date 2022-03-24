#include <iostream>
#include <vector>

int main() {
    std::cout << "Multiplication of a matrix by a vector" << std::endl;
    std::cout << std::endl;

    std::vector<float> V(4);
    float M[4][4];

    std::cout << "Enter vector V elements: " << std::endl;
    for (int i = 0; i < 4; i++) std::cin >> V[i];

    std::cout << "Enter matrix M elements: " << std::endl;
    for (auto & i : M) {
        for (float & j : i) {
            std::cin >> j;
        }
    }

    std::cout << std::endl;
    std::cout << "Vector V: " << std::endl;
    for (float i : V) {
        std::cout << i << ' ';
    } std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Matrix M: " << std::endl;
    for (auto & i : M) {
        for (float & j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    } std::cout << std::endl;

    float R[4];
    for (int i = 0; i < 4; i++) {
        float summa = 0.f;
        for (int j = 0; j < 4; j++) {
            summa += M[i][j] * V[i];
        }
        R[i] = summa;
    }

    std::cout << "Array R: " << std::endl;
    for (float i : R) {
        std::cout << i << ' ';
    } std::cout << std::endl;
    return 0;
}
