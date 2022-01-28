#include <iostream>

std::string get_num(std::string address, int num) {
    int count = 1;
    std::string address_num;
    for (int i = 0; i < address.length(); i++) {
        if (count == num) {
            while (address[i] != '.' and i < address.length()) {
                address_num += address[i];
                i++;
            } return address_num;
        }
        if (address[i] == '.') count++;
    }
    return address_num;
}

bool check_num(std::string number) {
    if (number == std::to_string(std::stoi(number))) {
        if (std::stoi(number) >= 0 and std::stoi(number) <= 255) {
            return true;
        } else {
            std::cout << "Numbers greater than 255 or less than 0 in part " << number << std::endl;
            return false;
        }
    } else {
        std::cout << "Extra zeros in part " << number << std::endl;
        return false;
    }
}

int main() {
    std::cout << "IP Address Validation" << std::endl;
    std::cout << std::endl;

    std::string address;

    std::cout << "Enter your address for checking the correctness:" << std::endl;
    std::cin >> address;

    std::string alphabet = "1234567890.";
    int count_dot = 0;

    if (address[0] != '.' and address[address.length()-1] != '.') {
        for (int i = 0; i < address.length() - 1; i++) {
            if (address[i] == '.') {
                count_dot++;
                if (address[i + 1] == '.') {
                    std::cout << "Two dots cannot be consecutive" << std::endl;
                    return -1;
                }
            }
            if (alphabet.find(address[i]) == std::string::npos) {
                std::cout << "Extraneous characters other than numbers and dots" << std::endl;
                return -1;
            }
        }
    } else {
        std::cout << "Extra dot at the beginning or end of the address" << std::endl;
        return -1;
    }

    if (count_dot != 3) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }

    bool first_number_bool = check_num(get_num(address, 1));
    bool second_number_bool = check_num(get_num(address, 2));
    bool third_number_bool = check_num(get_num(address, 3));
    bool fourth_number_bool = check_num(get_num(address, 4));

    if (first_number_bool and second_number_bool and third_number_bool and fourth_number_bool) {
        std::cout << "Yes" << std::endl;
    } else std::cout << "No" << std::endl;
    return 0;
}
