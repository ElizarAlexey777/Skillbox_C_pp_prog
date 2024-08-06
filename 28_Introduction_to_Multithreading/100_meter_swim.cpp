#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include <mutex>
#include <algorithm>

struct Swimmer {
    std::string name;
    double speed; // Скорость в м/с
    double distance; // Пройденное расстояние в метрах
    std::thread swim;
    static std::mutex cout_mutex;

    Swimmer(const std::string& n, double s) : name(n), speed(s), distance(0) {}

    void swim_routine() {
        while (distance < 100) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            distance += speed;
            if (distance >= 100) {
                distance = 100;

                {
                    std::lock_guard<std::mutex> lock(cout_mutex);
                    std::cout << name << " проплыл " << distance << " метров и закончил заплыв.\n";
                }
                break;
            }

            {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cout << name << " проплыл " << distance << " метров.\n";
            }
        }
    }

    void start() {
        swim = std::thread(&Swimmer::swim_routine, this);
    }
};

std::mutex Swimmer::cout_mutex;

int main() {
    std::vector<Swimmer> swimmers;
    const int num_swimmers = 6;

    std::cout << "Введите имена и скорости (в м/с) для " << num_swimmers << " пловцов:\n";
    for (int i = 0; i < num_swimmers; ++i) {
        std::string name;
        double speed;
        std::cout << "Пловец " << i + 1 << ":\n";
        std::cout << "Имя: ";
        std::cin >> name;
        std::cout << "Скорость: ";
        std::cin >> speed;
        swimmers.emplace_back(name, speed);
    }

    for (auto& swimmer : swimmers) {
        swimmer.start();
    }

    for (auto& swimmer : swimmers) {
        swimmer.swim.join();
    }

    std::sort(swimmers.begin(), swimmers.end(), [](const Swimmer& a, const Swimmer& b) {
        return a.distance / a.speed < b.distance / b.speed;
    });

    std::cout << "\nИтоговые результаты:\n";
    for (const auto& swimmer : swimmers) {
        std::cout << swimmer.name << " завершил с результатом " << swimmer.distance / swimmer.speed << " секунд.\n";
    }

    return 0;
}
