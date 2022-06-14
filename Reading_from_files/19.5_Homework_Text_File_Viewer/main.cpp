#include <iostream>
#include <fstream>

int main() {
    std::cout << "Text File Viewer" << std::endl;
    std::cout << std::endl;

    std::string path_to_file;

    std::getline(std::cin, path_to_file);

    std::ifstream file;
    file.open(path_to_file);

    if (file.is_open()) {
        while(!file.eof()) {
            char buffer[20];
            file.read(buffer, sizeof(buffer));
            buffer[file.gcount()] = '\0';
            std::cout << buffer;
        }
    } else {
        std::cout << "Invalid file path or such file does not exist!" << std::endl;
    }

    file.close();

    return 0;
}
