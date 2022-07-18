#include <iostream>

#define RAILWAY_CARRIAGES_COUNT 10

#define INPUT(num) for (int i = 1; i <= num; i++) {\
        int count_passengers;\
        std::cout << "Enter the number of passengers in the railway carriage #" << i << ": " << std::endl;\
        std::cin >> count_passengers;\
        if (overflow(count_passengers)) {\
            std::cout << "Railway carriage #" << i << " is overflow." << std::endl;\
        }\
        if (empty(count_passengers)) {\
            std::cout << "Railway carriage #" << i << " is empty." << std::endl;\
        }\
        railway_carriages[i] = count_passengers;\
        }

#define PASS_COUNT int sum = 0;\
        for (int i = 1; i <= RAILWAY_CARRIAGES_COUNT; i++) {\
        sum += railway_carriages[i];\
        }\
        std::cout << "Total number of passengers in all carriages: " << sum << std::endl;

bool overflow(int num) {
    if (num > 20) {
        return true;
    }
    return false;
}

bool empty(int num) {
    if (num <= 0) {
        return true;
    }
    return false;
}

int main() {
    std::cout << "Train occupancy analysis" << std::endl << std::endl;

    int railway_carriages[RAILWAY_CARRIAGES_COUNT];

    INPUT(RAILWAY_CARRIAGES_COUNT);
    PASS_COUNT;
}