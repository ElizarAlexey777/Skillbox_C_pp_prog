#include <iostream>
#include <fstream>

bool check_date_payment(std::string date_payment) {
    if (std::stoi(date_payment.substr(0, 2)) <= 31 and std::stoi(date_payment.substr(0, 2)) >= 1
    and std::stoi(date_payment.substr(3, 5)) <= 12 and std::stoi(date_payment.substr(3, 5)) >= 1
    and std::stoi(date_payment.substr(7, 9)) <= 99 and std::stoi(date_payment.substr(7, 9)) >= 1) {
        return true;
    }
    std::cout << "Invalid date format" << std::endl;
    return false;
}

bool check_exit(std::string exit_in_name_surname) {
    if (exit_in_name_surname == "Exit") {
        return false;
    }
    return true;
}

int main() {
    std::cout << "Entry in the ledger" << std::endl;
    std::cout << std::endl;

    int payment;
    std::string date_payment;
    std::string name_surname;

    std::ofstream bill;
    bill.open("#путь_к_файлу_\"bill.txt\"");
//    bill.open(R"(C:\Users\User\Desktop\Elizarov_Alexey\C++\Skillbox_C_pp_prog\Writing_to_files\20.5_Homework_Entry_in_the_ledger\bill.txt)", std::ios::app);

    std::cout << R"(Enter "Exit" in the first and last name line to end the program)" << std::endl;
    bool flag = true;

    do {
        std::cout << "Enter the name and surname of the payee:" << std::endl;
        std::getline(std::cin, name_surname);
        if (!check_exit(name_surname)) {
            break;
        }

        do {
            std::cout << "Enter payment date: (format DD/MM/YY)" << std::endl;
            std::cin >> date_payment;
        } while(!check_date_payment(date_payment));

        std::cout << "Enter the payout amount:" << std::endl;
        std::cin >> payment;

        bill << name_surname << " " << date_payment << " " << payment << "\n";
        std::cout << "User " << name_surname << " data was successfully written!" << std::endl;
        std::cout << std::endl;

        std::cin.ignore(256,'\n');
    }
    while (true);

    bill.close();

    std::cout << "All data has been successfully written to the bill (\"bill.txt\")!" << std::endl;
    return 0;
}
