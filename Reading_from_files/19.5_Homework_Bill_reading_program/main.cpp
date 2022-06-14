#include <iostream>
#include <fstream>

int main() {
    std::cout << "Bill reading program" << std::endl;
    std::cout << std::endl;

    std::ifstream bill;
    bill.open("#путь_к_файлу_\"bill.txt\"");

    int total_payment = 0, max_payment = 0;
    std::string name_surname_max_payment;

    while(!bill.eof()) {
        int payment;
        std::string name, surname, payment_date;
        bill >> name >> surname >> payment >> payment_date;
        total_payment += payment;
        if (payment > max_payment) {
            name_surname_max_payment = name + " " + surname;
            max_payment = payment;
        }
    }
    std::cout << "Total amount paid out: " << total_payment << std::endl;
    std::cout << "The person with the highest payout: " << name_surname_max_payment << std::endl;
    bill.close();
    return 0;
}
