#include <iostream>
#include <fstream>

int main() {
    std::cout << "PNG detector" << std::endl;
    std::cout << std::endl;

    std::string path_to_file;

    std::cout << "Enter the path to the .png: " << std::endl;
    std::getline(std::cin, path_to_file);

    if (path_to_file.substr(path_to_file.length() - 4, path_to_file.length() - 1) != "png") {
        std::ifstream png;
        png.open(path_to_file, std::ios::binary);

        char title[4];
        png.read(title, sizeof(title));

        if ((int) title[0] == -119 and title[1] == 'P' and title[2] == 'N' and title[3] == 'G') {
            std::cout << "The file is .png format" << std::endl;
        } else {
            std::cout << "File format is not .png" << std::endl;
        }

        png.close();
    } else {
        std::cout << "File format is not .png" << std::endl;
    }
    return 0;
}
