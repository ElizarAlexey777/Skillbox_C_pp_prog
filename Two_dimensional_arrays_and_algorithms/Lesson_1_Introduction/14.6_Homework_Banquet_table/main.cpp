#include <iostream>

int main() {
    std::cout << "Banquet_table" << std::endl;
    std::cout << std::endl;

    std::string seats[2][12] = {
            {"Vip", "Regular","Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular"},
            {"Vip", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular", "Regular"}
    };

    int cutlery[2][12] = {
            {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
            {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
    };

    int plates[2][12] = {
            {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
            {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };

    int chairs[2][12] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    std::cout << "After the arrival of the woman with the child to the first row and 5th place..." << std::endl;
    seats[0][4] = "Regular with children";
    chairs[0][4] += 1;
    std::cout << "Change in seats: " << std::endl;
    for (auto & seat : seats) {
        for (int j = 0; j < 10; j++) {
            std::cout << seat[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Additional chair: " << std::endl;
    for (auto & chair : chairs) {
        for (int j = 0; j < 10; j++) {
            std::cout << chair[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Stealing a spoon from 3rd seat in the second row..." << std::endl;
    cutlery[1][2] -= 1;
    std::cout << "Change in the number of cutlery: " << std::endl;
    for (auto & cut : cutlery) {
        for (int j = 0; j < 10; j++) {
            std::cout << cut[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "A VIP shared a dessert spoon with a visitor from the 3rd place in the second row..." << std::endl;
    cutlery[0][0] -= 1;
    cutlery[1][2] += 1;
    std::cout << "Change in the number of cutlery: " << std::endl;
    for (auto & cut : cutlery) {
        for (int j = 0; j < 10; j++) {
            std::cout << cut[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The waiter took the dessert plate from the VIP person..." << std::endl;
    plates[0][0] -= 1;
    std::cout << "Change in the number of plates: " << std::endl;
    for (auto & plate : plates) {
        for (int j = 0; j < 10; j++) {
            std::cout << plate[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Summary of the last dinner: " << std::endl;
    std::cout << "Seats: " << std::endl;
    for (auto & seat : seats) {
        for (int j = 0; j < 10; j++) {
            std::cout << seat[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Cutlery: " << std::endl;
    for (auto & cut : cutlery) {
        for (int j = 0; j < 10; j++) {
            std::cout << cut[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Plates: " << std::endl;
    for (auto & plate : plates) {
        for (int j = 0; j < 10; j++) {
            std::cout << plate[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Chairs: " << std::endl;
    for (auto & chair : chairs) {
        for (int j = 0; j < 10; j++) {
            std::cout << chair[j] << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
