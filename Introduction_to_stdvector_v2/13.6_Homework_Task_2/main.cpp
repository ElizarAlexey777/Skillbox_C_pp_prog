#include <iostream>
#include <vector>

int main() {
    std::cout << "Task 2" << std::endl;
    std::cout << std::endl;

    std::vector<float> product_prices = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> products_ind = {1, 1, 0, 3};
    float total_price = 0;

    std::cout << "Price vector: ";
    for (float price : product_prices) {
        std::cout << price << ' ';
    }
    std::cout << std::endl;

    std::cout << "Shopping vector: ";
    for (int ind : products_ind) {
        std::cout << ind << ' ';
    }
    std::cout << std::endl;

    for (int i : products_ind) {
        total_price += product_prices[i];
    }
    std::cout << "Total price: " << total_price;
    return 0;
}
