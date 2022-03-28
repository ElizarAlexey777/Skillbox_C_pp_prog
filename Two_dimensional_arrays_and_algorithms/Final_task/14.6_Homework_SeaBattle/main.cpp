#include <iostream>
#include <vector>

void pr_field(std::vector<std::vector<char>> field, int num_player) {
    std::cout << "Player " << num_player << " field: " << std::endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << ' ';
        } std::cout << std::endl;
    }
}

bool position_check(std::vector<std::vector<char>> field, int coord_x1, int coord_x2, int coord_y1, int coord_y2, char designation) {
    if (!((coord_x1 >= 0 and coord_x1 < 10) and (coord_x2 >= 0 and coord_x2 < 10) and (coord_y1 >= 0 and coord_y1 < 10) and (coord_y2 >= 0 and coord_y2 < 10))) {
        std::cout << "The ship goes out of bounds. Try again!" << std::endl;
        return false;
    }
    if (coord_x1 != coord_x2 and coord_y1 != coord_y2) {
        std::cout << "Ship can be positioned either horizontally or vertically. Try again!" << std::endl;
        return false;
    }
    char position = coord_x1 == coord_x2 ? 'h' : 'v';
    int coord_1, coord_2;
    if (position == 'h') {
        int tmp = std::max(coord_y1, coord_y2);
        coord_1 = std::min(coord_y1, coord_y2);
        coord_2 = tmp;
    } else {
        int tmp = std::max(coord_x1, coord_x2);
        coord_1 = std::min(coord_x1, coord_x2);
        coord_2 = tmp;
    }
    if ((coord_2 - coord_1 != 1 and designation == '%') or (coord_2 - coord_1 != 2 and designation == '&')
    or (coord_2 - coord_1 != 3 and designation == '@')) {
        std::cout << "The number of decks of the ship is incorrect, correct the coordinates. Try again!" << std::endl;
        return false;
    }
    for (int i = coord_1; i <= coord_2; i++) {
        if ((field[i][coord_x1] != '.' and position == 'h') or (field[coord_y1][i] != '.' and position == 'v')) {
            std::cout << "This cell is already occupied by another ship(s). Try again!" << std::endl;
            return false;
        }
    }
    return true;
}

std::vector<std::vector<char>> position_ship(std::vector<std::vector<char>> field, int coord_x1, int coord_x2, int coord_y1, int coord_y2, char designation) {
    char position = coord_x1 == coord_x2 ? 'h' : 'v';
    int coord_1, coord_2;
    if (position == 'h') {
        int tmp = std::max(coord_y1, coord_y2);
        coord_1 = std::min(coord_y1, coord_y2);
        coord_2 = tmp;
    } else {
        int tmp = std::max(coord_x1, coord_x2);
        coord_1 = std::min(coord_x1, coord_x2);
        coord_2 = tmp;
    }
    for (int i = coord_1; i <= coord_2; i++) {
        if (position == 'h') {
            field[i][coord_x1] = designation;
        } else {
            field[coord_y1][i] = designation;
        }
    }
    return field;
}

