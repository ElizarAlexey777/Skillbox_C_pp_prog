#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>

int main() {
    std::map<std::string, std::string> arguments;
    std::string key, value;

    while (true) {
        std::cout << "Введите название параметра (или 'post'/'get' для отправки запроса): ";
        std::cin >> key;

        if (key == "post" || key == "get") {
            break;
        }

        std::cout << "Введите значение параметра: ";
        std::cin >> value;

        arguments[key] = value;
    }

    if (key == "get") {
        cpr::Parameters parameters;
        for (const auto& arg : arguments) {
            parameters.Add({ arg.first, arg.second });
        }
        cpr::Response r = cpr::Get(cpr::Url{ "https://httpbin.org/get" }, parameters);
        std::cout << "Ответ сервера:\n" << r.text << std::endl;
    } else if (key == "post") {
        std::vector<cpr::Pair> payloadData;
        for (const auto& arg : arguments) {
            payloadData.push_back({ arg.first, arg.second });
        }

        cpr::Payload payload(payloadData.begin(), payloadData.end());

        cpr::Response r = cpr::Post(cpr::Url{ "https://httpbin.org/post" }, payload);
        std::cout << "Ответ сервера:\n" << r.text << std::endl;
    }


    return 0;
}