#include <iostream>
#include <fstream>
#include <ctime>

bool check_entered_data(int x, int y) {
    return x > 0 and y > 0;
}

int main() {
    std::cout << "Drawing random pictures" << std::endl;
    std::cout << std::endl;

    int x_width, y_height;

    std::cout << "Enter the width and height of the picture (in pixels): (width height)" << std::endl;
    std::cin >> x_width >> y_height;

    while (!check_entered_data(x_width, y_height)) {
        std::cout << "Wrong data values!!! Enter positive numbers:" << std::endl;
        std::cin >> x_width >> y_height;
    }

    std::ofstream pic;
    pic.open("#путь_к_файлу_\"pic.txt\"");
//    pic.open(R"(C:\Users\User\Desktop\Elizarov_Alexey\C++\Skillbox_C_pp_prog\Writing_to_files\20.5_Homework_Drawing_random_pictures\pic.txt)");

    std::srand(std::time(nullptr));

    for (int y = 0; y < y_height; y++) {
        for (int x = 0; x < x_width; x++) {
            pic << std::rand() % 2;
        }
        pic << std::endl;
    }

    pic.close();

    std::cout << "The picture has been successfully saved to a file \"pic.txt\"" << std::endl;
    return 0;
}
