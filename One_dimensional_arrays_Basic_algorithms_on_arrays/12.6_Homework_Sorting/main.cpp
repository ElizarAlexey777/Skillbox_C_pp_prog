#include <iostream>

int main() {
    std::cout << "Sorting" << std::endl;
    std::cout << std::endl;

    float mas[15];

    std::cout << "Enter array elements: " << std::endl;
    for (float & i : mas) {
        std::cin >> i;
    }

    for (int i = 0; i < 15 - 1; ++i)
    {
        int ind = i;
        for (int j = i + 1; j < 15; ++j)
        {
            if (mas[j] < mas[ind])
                ind = j;
        }
        std::swap(mas[i], mas[ind]);
    }

    std::cout << "Sorted array elements in ascending order: " << std::endl;
    for (float i : mas)
        std::cout << i << ' ';

    return 0;
}
