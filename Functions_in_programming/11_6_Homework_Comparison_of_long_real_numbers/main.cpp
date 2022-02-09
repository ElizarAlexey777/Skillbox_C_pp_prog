#include <iostream>

std::string get_num(std::string number, std::string part) {
    std::string alph = "1234567890-.";
    int count_point = 0;
    std::string whole_part, fraction;
    for (int i = 0; i < number.length(); i++) {
        if (alph.find(number[i]) == std::string::npos) {
            std::cout << "Invalid data" << std::endl;
            return "";
        }
        if (number[i] == '-' and i != 0) {
            std::cout << "Wrong minus position" << std::endl;
            return "";
        }
        if (number[i] == '.') {
            if (count_point > 0) {
                std::cout << "Incorrect number entry" << std::endl;
                return "";
            }
            count_point += 1;
            whole_part = number.substr(0, i);
            fraction = number.substr(i+1, number.length() - 1);
        }
        if (i == number.length() - 1 and count_point == 0 and part == "whole") {
            return number.substr(0, i + 1);
        }
    }

    int count_null_whole = 0;
    if (whole_part[0] == '0' and part == "whole") {
        for (char j : whole_part) {
            if (j == '0') {
                count_null_whole++;
            } else {
                break;
            }
        }
        if (whole_part.length() <= 8) {
            if (std::stoi(whole_part) != 0) {
                whole_part = whole_part.substr(count_null_whole, whole_part.length());
            } else {
                whole_part = "0";
            }
        } else {
            whole_part = whole_part.substr(count_null_whole, whole_part.length());
        }
    }

    int count_null_fract = fraction.length();
    if (fraction[fraction.length() - 1] == '0' and part == "fraction") {
        for (int j = fraction.length(); j > 0; j--) {
            if (fraction[j-1] == '0') {
                count_null_fract--;
            } else {
                break;
            }
        }
        if (std::stoi(fraction) != 0) {
            fraction = fraction.substr(0, count_null_fract);
        } else {
            fraction = "";
        }
    }
    if (part == "whole") {
        return whole_part;
    } else if (part == "fraction") {
        return fraction;
    }
}

std::string number_comprasion(std::string num1_whole, std::string num1_fraction, std::string num2_whole, std::string num2_fraction) {
    if (num1_whole.empty() or num2_whole.empty()) {
        return "";
    }
    if (num1_whole[0] == '-' or num2_whole[0] == '-') {
        if (num1_whole.length() <= 2 and num2_whole.length() <= 2 and std::stoi(num1_whole) == std::stoi(num2_whole)) {
            return "equal";
        }
        if (num2_whole[0] == '-' and num1_whole[0] != '-') {
            return "more";
        } else if (num1_whole[0] == '-' and num2_whole[0] != '-') {
            return "less";
        }
    }
    if (num1_whole.length() != num2_whole.length() or num1_fraction.length() != num2_fraction.length()) {
        if (num1_whole.length() != num2_whole.length()) {
            return num1_whole.length() > num2_whole.length() ? "more" : "less";
        } else {
            return num1_fraction.length() > num2_fraction.length() ? "more" : "less";
        }
    }
    if (num1_whole.length() <= 8 and num2_whole.length() <= 8 and std::stoi(num1_whole) == std::stoi(num2_whole)) {
        if (num1_fraction.empty() or num2_fraction.empty()) {
            return "equal";
        } else if (std::stoi(num1_fraction) == std::stoi(num2_fraction)) {
            return "equal";
        } else {
            for (int i = 0; i < num1_fraction.length(); i++) {
                if (num1_fraction[i] != num2_fraction[i]) {
                    if (num1_fraction[i] > num2_fraction[i]) {
                        return "more";
                    } else {
                        return "less";
                    }
                }
            }
        }
    } else if (num1_whole.length() <= 8 and num2_whole.length() <= 8 and std::stoi(num1_fraction) == std::stoi(num2_fraction)) {
        for (int i = 0; i < num1_whole.length(); i++) {
            if (num1_whole[i] != num2_whole[i]) {
                if (num1_whole[i] > num2_whole[i]) {
                    return "more";
                } else {
                    return "less";
                }
            }
        }
    } else {
        std::string number_1 = num1_whole + num1_fraction;
        std::string number_2 = num2_whole + num2_fraction;
        if (number_1 == number_2) return "equal";
        for (int i = 0; i < number_1.length(); i++) {
            if (num1_whole[i] != num2_whole[i]) {
                if (num1_whole[i] > num2_whole[i]) {
                    return "more";
                } else {
                    return "less";
                }
            }
        }
    }
}

int main() {
    std::cout << "Comparison of long real numbers" << std::endl;
    std::cout << std::endl;

    std::string number_1, number_2;

    std::cout << "Enter the first real number:" << std::endl;
    std::cin >> number_1;

    std::cout << "Enter the second real number:" << std::endl;
    std::cin >> number_2;

    std::string answer = number_comprasion(get_num(number_1, "whole"),
                                           get_num(number_1, "fraction"),
                                           get_num(number_2, "whole"),
                                           get_num(number_2, "fraction")
                                           );

    if (answer == "more") {
        std::cout << "The first number is more than the second" << std::endl;
    } else if (answer == "less") {
        std::cout << "The first number is less than the second" << std::endl;
    } else if (answer == "equal") {
        std::cout << "The first number is equal to the second" << std::endl;
    }
    return 0;
}
