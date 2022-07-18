#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#define MONDAY_NAME std::cout << "Monday";
#define TUESDAY_NAME std::cout << "Tuesday";
#define WEDNESDAY_NAME std::cout << "Wednesday";
#define THURSDAY_NAME std::cout << "Thursday";
#define FRIDAY_NAME std::cout << "Friday";
#define SATURDAY_NAME std::cout << "Saturday";
#define SUNDAY_NAME std::cout << "Sunday";

int main() {
    std::cout << "Advanced input and output of days of the week" << std::endl << std::endl;

    int day_ord_num;

    std::cout << "Enter the day of the week as its ordinal number:" << std::endl;
    std::cin >> day_ord_num;

    if (day_ord_num < 1 or day_ord_num > 7) {
        std::cout << "Invalid day ordinal" << std::endl;
        return -1;
    }

    if (day_ord_num == MONDAY) {
        MONDAY_NAME
    } else if (day_ord_num == TUESDAY) {
        TUESDAY_NAME
    } else if (day_ord_num == WEDNESDAY) {
        WEDNESDAY_NAME
    } else if (day_ord_num == THURSDAY) {
        THURSDAY_NAME
    } else if (day_ord_num == FRIDAY) {
        FRIDAY_NAME
    } else if (day_ord_num == SATURDAY) {
        SATURDAY_NAME
    } else SUNDAY_NAME
    return 0;
}
