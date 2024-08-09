#include <iostream>
#include <random>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>
#include <ctime>
#include <vector>

const std::string food[5] = { "пицца", "суп", "стэйк", "салат", "суши" };

struct Order {
    std::string dish;
    std::time_t order_time;
    int order_number;
};

std::queue<Order> orders;
std::queue<std::pair<Order, std::time_t>> ready_meals;
std::mutex mtx;
bool kitchen_busy = false;
int deliveries = 0;
int order_number = 1;
bool stop_kitchen = false;
bool stop_orders = false;
std::time_t start_time;

void place_order() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5 + std::rand() % 6));

        {
            std::lock_guard<std::mutex> lock(mtx);
            if (stop_orders) break;

            std::string dish = food[std::rand() % 5];
            std::time_t now = std::time(nullptr);

            orders.push({ dish, now, order_number++ });
            std::cout << "Заказ " << order_number - 1 << " получен: " << dish << std::endl;
        }
    }
}

void cook() {
    while (true) {
        Order order;
        std::time_t start_cooking_time;

        {
            std::lock_guard<std::mutex> lock(mtx);

            if (stop_kitchen) {
                break;
            }

            if (!orders.empty() && !kitchen_busy) {
                order = orders.front();
                orders.pop();
                start_cooking_time = std::time(nullptr);
                kitchen_busy = true;
                std::cout << "Заказ " << order.order_number << " готовится: " << order.dish << std::endl;
            } else {
                continue;
            }
        }

        if (kitchen_busy) {
            int cook_time = 5 + std::rand() % 11;
            std::this_thread::sleep_for(std::chrono::seconds(cook_time));

            std::time_t ready_time = std::time(nullptr);
            std::time_t queue_time = start_cooking_time - order.order_time;
            std::time_t elapsed_time = ready_time - start_time;

            {
                std::lock_guard<std::mutex> lock(mtx);
                ready_meals.push({ order, ready_time });
                kitchen_busy = false;
                std::cout << "Заказ " << order.order_number << " готов (время ожидания в очереди " << queue_time
                    << " секунд(ы), время приготовления " << cook_time
                    << " секунд(ы), время с начала работы ресторана " << elapsed_time << " секунд(ы))" << std::endl;
            }
        }
    }
}

void deliver() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(30));

        std::vector<std::pair<Order, std::time_t>> orders_to_deliver;

        {
            std::lock_guard<std::mutex> lock(mtx);
            while (!ready_meals.empty()) {
                orders_to_deliver.push_back(ready_meals.front());
                ready_meals.pop();
            }
        }

        if (!orders_to_deliver.empty()) {
            for (const auto& order : orders_to_deliver) {
                deliveries++;
                std::cout << "Доставка заказа " << order.first.order_number
                    << " (количество доставок: " << deliveries << "/10)" << std::endl;

                if (deliveries >= 10) {
                    std::lock_guard<std::mutex> lock(mtx);
                    stop_orders = true;
                    stop_kitchen = true;
                    return;
                }
            }
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    start_time = std::time(nullptr);

    std::thread order_thread(place_order);
    std::thread kitchen_thread(cook);
    std::thread delivery_thread(deliver);

    delivery_thread.join();

    {
        std::lock_guard<std::mutex> lock(mtx);
        stop_orders = true;
        stop_kitchen = true;
    }

    order_thread.join();
    kitchen_thread.join();

    std::cout << "Все доставки выполнены. Ресторан завершил работу." << std::endl;
    return 0;
}
