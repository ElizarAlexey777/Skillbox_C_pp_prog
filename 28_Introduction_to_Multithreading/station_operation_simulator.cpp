#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

struct Train {
    const char name;
    uint64_t time_depature;
    std::thread track;
    static std::mutex cout_mutex;
    static bool platform_busy;
    static bool can_depart;

    Train(const char& n, uint64_t t) : name(n), time_depature(t) {}

    void track_info() {
        auto start_time = std::chrono::steady_clock::now();
        bool waiting_for_platform = false;
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            auto current_time = std::chrono::steady_clock::now();
            uint64_t elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
            if (elapsed_seconds >= time_depature) {
                std::unique_lock<std::mutex> lock(cout_mutex);
                if (!platform_busy) {
                    platform_busy = true;
                    std::cout << "Поезд " << name << " прибыл на вокзал";
                    if (elapsed_seconds - time_depature > 0) {
                        std::cout << " с опозданием на " << elapsed_seconds - time_depature << " c.";
                    }
                    std::cout << "\n";
                    std::cout << "Поезд " << name << " ожидает команды 'depart'.\n";

                    while (!can_depart) {
                        lock.unlock();
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        lock.lock();
                    }

                    std::cout << "Поезд " << name << " отбыл с вокзала.\n";
                    can_depart = false;
                    platform_busy = false;
                    break;
                } else if (!waiting_for_platform) {
                    std::cout << "Поезд " << name << " ожидает свободного перрона.\n";
                    waiting_for_platform = true;
                }
            }
        }
    }

    void start() {
        track = std::thread(&Train::track_info, this);
    }
};

std::mutex Train::cout_mutex;
bool Train::platform_busy = false;
bool Train::can_depart = false;

void depart_command() {
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "depart") {
            std::lock_guard<std::mutex> guard(Train::cout_mutex);
            Train::can_depart = true;
        }
    }
}

int main() {
    std::vector<Train> trains;
    const int num_trains = 3;
    const char names_trains[num_trains] = { 'A', 'B', 'C' };

    std::cout << "Введите время в пути до вокзала (в секундах) для " << num_trains << " поездов:\n";
    for (int i = 0; i < num_trains; ++i) {
        uint64_t time;
        std::cout << "Поезд " << names_trains[i] << ":\n";
        std::cout << "Время в пути до вокзала (в секундах): ";
        std::cin >> time;
        trains.emplace_back(names_trains[i], time);
    }

    for (auto& train : trains) {
        train.start();
    }

    std::thread command_thread(depart_command);

    for (auto& train : trains) {
        train.track.join();
    }

    command_thread.detach();

    return 0;
}
