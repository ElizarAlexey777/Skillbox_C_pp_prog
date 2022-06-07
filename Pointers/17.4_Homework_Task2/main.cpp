#include <iostream>

void reverse(int *pmas) {
    for (int i = 0; i < 5; i++) {
        std::swap(*(pmas + i), *(pmas + 9 - i));
    }
}

int main() {
    std::cout << "Task 2" << std::endl;
    std::cout << std::endl;

    int mas[10];

    std::cout << "Enter array elements (10 elements)" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Enter the " << i+1 << " element of the array:" << std::endl;
        std::cin >> mas[i];
    }

    std::cout << "Received array:" << std::endl;
    for (int i : mas) {
        std::cout << i << ' ';
    }

    reverse(mas);

    std::cout << "Reversed array:" << std::endl;
    for (int i : mas) {
        std::cout << i << ' ';
    }
    return 0;
}
