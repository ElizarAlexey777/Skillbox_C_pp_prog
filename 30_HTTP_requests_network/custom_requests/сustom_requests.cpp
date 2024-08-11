#include "сustom_requests.h"
#include "curl/curl.h"
#include "cpr/cpr.h"
#include <iostream>
#include <string>

int main() {
    std::string command;
    std::string url = "https://httpbin.org/";

    while (true) {
        std::cout << "Введите команду (get, post, put, delete, patch, exit): ";
        std::cin >> command;

        if (command == "exit") {
            break;
        }

        cpr::Response response;

        if (command == "get") {
            response = cpr::Get(cpr::Url{ url + "get" });
        } else if (command == "post") {
            response = cpr::Post(cpr::Url{ url + "post" }, cpr::Payload{ {"key", "value"} });
        } else if (command == "put") {
            response = cpr::Put(cpr::Url{ url + "put" }, cpr::Payload{ {"key", "value"} });
        } else if (command == "delete") {
            response = cpr::Delete(cpr::Url{ url + "delete" });
        } else if (command == "patch") {
            response = cpr::Patch(cpr::Url{ url + "patch" }, cpr::Payload{ {"key", "value"} });
        } else {
            std::cout << "Неизвестная команда. Попробуйте еще раз." << std::endl;
            continue;
        }

        std::cout << "Ответ сервера:\n" << response.text << std::endl;
    }

    return 0;
}
