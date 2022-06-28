#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Game \"Fishing\"" << std::endl;
    std::cout << std::endl;

    std::string fish_type;

    std::cout << "Enter the name of the type of fish you want to catch:" << std::endl;
    std::cin >> fish_type;

    std::ifstream river;
    river.open("#путь_к_файлу_\"river.txt\"");
//    river.open(R"(C:\Users\User\Desktop\Elizarov_Alexey\C++\Skillbox_C_pp_prog\Writing_to_files\20.5_Homework_game_Fishing\river.txt)");

    std::ofstream basket;
    basket.open("#путь_к_файлу_\"basket.txt\"");
//    basket.open(R"(C:\Users\User\Desktop\Elizarov_Alexey\C++\Skillbox_C_pp_prog\Writing_to_files\20.5_Homework_game_Fishing\basket.txt)", std::ios::app);

    if (river.is_open() and basket.is_open()) {

        int count_fish = 0;

        std::cout << std::endl;
        std::cout << "Fishing started!" << std::endl;

        while (!river.eof()) {
            std::string river_fish;
            river >> river_fish;
            if (fish_type == river_fish) {
                count_fish++;
                std::cout << "Pecking! Pull out! Yes, the " << count_fish << " " << fish_type << " during fishing" << std::endl;
                basket << fish_type << std::endl;
            }
        }

        std::cout << std::endl;
        if (count_fish > 0) {
            std::cout << "Fishing is over! All " << fish_type << "(s) caught" << std::endl;
            std::cout << "In total, " << count_fish << " " << fish_type << "(s) were caught" << std::endl;
        } else {
            std::cout << "Fishing is over! Unfortunately, we didn't get anything..." << std::endl;
        }
    } else {
        std::cout << "Wrong file path! Try again..." << std::endl;
    }

    river.close();
    basket.close();
    return 0;
}
