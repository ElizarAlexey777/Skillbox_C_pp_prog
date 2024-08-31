#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class Shop {
public:
    void addProduct(const std::string& product_article, int quantity) {
        if (quantity < 0) {
            throw std::invalid_argument("Количество товара не может быть отрицательным");
        }
        inventory[product_article] += quantity;
    }

    int getProductQuantity(const std::string& product_article) const {
        auto it = inventory.find(product_article);
        if (it == inventory.end()) {
            return 0;
        }
        return it->second;
    }

private:
    std::map<std::string, int> inventory;
};

class Cart {
public:
    Cart(const Shop& shop) : shop(shop) {}

    void add(const std::string& product_article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Количество товара должно быть больше нуля");
        }

        int available_quantity = shop.getProductQuantity(product_article);
        if (available_quantity == 0) {
            throw std::invalid_argument("Товар не найден в базе данных магазина");
        }

        if (available_quantity < quantity) {
            throw std::runtime_error("Недостаточно товара на складе");
        }

        cart[product_article] += quantity;
    }

    void remove(const std::string& product_article, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Количество товара должно быть больше нуля");
        }

        auto it = cart.find(product_article);
        if (it == cart.end() || it->second < quantity) {
            throw std::runtime_error("Недостаточно товара в корзине для удаления");
        }

        cart[product_article] -= quantity;
        if (cart[product_article] == 0) {
            cart.erase(product_article);
        }
    }

    void printCart() const {
        if (cart.empty()) {
            std::cout << "Корзина пуста\n";
        } else {
            std::cout << "Корзина:\n";
            for (const auto& item : cart) {
                std::cout << item.first << ": " << item.second << " шт.\n";
            }
        }
    }

private:
    const Shop& shop;
    std::map<std::string, int> cart;
};

int main() {
    try {
        Shop shop;

        int product_count;
        std::cout << "Введите количество товаров в магазине: ";
        std::cin >> product_count;

        for (int i = 0; i < product_count; ++i) {
            std::string product_article;
            int quantity;

            std::cout << "Введите артикул товара: ";
            std::cin >> product_article;
            std::cout << "Введите количество товара: ";
            std::cin >> quantity;

            try {
                shop.addProduct(product_article, quantity);
                std::cout << "Товар добавлен в базу данных магазина\n";
            } catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
                --i;
            }
        }

        Cart cart(shop);

        std::string command;
        while (true) {
            std::cout << "\nВведите команду (add, remove, print, exit): ";
            std::cin >> command;

            if (command == "add") {
                std::string product_article;
                int quantity;
                std::cout << "Введите артикул товара: ";
                std::cin >> product_article;
                std::cout << "Введите количество: ";
                std::cin >> quantity;

                try {
                    cart.add(product_article, quantity);
                    std::cout << "Товар добавлен в корзину\n";
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }

            } else if (command == "remove") {
                std::string product_article;
                int quantity;
                std::cout << "Введите артикул товара: ";
                std::cin >> product_article;
                std::cout << "Введите количество: ";
                std::cin >> quantity;

                try {
                    cart.remove(product_article, quantity);
                    std::cout << "Товар удален из корзины\n";
                } catch (const std::exception& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }

            } else if (command == "print") {
                cart.printCart();

            } else if (command == "exit") {
                std::cout << "Выход из программы\n";
                break;

            } else {
                std::cerr << "Неизвестная команда\n";
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