std::vector<std::vector<char>> arrangement_of_ships(std::vector<std::vector<char>> field, int num_player) {
    for (int x = 1; x <= 4; x++) {
        int coord_x, coord_y;
        bool flag;
        std::cout << "Player " << num_player << ", enter the coordinates of the " << x << " single-deck ship: (x1 y1)" << std::endl;
        do {
            flag = true;
            std::cin >> coord_x >> coord_y;
            if (!((coord_x >= 0 and coord_x < 10) and (coord_y >= 0 and coord_y < 10))) {
                std::cout << "The ship goes out of bounds. Try again!" << std::endl;
                flag = false;
                continue;
            }
            if (field[coord_x][coord_y] == '*') std::cout << "This cell is already occupied by another single-deck ship. Try again!" << std::endl;
        } while (!flag);
        field[coord_x][coord_y] = '*';
        pr_field(field, num_player);
    }
    for (int x = 1; x <= 3; x++) {
        int coord_x1, coord_y1, coord_x2, coord_y2;
        bool flag;
        std::cout << "Player " << num_player << ", enter the coordinates of the " << x << " double-deck ship: (x1 y1 enter x2 y2)" << std::endl;
        do {
            std::cin >> coord_x1 >> coord_y1;
            std::cin >> coord_x2 >> coord_y2;
            flag = position_check(field, coord_x1, coord_x2, coord_y1, coord_y2, '%');
        } while (!flag);
        field = position_ship(field, coord_x1, coord_x2, coord_y1, coord_y2, '%');
        pr_field(field, num_player);
    }
    for (int x = 1; x <= 2; x++) {
        int coord_x1, coord_y1, coord_x2, coord_y2;
        bool flag;
        std::cout << "Player " << num_player << ", enter the coordinates of the " << x << " three-deck ship: (x1 y1 enter x2 y2)" << std::endl;
        do {
            std::cin >> coord_x1 >> coord_y1;
            std::cin >> coord_x2 >> coord_y2;
            flag = position_check(field, coord_x1, coord_x2, coord_y1, coord_y2,'&');
        } while (!flag);
        field = position_ship(field, coord_x1, coord_x2, coord_y1, coord_y2, '&');
        pr_field(field, num_player);
    }
    int coord_x1, coord_y1, coord_x2, coord_y2;
    bool flag;
    std::cout << "Player " << num_player << ", enter the coordinates of the " << 1 << " four-deck ship: (x1 y1 enter x2 y2)" << std::endl;
    do {
        std::cin >> coord_x1 >> coord_y1;
        std::cin >> coord_x2 >> coord_y2;
        flag = position_check(field, coord_x1, coord_x2, coord_y1, coord_y2, '@');
    } while (!flag);
    field = position_ship(field, coord_x1, coord_x2, coord_y1, coord_y2, '@');
    pr_field(field, num_player);
    return field;
}

bool all_ships_destroyed(std::vector<std::vector<char>> field) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j] != '*' and field[i][j] != 'x' and field[i][j] != 'o') {
                return true;
            }
        }
    }
    return false;
}

std::vector<std::vector<char>> attack(std::vector<std::vector<char>> field, int num_player) {
    std::cout << "Player " << num_player << " is attacking" << std::endl;

    int shot_x, shot_y;

    std::cout << "Player " << num_player << ", enter shot coordinates: (x y)" << std::endl;
    std::cin >> shot_y >> shot_x;

    if (field[shot_x][shot_y] != '.' and field[shot_x][shot_y] != 'x' and field[shot_x][shot_y] != 'o') {
        std::cout << "Player " << num_player << " hit the ship successfully" << std::endl;
        field[shot_x][shot_y] = 'x';
    } else {
        std::cout << "Player " << num_player << " shot wide" << std::endl;
        field[shot_x][shot_y] = 'o';
    }
    std::cout << std::endl;
    return field;
}

void winner (bool player_1_lost, bool player_2_lost) {
    std::cout << std::endl;
    std::cout << "Game over! ";
    if (player_1_lost and player_2_lost) {
        std::cout << "Draw!" << std::endl;
    } else if (player_1_lost) {
        std::cout << "Player 2 won!" << std::endl;
    } else {
        std::cout << "Player 1 won!" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Sea Battle" << std::endl;
    std::cout << std::endl;

    std::vector<std::vector<char>> field_arrangement_1 = {
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            };

    std::vector<std::vector<char>> field_arrangement_2 = {
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };

    std::cout << "Arrangement of ships" << std::endl;
    std::cout << "* - single-deck ship" << std::endl;
    std::cout << "% - double-deck ship" << std::endl;
    std::cout << "& - three-deck ship" << std::endl;
    std::cout << "@ - four-deck ship" << std::endl;
    field_arrangement_1 = arrangement_of_ships(field_arrangement_1, 1);
    field_arrangement_2 = arrangement_of_ships(field_arrangement_2, 2);
    std::cout << std::endl;
    std::cout << "The beginning of the ship battle" << std::endl;

    bool win;

    do {
        field_arrangement_2 = attack(field_arrangement_2, 1);
        field_arrangement_1 = attack(field_arrangement_1, 2);
        win = all_ships_destroyed(field_arrangement_1) and all_ships_destroyed(field_arrangement_2);
        pr_field(field_arrangement_1, 1);
        pr_field(field_arrangement_2, 2);
    } while (win);
    winner(all_ships_destroyed(field_arrangement_1), all_ships_destroyed(field_arrangement_2));
    std::cout << "The final alignment of forces at sea: " << std::endl;
    pr_field(field_arrangement_1, 1);
    pr_field(field_arrangement_2, 2);
    return 0;
}
