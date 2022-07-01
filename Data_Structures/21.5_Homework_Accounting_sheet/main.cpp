#include <iostream>
#include <string>
#include <fstream>
#include <string>

struct bill {
    std::string name;
    std::string surname;
    std::string date_payment;
    int payment = 0;
};

void read_bill(std::ifstream& file) {
    bill recipient;
    while (!file.eof()) {
        file >> recipient.name >> recipient.surname >> recipient.date_payment >> recipient.payment;
        if (file.eof()) break;
        std::cout << recipient.name << " " << recipient.surname << " " << recipient.date_payment << " " << recipient.payment << std::endl;
    }
}

bool check_date_payment(std::string date_payment) {
    if (std::stoi(date_payment.substr(0, 2)) <= 31 and std::stoi(date_payment.substr(0, 2)) >= 1
        and std::stoi(date_payment.substr(3, 5)) <= 12 and std::stoi(date_payment.substr(3, 5)) >= 1
        and std::stoi(date_payment.substr(7, 9)) <= 99 and std::stoi(date_payment.substr(7, 9)) >= 1) {
        return true;
    }
    std::cout << "Invalid date format" << std::endl;
    return false;
}

void add_to_bill(std::ofstream& file) {
    bill recipient;

    std::cout << "Enter the name of the payee:" << std::endl;
    std::cin >> recipient.name;

    std::cout << "Enter the surname of the payee:" << std::endl;
    std::cin >> recipient.surname;

    do {
        std::cout << "Enter payment date: (format DD/MM/YY)" << std::endl;
        std::cin >> recipient.date_payment;
    } while (!check_date_payment(recipient.date_payment));

    std::cout << "Enter the payout amount:" << std::endl;
    std::cin >> recipient.payment;

    file << recipient.name << " " << recipient.surname << " " << recipient.date_payment << " " << recipient.payment << std::endl;

    std::cout << recipient.name << " " << recipient.surname << " data was successfully written!" << std::endl;
}

int main() {
    std::cout << "Accounting sheet" << std::endl;
    std::cout << std::endl;

    std::string command;

    std::cout << "Specify the command by which the program will run:" << std::endl;
    std::cout << "\"list\" - reading data from the list file into data structures and displaying them on the screen" << std::endl;
    std::cout << "\"add\" - adding new data to the end of the list" << std::endl;
    std::cout << "\"exit\" - exit the program" << std::endl;
    std::cin >> command;

    std::string file_path = R"(C:\Users\User\Desktop\Elizarov_Alexey\C++\Skillbox_C_pp_prog\Data_Structures\21.5_Homework_Accounting_sheet\bill.txt)";

    while (command != "exit") {
        if (command == "list") {
            std::ifstream bill_file(file_path);
            if (bill_file.is_open()) {
                read_bill(bill_file);
            } else {
                std::cout << "Wrong file path! Try again..." << std::endl;
            }
            bill_file.close();
        } else if (command == "add") {
            std::ofstream bill_file(file_path, std::ios::app);
            if (bill_file.is_open()) {
                add_to_bill(bill_file);
            } else {
                std::cout << "Wrong file path! Try again..." << std::endl;
            }
        }
        std::cout << R"(Specify the command ("list", "add", "exit"):)" << std::endl;
        std::cin >> command;
    }
    std::cout << "Closing the program... All data successfully saved!" << std::endl;
    return 0;
}
