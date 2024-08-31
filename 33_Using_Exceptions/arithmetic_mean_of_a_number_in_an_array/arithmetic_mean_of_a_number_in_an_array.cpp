#include <iostream>

template <typename T>
void input(T array[8]) {
    std::cout << "Fill the array (8 elements): ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> array[i];
    }
}

template <typename T>
T calculateAverage(T array[8]) {
    T sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    return sum / 8;
}

int main() {
    int intArray[8];
    input(intArray);
    std::cout << "Average for int: " << calculateAverage(intArray) << std::endl;

    double doubleArray[8];
    input(doubleArray);
    std::cout << "Average for double: " << calculateAverage(doubleArray) << std::endl;

    return 0;
}
