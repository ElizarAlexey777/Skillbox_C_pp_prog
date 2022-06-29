#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

void ATM_info(std::ifstream& file, std::vector<int> &type_banknotes, int& banknotes_count)
{
    int banknote;
    while (!file.eof())
    {
        file >> banknote;
        if (banknote == 5000)
            type_banknotes[0]++;
        else if (banknote == 2000)
            type_banknotes[1]++;
        else if (banknote == 1000)
            type_banknotes[2]++;
        else if (banknote == 500)
            type_banknotes[3]++;
        else if (banknote == 200)
            type_banknotes[4]++;
        else if (banknote == 100)
            type_banknotes[5]++;
        banknotes_count++;
        banknote = 0;
    }
}

void ATM_input(std::ofstream& file, std::vector<int>& type_banknotes)
{
    for (int i = 0; i < type_banknotes[0]; ++i) {
        file << 5000 << std::endl;
    }
    for (int i = 0; i < type_banknotes[1]; ++i) {
        file << 2000 << std::endl;
    }
    for (int i = 0; i < type_banknotes[2]; ++i) {
        file << 1000 << std::endl;
    }
    for (int i = 0; i < type_banknotes[3]; ++i) {
        file << 500 << std::endl;
    }
    for (int i = 0; i < type_banknotes[4]; ++i) {
        file << 200 << std::endl;
    }
    for (int i = 0; i < type_banknotes[5]; ++i) {
        file << 100 << std::endl;
    }
}

int main() {
    std::cout << "ATM simulation" << std::endl;
    std::cout << std::endl;

    char operation_type;

    std::cout << "Enter operation type:" << std::endl;
    std::cout << "ATM filling, enter \"+\"" << std::endl;
    std::cout << "Withdrawal of money by the user, enter \"-\"" << std::endl;

    std::cin >> operation_type;

//    путь к файлу "bank.txt"
    std::string file_path = "C:\\Users\\User\\Desktop\\Elizarov_Alexey\\C++\\Skillbox_C_pp_prog\\Writing_to_files\\20.5_Homework_ATM_simulation\\bank.txt";

    std::srand(std::time(nullptr));

    std::vector<int> type_banknotes(6, 0);
    int banknotes_count = 0;

    if (operation_type == '+') {
        for (int i = 0; i < 1000 - banknotes_count; ++i) {
            type_banknotes[rand() % 6]++;
        }

        std::ofstream atm(file_path, std::ios::binary);

        if (atm.is_open()){
            ATM_input(atm, type_banknotes);
            std::cout << "ATM replenishment with banknotes completed successfully!" << std::endl;
            atm.close();
        } else {
            std::cout << "Wrong file path! Try again..." << std::endl;
        }
    } else if (operation_type == '-'){
        int sum;
        std::cout << "Enter the amount of money to debit from the account:" << std::endl;
        std::cin >> sum;

        std::ifstream atm(file_path, std::ios::binary);

        if (atm.is_open()){
            ATM_info(atm, type_banknotes, banknotes_count);
            atm.close();
        } else {
            std::cout << "Wrong file path! Try again..." << std::endl;
            return 0;
        }

        while(sum != 0){
            if (type_banknotes[0] > 0 and sum >= 5000){
                sum -= 5000;
                type_banknotes[0]--;
            } else if (type_banknotes[1] > 0 and sum >= 2000){
                sum -= 2000;
                type_banknotes[1]--;
            } else if (type_banknotes[2] > 0 and sum >= 1000){
                sum -= 1000;
                type_banknotes[2]--;
            } else if (type_banknotes[3] > 0 and sum >= 500){
                sum -= 500;
                type_banknotes[3]--;
            } else if (type_banknotes[4] > 0 and sum >= 200){
                sum -= 200;
                type_banknotes[4]--;
            } else if (type_banknotes[5] > 0 and sum >= 100){
                sum -= 100;
                type_banknotes[5]--;
            } else if(sum > 0){
                std::cout << "Operation is not possible! Invalid payout amount.";
                break;
            }
        }

        if (sum == 0) {
            std::ofstream atm(file_path, std::ios::binary);

            ATM_input(atm, type_banknotes);
            atm.close();

            std::cout << "Money issued, thank you, come back again!";
        }
    }
    return 0;
}
