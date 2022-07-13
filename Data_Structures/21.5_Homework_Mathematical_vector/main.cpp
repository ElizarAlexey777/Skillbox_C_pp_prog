#include <iostream>
#include <string>
#include <cmath>

struct vec {
    double x;
    double y;
};


vec add(vec vec1, vec vec2) {
    vec result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;
    return result;
}

vec substract(vec vec1, vec vec2) {
    vec result;
    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;
    return result;
}

vec scale(vec vector, float scale_num) {
    vec result;
    result.x = vector.x * scale_num;
    result.y = vector.y * scale_num;
    return result;
}

float length(vec vector) {
    return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

vec normalize(vec vector) {
    vec result;
    float scale = length(vector);
    result.x = vector.x / scale;
    result.y = vector.y / scale;
    return result;
}

int main() {
    std::cout << "Mathematical vector" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the command: " << std::endl;
    std::cout << R"("add" / "subtract" / "scale" / "length" / "normalize")" << std::endl;

    std::string operation;
    std::cin >> operation;

    if (operation == "add") {
        vec vec1, vec2, result;
        std::cout << "Input coords of the first vector: (x:y)" << std::endl;
        std::cin >> vec1.x >> vec1.y;

        std::cout << "Input coords of the second vector: (x:y)" << std::endl;
        std::cin >> vec2.x >> vec2.y;

        result = add(vec1, vec2);

        std::cout << "The coordinates of the resulting vector: X = " << result.x << ", Y = " << result.y << std::endl;

    } else if (operation == "subtract") {
        vec vec1, vec2, result;
        std::cout << "Input coords of the first vector: (x:y)" << std::endl;
        std::cin >> vec1.x >> vec1.y;

        std::cout << "Input coords of the second vector: (x:y)" << std::endl;
        std::cin >> vec2.x >> vec2.y;

        result = substract(vec1, vec2);

        std::cout << "The coordinates of the resulting vector: X = " << result.x << ", Y = " << result.y << std::endl;

    } else if (operation == "scale") {
        vec vector, result;
        float scale_num;

        std::cout << "Input coords of the vector: (x:y)" << std::endl;
        std::cin >> vector.x >> vector.y;

        std::cout << "Input scale:" << std::endl;
        std::cin >> scale_num;

        result = scale(vector, scale_num);

        std::cout << "The coordinates of the resulting vector: X = " << result.x << ", Y = " << result.y << std::endl;

    } else if (operation == "length") {
        vec vector;

        std::cout << "Input coords of the vector: (x:y)" << std::endl;
        std::cin >> vector.x >> vector.y;

        std::cout << "Vector length: " << length(vector) << std::endl;

    } else if (operation == "normalize") {
        vec vector, result;

        std::cout << "Input coords of the vector: (x:y)" << std::endl;
        std::cin >> vector.x >> vector.y;

        result = normalize(vector);

        std::cout << "The coordinates of the resulting vector: X = " << result.x << ", Y = " << result.y << std::endl;

    } else std::cout << "Unknown operation..." << std::endl;
}