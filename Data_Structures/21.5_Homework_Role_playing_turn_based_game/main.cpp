#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

struct coordinate {
    int x;
    int y;
};

struct characters {
    std::string name;
    bool enemy;
    int health;
    int armor;
    int damage;
    coordinate point;
};

bool overlap(int x, int y, std::vector<characters> &person, int index, bool isEnemy) {
    for (int i = index-1; i >= 0; --i) {
        if(person[i].point.x == x && person[i].point.y == y) return true;
    }
    if (isEnemy) {
        person[index].point.x = x;
        person[index].point.y = y;
    }
    return false;
}

void initEnemy(std::vector<characters> &enemy) {
    for(int i = 0; i < enemy.size(); ++i) {
        enemy[i].name = "Enemy #" + std::to_string(i+1);
        enemy[i].enemy = true;
        enemy[i].health = (rand() % 101) + 50;
        enemy[i].armor = rand() % 51;
        enemy[i].damage = (rand() % 16) + 15;
        while(overlap(rand() % 20, rand() % 20, enemy, i, enemy[i].enemy)){}
    }
}

void viewEnemy(std::vector<characters> &enemy)
{
    for (int i = 0; i < enemy.size(); ++i) {
        std::cout << enemy[i].name << std::endl;
        std::cout << enemy[i].enemy << std::endl;
        std::cout << enemy[i].health << std::endl;
        std::cout << enemy[i].armor << std::endl;
        std::cout << enemy[i].damage << std::endl;
        std::cout << enemy[i].point.x << std::endl;
        std::cout << enemy[i].point.y << std::endl;
        std::cout << std::endl << "----------------------------" << std::endl;
    }
}
void initPlayer(characters &player, std::vector<characters> &enemy) {
    std::cout << "Input characteristics of your hero:" << std::endl;
    std::cout << "Input name of your hero:" << std::endl;
    std::cin >> player.name;
    player.enemy = false;
    do {
        std::cout << "Input health of your hero: (50 - 150)" << std::endl;
        std::cin >> player.health;
    } while(player.health < 50 || player.health > 150);
    do {
        std::cout << "Input armor of your hero: (0 - 50)" << std::endl;
        std::cin >> player.armor;
    } while(player.armor < 0 || player.armor > 50);
    do {
        std::cout << "Input damage of your hero: (15 - 30)" << std::endl;
        std::cin >> player.damage;
    } while(player.damage < 15 || player.damage > 30);

    std::cout << std::endl << "Name - " << player.name << std::endl;
    std::cout << "Health - " << player.health << std::endl;
    std::cout << "Armor - " << player.armor << std::endl;
    std::cout << "Damage - " << player.damage << std::endl;

    int x, y;
    do {
        std::cout << "Your coordinates on the field (0 - 19):" << std::endl;
        std::cin >> x >> y;
    } while(x < 0 or x > 19 or y < 0 or y > 19 or overlap(x, y, enemy, enemy.size(), player.enemy));
    player.point.x = x;
    player.point.y = y;
}

