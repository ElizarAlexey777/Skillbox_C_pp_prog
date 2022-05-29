#include <iostream>

int main() {
    std::cout << "Fractional stitcher" << std::endl;
    std::cout << std::endl;

    std::string int_part, fract_part;

    std::cout << "Enter the integer part of the number: " << std::endl;
    std::cin >> int_part;

    std::cout << "Enter the fractional part of the number: " << std::endl;
    std::cin >> fract_part;

    std::string str_num = int_part + "." + fract_part;
    double double_num = std::stod(str_num);

    std::cout << "Floating point number: " << double_num << std::endl;
    return 0;
}
