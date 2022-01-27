#include <iostream>

std::string side_address(std::string address, std::string type_side) {
    int i = 0;
    int count_sym = 0;
    int cut = 0;
    bool flag = false;
    while (i <= address.length()) {
        if (address[i] == '@') {
            flag = true;
            cut = i;
            count_sym++;
        }
        i++;
    }
    if (flag) {
        if (count_sym > 1) return "@@";
        if (type_side == "left") return address.substr(0, cut);
        else if (type_side == "right") return address.substr(cut + 1, -1);
    } return "@";
}

int main() {
    std::cout << "Checking the correctness of the email address" << std::endl;
    std::cout << std::endl;

    std::string address;

    std::cout << "Enter your address for checking the correctness:" << std::endl;
    std::cin >> address;

    std::string left_side = side_address(address, "left");
    std::string right_side = side_address(address, "right");

    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";
    std::string left_side_add = "!#$%&'*+/=?^_`{|}~";

    if (left_side == "@" or right_side == "@") {
        std::cout << "No @ symbol" << std::endl;
        return -1;
    }

    if (left_side == "@@" or right_side == "@@") {
        std::cout << "There must be only one @ symbol" << std::endl;
        return -1;
    }

    if ((left_side.length() >= 1 and left_side.length() < 65) and (right_side.length() >= 1 and right_side.length() < 64)) {
        if (left_side[0] != '.' and left_side[-1] != '.' and right_side[0] != '.' and right_side[-1] != '.') {
            for (int i = 0; i < left_side.length() - 1; i++) {
                if (left_side[i] == '.' and left_side[i + 1] == '.') {
                    std::cout << "Two dots cannot be consecutive" << std::endl;
                    return -1;
                }
                if (alphabet.find(left_side[i]) == std::string::npos and left_side_add.find(left_side[i]) == std::string::npos) {
                    std::cout << "Invalid characters present" << std::endl;
                    return -1;
                }
            }
            for (int i = 0; i < right_side.length() - 1; i++) {
                if (left_side[i] == '.' and left_side[i + 1] == '.') {
                    std::cout << "Two dots cannot be consecutive" << std::endl;
                    return -1;
                }
                if (left_side_add.find(right_side[i]) != std::string::npos) {
                    std::cout << "There is an invalid character on the right side from the list of valid characters on the left side" << std::endl;
                    return -1;
                }
                if (alphabet.find(right_side[i]) == std::string::npos) {
                    std::cout << "Invalid characters present" << std::endl;
                    return -1;
                }
            }
        } else {
            std::cout << "Point at the beginning or end of a side" << std::endl;
            return -1;
        }
    } else {
        std::cout << "Some part is longer than 63-64 characters" << std::endl;
        return -1;
    }
    std::cout << "Ok" << std::endl;
    return 0;
}
