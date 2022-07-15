#include <iostream>
#include <map>
#include <string>

int main() {
    std::cout << "Registry" << std::endl;
    std::cout << std::endl;

    int num_client = 0;
    std::map<std::string, std::string> registry;
    std::string input;
    std::string key_input;

    while (true) {
        std::cout << "Enter the client's last name or team:" << std::endl;
        std::cout << "{last name} - register a customer by last name in the queue" << std::endl;
        std::cout << "\"Next\" - call the next client from the queue" << std::endl;
        std::cout << "\"Exit\" - finish the job and clear the queue" << std::endl;
        std::cin >> input;

        if (input == "Exit") break;

        if (input == "Next") {
            if (num_client > 0) {
                std::cout << "Next client in the queue: " << registry.begin()->second << std::endl;
                registry.erase(registry.begin());
                num_client--;
            } else std::cout << "Queue is empty :(" << std::endl;
        } else {
            key_input = input + std::to_string(num_client);
            registry[key_input] = input;
            num_client++;
        }
        std::cout << std::endl;
    }
    return 0;
}