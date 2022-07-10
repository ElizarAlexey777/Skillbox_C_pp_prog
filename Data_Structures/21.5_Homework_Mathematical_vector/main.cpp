#include <iostream>
#include <string>
#include <cmath>

struct vec {
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;
};

void add() {
    float coords;
    vec vector;
    std::cout << "Input coords of the first vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x1 = coords;
    std::cin >> coords;
    vector.y1 = coords;

    std::cout << "Input coords of the second vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x2 = coords;
    std::cin >> coords;
    vector.y2 = coords;

    std::cout << "The coordinates of the resulting vector: X = " << vector.x1 + vector.x2 << ", Y = " << vector.y1 + vector.y2 << std::endl;
}

void subtract() {
    float coords;
    vec vector;
    std::cout << "Input coords of the first vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x1 = coords;
    std::cin >> coords;
    vector.y1 = coords;

    std::cout << "Input coords of the second vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x2 = coords;
    std::cin >> coords;
    vector.y2 = coords;

    std::cout << "The coordinates of the resulting vector: X = " << vector.x1 - vector.x2 << ", Y = " << vector.y1 - vector.y2 << std::endl;
}

void length() {
    float coords;
    vec vector;
    std::cout << "Input coords of the vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x1 = coords;
    std::cin >> coords;
    vector.y1 = coords;

    std::cout << "Vector length: " << std::sqrt(std::abs(std::pow(vector.x1, 2) + std::pow(vector.y1, 2))) << std::endl;
}

void scale() {
    float coords;
    vec vector;
    std::cout << "Input coords of the vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x1 = coords;
    std::cin >> coords;
    vector.y1 = coords;

    std::cout << "Input scale:" << std::endl;
    float scale;
    std::cin >> scale;

    std::cout << "The coordinates of the resulting vector: X = " << vector.x1 * scale << ", Y = " << vector.y1 * scale << std::endl;
}

void normalize() {
    float coords;
    vec vector;
    std::cout << "Input coords of the vector: (x:y)" << std::endl;
    std::cin >> coords;
    vector.x1 = coords;
    std::cin >> coords;
    vector.y1 = coords;

    double normal = std::sqrt(std::abs(std::pow(vector.x1, 2) + std::pow(vector.y1, 2)));

    std::cout << "The coordinates of the resulting vector: X = " << vector.x1 / normal << ", Y = " << vector.y1 / normal << std::endl;
}

int main() {
    std::cout << "Mathematical vector" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the command: " << std::endl;
    std::cout << R"("add" / "subtract" / "scale" / "length" / "normalize")" << std::endl;

    std::string operation;
    std::cin >> operation;

    if (operation == "add") {
        add();
    } else if (operation == "subtract"){
        subtract();
    } else if (operation == "scale"){
        scale();
    } else if (operation == "length"){
        length();
    } else if (operation == "normalize"){
        normalize();
    } else std::cout << "Unknown operation..." << std::endl;
}