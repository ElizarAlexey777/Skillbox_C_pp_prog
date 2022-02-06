#include <iostream>

bool check_field(std::string line1, std::string line2, std::string line3, int part) {
    if (part == 1) {
        std::string field = line1 + line2 + line3;
        std::string alphabet = "XO.";
        if (field.length() != 9) return false;
        for (char i : field) {
            if (alphabet.find(i) == std::string::npos) {
                std::cout << "There are invalid characters on the field" << std::endl;
                return false;
            }
        }
        return true;
    }
    return true;
}

std::string get_line(int line_num, std::string l1, std::string l2, std::string l3) {
    std::string cur_line;
    if (line_num == 1) {
        return l1;
    } else if (line_num == 2) {
        return l2;
    } else if (line_num == 3) {
        return l3;
    }
    return cur_line;
}

bool check_win_line(std::string cur_line) {
    if (cur_line[0] == cur_line[1] == cur_line[2] and cur_line != "...") {
        return true;
    } return false;
}

std::string who_win(std::string cur_line) {
    return (cur_line[0] == 'X' ? "Petya won" : "Vasya won");
}

std::string winner(std::string l1, std::string l2, std::string l3, int part) {
    for (int line = 0; line <= 3; line++) {
        std::string cur_line = get_line(line, l1, l2, l3);
        if (check_win_line(cur_line)) {
            return who_win(cur_line);
        }
    }
    return "Nobody";
}

int main() {
    std::cout << "Analysis of the results of the game of tic-tac-toe" << std::endl;
    std::cout << std::endl;

    std::string line1, line2, line3;

    std::cout << "Enter the lines of the playing field: " << std::endl;
    std::cin >> line1;
    std::cin >> line2;
    std::cin >> line3;

    if (!(check_field(line1, line2, line3, 1))) {
        std::cout << "Incorrect" << std::endl;
        return -1;
    }

    std::cout << winner(line1, line2, line3, 2) << std::endl;
    return 0;
}