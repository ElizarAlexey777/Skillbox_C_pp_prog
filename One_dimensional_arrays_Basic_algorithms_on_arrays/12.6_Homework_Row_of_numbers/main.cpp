#include <iostream>

int main() {
    std::cout << "Row of numbers" << std::endl;
    std::cout << std::endl;

    int numbers[15] = {114,111, 106, 107, 108, 105, 115,  108, 110, 109, 112, 113, 116, 117, 118};

    for (int number : numbers) {
        int count = 0;
        for (int j : numbers) {
            if (number == j) {
                count++;
                if (count >= 2) {
                    std::cout << "Repeating number: " << number << std::endl;
                    break;
                }
            }
        }
        if (count >= 2) {
            break;
        }
    }
    return 0;
}
