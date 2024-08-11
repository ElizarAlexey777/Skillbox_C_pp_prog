#include <cpr/cpr.h>
#include <iostream>
#include <string>

int main() {
    cpr::Response response = cpr::Get(cpr::Url{ "http://httpbin.org/html" },
        cpr::Header{ {"accept", "text/html"} });

    if (response.status_code == 200) {
        std::string::size_type start_pos = response.text.find("<h1>");
        std::string::size_type end_pos = response.text.find("</h1>");

        if (start_pos != std::string::npos && end_pos != std::string::npos) {
            std::string title = response.text.substr(start_pos + 4, end_pos - start_pos - 4);

            std::cout << "Заголовок статьи: " << title << std::endl;
        } else {
            std::cout << "Заголовок статьи не найден." << std::endl;
        }
    } else {
        std::cout << "Запрос не удался, статус код: " << response.status_code << std::endl;
    }

    return 0;
}
