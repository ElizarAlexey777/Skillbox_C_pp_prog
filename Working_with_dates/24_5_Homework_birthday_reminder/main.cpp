#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>


struct birthday_table {
    std::string name = "";
    std::tm birth_date{};
};

std::vector<birthday_table> birthdays;

void get_name(std::string & name) {
    std::cout << "Enter your friend's name:" << std::endl;
    std::cin >> name;
}

void get_birth_date(std::tm & birth_date) {
    std::cout << "Enter your friend's date of birth: (YYYY/MM/DD)" << std::endl;
    std::cin >> std::get_time(&birth_date, "%Y/%m/%d");
}

void display_table() {
    std::time_t t = std::time(nullptr);
    std::tm* current = std::localtime(&t);
    int closest_month_interval = 100;
    int closest_day_interval = 100;
    birthday_table* closest_bd = nullptr;
    for (auto & birth_date_table : birthdays) {
        if (birth_date_table.birth_date.tm_mon < current->tm_mon) continue;
        if (birth_date_table.birth_date.tm_mon  == current->tm_mon
            && birth_date_table.birth_date.tm_mday == current->tm_mday) {
            std::cout << "Today is the birthday of: " << birth_date_table.name << "!"
                      << std::endl;
        }
        else if (birth_date_table.birth_date.tm_mon - current->tm_mon < closest_month_interval) {
            closest_month_interval = birth_date_table.birth_date.tm_mon - current->tm_mon;
            closest_day_interval = birth_date_table.birth_date.tm_mday - current->tm_mday;
            closest_bd = &birth_date_table;
        }
        else if (birth_date_table.birth_date.tm_mday - current->tm_mday < closest_day_interval) {
            closest_day_interval = birth_date_table.birth_date.tm_mday - current->tm_mday;
            closest_bd = &birth_date_table;
        }
    }

    if (closest_bd) {
        std::cout << "Next birthday: " << closest_bd->name << " - "
                  << std::put_time(&(closest_bd->birth_date), "%m/%d") << std::endl;
    }
}

int main() {
    std::cout << "Birthday reminder" << std::endl << std::endl;

    birthday_table bd_t;
    while (true) {
        get_name(bd_t.name);
        if (bd_t.name == "end") {
            display_table();
            break;
        }
        get_birth_date(bd_t.birth_date);
        birthdays.push_back(bd_t);
    }
    return 0;
}
