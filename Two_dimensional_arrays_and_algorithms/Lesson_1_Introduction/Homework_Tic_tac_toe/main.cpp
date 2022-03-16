#include <iostream>

char check_win(char field[][3]) {
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] and field[i][1] == field[i][2] and field[i][0] != ' ') {
            return field[i][0];
        }
        if (field[0][i] == field[1][i] and field[1][i] == field[2][i]  and field[0][i] != ' ') {
            return field[0][i];
        }
    }
    return 'N';
}

void print_field(char field[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Tic-tac-toe" << std::endl;
    std::cout << std::endl;

    char field[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
    };
    int x, y;
    char symbol = 'X';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                std::cout << "Enter the coordinates of the move: (" << symbol << " makes a move)" << std::endl;
                std::cin >> x >> y;
            }
            while ((x < 0 or x > 2 or y < 0 or y > 2) or field[y][x] != ' ');
            field[y][x] = symbol;
            print_field(field);
            if (symbol == 'X') {
                symbol = 'O';
            } else {
                symbol = 'X';
            }
            char win = check_win(field);
            if (win != 'N') {
                std::cout << std::endl;
                std::cout << win << " won" << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
