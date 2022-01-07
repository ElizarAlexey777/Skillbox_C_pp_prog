#include <iostream>

std::string encrypt_caesar(std::string stroka, int num_sdvig) {

}

int main() {
    std::cout << "Caesar cipher implementation" << std::endl;
    std::cout << std::endl;

    std::string stroka;
    int num_sdvig;

    std::cout << "Enter the original string: " << std::endl;
    std::cin >> stroka;

    std::cout << "Enter numeric shift: " << std::endl;
    std::cin >> num_sdvig;

    std::cout << "The original string in Caesar cipher: " << encrypt_caesar(stroka, num_sdvig) << std::endl;

    return 0;
}
