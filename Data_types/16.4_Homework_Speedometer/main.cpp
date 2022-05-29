#include <iostream>
#include <cstdio>
#include <iomanip>

int main() {
    std::cout << "Speedometer" << std::endl;
    std::cout << std::endl;

    const int max_speed = 150;
    const float epsilon = 0.01;
    char speed_str[10];
    float speed_value = 0;
    float delta_speed_value;

    do {
        std::cout << "Input delta speed: " << std::endl;
        std::cin >> delta_speed_value;

        speed_value += delta_speed_value;

        if (speed_value > max_speed) speed_value = 150;

        std::sprintf(speed_str, "%.1f", speed_value);
        std::cout << "Current speed: " << speed_str << " km/h" << std::endl;
        std::cout << std::endl;

    } while ((speed_value + epsilon >= 0) and (speed_value - epsilon >= 0));
    std::cout << "The car stopped!" << std::endl;
    return 0;
}