void displayField(characters &player, std::vector<characters> &enemy) {
    const int fieldSize = 20;
    char gameMap[fieldSize][fieldSize];

    for (int i = 0; i < fieldSize; ++i) {
        for (int j = 0; j < fieldSize; ++j) {
            gameMap[i][j] = '.';
        }
    }
    for (int i = 0; i < enemy.size(); ++i) {
        if (enemy[i].health > 0) {
            gameMap[enemy[i].point.x][enemy[i].point.y] = 'E';
        }
    }

    if (player.health > 0) gameMap[player.point.x][player.point.y] = 'P';

    for (int i = 0; i < fieldSize; ++i) {
        for(int j = 0; j < fieldSize; ++j) {
            std::cout << gameMap[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void attacks(coordinate &point, characters &attack, characters &player, std::vector<characters> &enemy) {
    if (!attack.enemy) {
        attack.point = point;
        for (int i = 0; i < enemy.size(); ++i) {
            if (enemy[i].health != 0 && attack.point.x == enemy[i].point.x && attack.point.y == enemy[i].point.y) {
                enemy[i].armor -= attack.damage;
                if (enemy[i].armor < 0) {
                    enemy[i].health += enemy[i].armor;
                    enemy[i].armor = 0;
                }
                if (enemy[i].health < 0) enemy[i].health = 0;
            }
        }
    } else {
        if (point.x == player.point.x && point.y == player.point.y) {
            attack.point = point;
            player.armor -= attack.damage;
            if (player.armor < 0) {
                player.health += player.armor;
                player.armor = 0;
            }
            if (player.health < 0) player.health = 0;
        } else {
            for (int i = 0; i < enemy.size(); ++i) {
                if (enemy[i].health <= 0 || (attack.name != enemy[i].name && (point.x != enemy[i].point.x || point.y != enemy[i].point.y))) {
                    attack.point = point;
                }
            }
        }
    }
}

void save(characters &player, std::vector<characters> &enemy) {
    std::ofstream file("save.bin", std::ios::binary); // путь к файлу "save.bin"
    if (file.is_open()) {
        int len = player.name.length();
        file.write((char*)&len, sizeof(len));
        file.write(player.name.c_str(), len);
        file.write((char*)&player.enemy, sizeof(player.enemy));
        file.write((char*)&player.health, sizeof(player.health));
        file.write((char*)&player.armor, sizeof(player.armor));
        file.write((char*)&player.damage, sizeof(player.damage));
        file.write((char*)&player.point.x, sizeof(player.point.x));
        file.write((char*)&player.point.y, sizeof(player.point.y));

        for (int i = 0; i < enemy.size(); ++i) {
            int len = enemy[i].name.length();
            file.write((char*)&len, sizeof(len));
            file.write(enemy[i].name.c_str(), len);
            file.write((char*)&enemy[i].enemy, sizeof(enemy[i].enemy));
            file.write((char*)&enemy[i].health, sizeof(enemy[i].health));
            file.write((char*)&enemy[i].armor, sizeof(enemy[i].armor));
            file.write((char*)&enemy[i].damage, sizeof(enemy[i].damage));
            file.write((char*)&enemy[i].point.x, sizeof(enemy[i].point.x));
            file.write((char*)&enemy[i].point.y, sizeof(enemy[i].point.y));
        }
        std::cout << "The game has been successfully saved!" << std::endl;
        file.close();
    } else {
        std::cout << "File not found..." << std::endl;
    }
}

void load(characters &player, std::vector<characters> &enemy) {
    std::ifstream file("save.bin", std::ios::binary); // путь к файлу "save.bin"
    if (file.is_open()) {
        int len;
        file.read((char*)&len, sizeof(len));
        player.name.resize(len);
        file.read((char*)player.name.c_str(), len);
        file.read((char*)&player.enemy, sizeof(player.enemy));
        file.read((char*)&player.health, sizeof(player.health));
        file.read((char*)&player.armor, sizeof(player.armor));
        file.read((char*)&player.damage, sizeof(player.damage));
        file.read((char*)&player.point.x, sizeof(player.point.x));
        file.read((char*)&player.point.y, sizeof(player.point.y));

        for (int i = 0; i < enemy.size(); ++i) {
            int len;
            file.read((char*)&len, sizeof(len));
            enemy[i].name.resize(len);
            file.read((char*)enemy[i].name.c_str(), len);
            file.read((char*)&enemy[i].enemy, sizeof(enemy[i].enemy));
            file.read((char*)&enemy[i].health, sizeof(enemy[i].health));
            file.read((char*)&enemy[i].armor, sizeof(enemy[i].armor));
            file.read((char*)&enemy[i].damage, sizeof(enemy[i].damage));
            file.read((char*)&enemy[i].point.x, sizeof(enemy[i].point.x));
            file.read((char*)&enemy[i].point.y, sizeof(enemy[i].point.y));
        }
        std::cout << "The last game save was loaded successfully!" << std::endl;
        file.close();
        displayField(player, enemy);
    } else {
        std::cout << "File not found..." << std::endl;
    }
}

void movingPlayers(characters &player, std::vector<characters> &enemy) {
    std::string command;
    do {
        std::cout << std::endl << "Input command: " << std::endl;
        std::cout << "save - to save the game" << std::endl;
        std::cout << "load - to load the game" << std::endl;
        std::cout << "l - to move left" << std::endl;
        std::cout << "r - to move right" << std::endl;
        std::cout << "u - to move up" << std::endl;
        std::cout << "d - to move down" << std::endl;
        std::cin >> command;
    } while(command != "l" and command != "r" and command != "u" and command != "d" and command != "save" and command != "load");

    coordinate point;

    if (command == "l") {
        if (player.point.y > 0) {
            point = player.point;
            --point.y;
            attacks(point, player, player, enemy);
        }
    } else if (command == "r") {
        if (player.point.y < 19) {
            point = player.point;
            ++point.y;
            attacks(point, player, player, enemy);
        }
    } else if (command == "u") {
        if (player.point.x > 0) {
            point = player.point;
            --point.x;
            attacks(point, player, player, enemy);
        }
    } else if (command == "d") {
        if (player.point.x < 19) {
            point = player.point;
            ++point.x;
            attacks(point, player, player, enemy);
        }
    } else if (command == "save") {
        save(player, enemy);
    } else if (command == "load") {
        load(player, enemy);
    }

    for (int i = 0; i < enemy.size(); ++i) {
        int step = rand() % 4;
        switch (step) {
            case 0:
                if(enemy[i].point.y > 0 && enemy[i].health != 0)
                {
                    point = enemy[i].point;
                    --point.y;
                    attacks(point, enemy[i], player, enemy);
                }
                break;
            case 1:
                if(enemy[i].point.y < 39 && enemy[i].health != 0)
                {
                    point = enemy[i].point;
                    ++point.y;
                    attacks(point, enemy[i], player, enemy);
                }
                break;
            case 2:
                if(enemy[i].point.x > 0 && enemy[i].health != 0)
                {
                    point = enemy[i].point;
                    --point.x;
                    attacks(point, enemy[i], player, enemy);
                }
                break;
            case 3:
                if(enemy[i].point.x < 39 && enemy[i].health != 0)
                {
                    point = enemy[i].point;
                    ++point.x;
                    attacks(point, enemy[i], player, enemy);
                }
                break;
        }
    }
}

int statusCheck(characters &player, std::vector<characters> &enemy) {
    std::cout << "Statistics: "<< std::endl << "Player" << std::endl;
    std::cout << "Health: " << player.health << std::endl;
    std::cout << "Armor: " << player.armor << std::endl;
    std::cout << std::endl;
    int sum_enemy = 0;
    for (int i = 0; i < enemy.size(); ++i) {
        std::cout << "Enemy #" << i + 1 << std::endl;
        std::cout << "Live: " << enemy[i].health << std::endl;
        std::cout << "Armor: " << enemy[i].armor << std::endl;
        sum_enemy += enemy[i].health;
        std::cout << std::endl;
    }
    if (sum_enemy <= 0) return -1;
    if (player.health <= 0) return 1;
    return 0;
}

int main() {
    std::cout << "RPG turn-based game" << std::endl << std::endl;
    srand(time(0));
    const int numEnemy = 5;
    std::vector<characters> enemy(numEnemy);
    characters myPlayer;

    initEnemy(enemy);
    initPlayer(myPlayer, enemy);
    displayField(myPlayer, enemy);
    int status = statusCheck(myPlayer, enemy);
    while(!status) {
        movingPlayers(myPlayer, enemy);
        displayField(myPlayer, enemy);
        status = statusCheck(myPlayer, enemy);
    }
    if (status == 1) std::cout << std::endl << "You lose!" << std::endl;
    else if (status == -1) std::cout<< std::endl << "You won!" << std::endl;
}