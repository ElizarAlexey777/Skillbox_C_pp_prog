#include <iostream>

int main() {
    std::cout << "Apartment house" << std::endl;
    std::cout << std::endl;

    std::string tenants[10];

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter the last name of " << i + 1 << " tenant:" << std::endl;
        std::cin >> tenants[i];
    }

    int apart_num;
    std::cout << "Enter three apartment numbers:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cin >> apart_num;
        if (apart_num > 10 or apart_num < 1) {
            std::cout << "Invalid apartment number" << std::endl;
            continue;
        }
        std::cout << tenants[apart_num-1] << " lives in apartment number " << apart_num << std::endl;
    }
    return 0;
}
