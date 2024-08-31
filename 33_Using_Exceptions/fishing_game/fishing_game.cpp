#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class GameObject {
public:
    virtual ~GameObject() = default;
};

class Fish : public GameObject {};

class Boot : public GameObject {};

class FishCaughtException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Поздравляем! Вы поймали рыбу!";
    }
};

class BootCaughtException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Неудача! Вы поймали сапог!";
    }
};

void initField(std::vector<GameObject*>& field) {
    int fish_pos = std::rand() % 9;
    field[fish_pos] = new Fish();

    for (int i = 0; i < 3; ++i) {
        int boot_pos;
        do {
            boot_pos = std::rand() % 9;
        } while (field[boot_pos] != nullptr);
        field[boot_pos] = new Boot();
    }
}

void playGame(std::vector<GameObject*>& field) {
    int attempts = 0;

    while (true) {
        std::cout << "Введите номер сектора (0-8): ";
        int sector;
        std::cin >> sector;

        if (sector < 0 || sector >= 9) {
            std::cout << "Неверный ввод. Пожалуйста, введите число от 0 до 8" << std::endl;
            continue;
        }

        ++attempts;

        if (field[sector] != nullptr) {
            if (dynamic_cast<Fish*>(field[sector])) {
                throw FishCaughtException();
            } else if (dynamic_cast<Boot*>(field[sector])) {
                throw BootCaughtException();
            }
        } else {
            std::cout << "Вы промахнулись. Попробуйте еще раз" << std::endl;
        }
    }
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<GameObject*> field(9, nullptr);
    initField(field);

    try {
        playGame(field);
    } catch (const FishCaughtException& e) {
        std::cout << e.what() << std::endl;
    } catch (const BootCaughtException& e) {
        std::cout << e.what() << std::endl;
    }

    for (auto obj : field) {
        delete obj;
    }

    return 0;
}
