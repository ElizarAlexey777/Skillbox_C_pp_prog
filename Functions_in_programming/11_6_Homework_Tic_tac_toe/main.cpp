#include <iostream>

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

int check_correctness(std::string line) {
    int count_xo_field = 0;
    for (char & i : line) {
        if (i == 'X') {
            count_xo_field++;
        } else if (i == 'O') {
            count_xo_field--;
        }
    }
    return count_xo_field;
}

std::string line_winner(std::string line) {
    if(line[0] == line[1] && line[0] == line[2]){
        if(line[0] == 'X'){
            return "Petya";
        }
        else if(line[0] == 'O'){
            return "Vasya";
        }
    }
    return "Nobody";
}

bool check_line(std::string l1, std::string l2, std::string l3) {
    std::string result;
    std::string winner;
    int count_line_wins = 0;
    for (int line = 1; line <= 3; line++) {
        std::string cur_line = get_line(line, l1, l2, l3);
        winner = line_winner(cur_line);
        if (winner != "Nobody") {
            count_line_wins++;
            result = winner;
        }
    }

    if (count_line_wins > 1){
        std::cout << "Incorrect" << std::endl;
        return false;
    }

    int correctness_xo = check_correctness(l1) + check_correctness(l2) + check_correctness(l3);

    if (result == "Petya") {
        if (correctness_xo != -1) {
            std::cout << "Incorrect";
            return false;
        }
        else {
            std::cout << "Petya won" << std::endl;
            return false;
        }
    }
    else if (result == "Vasya") {
        if (correctness_xo != 0 and correctness_xo != -1) {
            std::cout << "Incorrect";
            return false;
        }
        else {
            std::cout << "Vasya won" << std::endl;
            return false;
        }
    }
    return true;
}

bool check_col(std::string l1, std::string l2, std::string l3) {
    std::string result;
    std::string winner;
    int count_col_wins = 0;

    for (int i = 0; i < 3; i++){
        if (l1[i] == l2[i] and l1[i] == l3[i]){
            if (l1[i] == 'X'){
                winner = "Petya";
                count_col_wins++;
            }
            else if (l1[i] == 'O'){
                winner = "Vasya";
                count_col_wins++;
            }
        }
    }

    if (count_col_wins > 1){
        std::cout << "Incorrect" << std::endl;
        return false;
    }

    int correctness_xo = check_correctness(l1) + check_correctness(l2) + check_correctness(l3);

    if (winner == "Petya") {
        if (correctness_xo != -1) {
            std::cout << "Incorrect";
            return false;
        }
        else {
            std::cout << "Petya won" << std::endl;
            return false;
        }
    }
    else if (winner == "Vasya") {
        if (correctness_xo != 0 and correctness_xo != -1) {
            std::cout << "Incorrect";
            return false;
        }
        else {
            std::cout << "Vasya won" << std::endl;
            return false;
        }
    }
    return true;
}

bool check_diag(std::string l1, std::string l2, std::string l3) {
    int correctness_xo = check_correctness(l1) + check_correctness(l2) + check_correctness(l3);
    if ((l1[0] == l2[1] and l2[1] == l3[2]) or (l1[2] == l2[1] and l2[1] == l3[0])){
        if (l2[1] == 'X'){
            if (correctness_xo != 1) {
                std::cout << "Incorrect";
            } else {
                std::cout << "Petya won" << std::endl;
            }
            return false;
        }
        else if (l2[1] == 'O'){
            if (correctness_xo != 0 and correctness_xo != -1) {
                std::cout << "Incorrect";
            } else {
                std::cout << "Vasya won" << std::endl;
            }
            return false;
        }
    }
    return true;
}

bool pre_check_field(std::string line1, std::string line2, std::string line3) {
    std::string field = line1 + line2 + line3;
    std::string alphabet = "XO.";
    if (field.length() != 9) return false;
    for (char i : field) {
        if (alphabet.find(i) == std::string::npos) {
            std::cout << "There are invalid characters on the field" << std::endl;
            return false;
        }
    }

    int count_xo_field = 0;
    for (char & i : field) {
        if (i == 'X') {
            count_xo_field++;
        } else if (i == 'O') {
            count_xo_field--;
        }
    }

    if (count_xo_field != 0 and count_xo_field != 1) {
        std::cout << "Incorrect" << std::endl;
    } else if (check_line(line1, line2, line3) and check_col(line1, line2, line3) and check_diag(line1, line2, line3)) {
        std::cout << "Nobody" << std::endl;
    }
    return true;
}

int main() {
    std::cout << "Analysis of the results of the game of tic-tac-toe" << std::endl;
    std::cout << std::endl;

    std::string line1, line2, line3;

    std::cout << "Enter the lines of the playing field: " << std::endl;
    std::cin >> line1;
    std::cin >> line2;
    std::cin >> line3;

    if (!(pre_check_field(line1, line2, line3))) std::cout << "Incorrect" << std::endl;
    return 0;
}