#include <iostream>

void swap(int* pa, int* pb) {
    std::swap(*pa, *pb);
}


int main() {
    std::cout << "Task 1" << std::endl;
    std::cout << std::endl;

    int a = 10;
    int b = 20;
    swap(&a, &b);
    std::cout << a << " " << b;
    return 0;
}
