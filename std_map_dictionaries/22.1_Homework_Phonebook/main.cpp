#include <iostream>
#include <string>
#include <map>
#include <vector>

void add(std::map<std::string, std::vector<std::string>> & phonebook_name, std::map<std::string, std::string> & phonebook_phone) {
    std::string phone_num, last_name;

    std::cout << "Enter the phone number and last name of the subscriber to add to the phonebook: (split - space)" << std::endl;
    std::cin >> phone_num >> last_name;

    phonebook_phone.insert(std::make_pair(phone_num, last_name));

    if (phonebook_phone[phone_num] == last_name) {
        phonebook_name[last_name].push_back(phone_num);
        std::cout << "Subscriber " << last_name << " with phone number " << phone_num
                  << " data has been successfully saved!" << std::endl << std::endl;
    } else std::cout << "A subscriber with this phone number already exists (wrong data)" << std::endl << std::endl;
}

void findName(std::map<std::string, std::string> & phonebook_phone) {
    std::string phone_num;
    std::cout << "Enter the subscriber's phone number to get the subscriber's details: (separator - dash)" << std::endl;
    std::cin >> phone_num;

    std::cout << "Surname of the subscriber by phone number " << phone_num << ": " << phonebook_phone[phone_num] << std::endl << std::endl;
}

void findPhoneNum(std::map<std::string, std::vector<std::string>> & phonebook_name) {
    std::string last_name;
    std::cout << "Enter the subscriber's last name to get the subscriber's phone number:" << std::endl;
    std::cin >> last_name;

    std::cout << "Phone numbers found by last name " << last_name << ":" << std::endl;
    for (int i = 0; i < phonebook_name[last_name].size(); i++) {
        std::cout << phonebook_name[last_name][i] << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Phonebook" << std::endl;
    std::cout << std::endl;

    std::map<std::string, std::string> phonebook_key_phone;
    std::map<std::string, std::vector<std::string>> phonebook_key_name;
    std::string command;

    do {
        std::cout << "Choose a command from the list:" << std::endl;
        std::cout << "\"add\" - add the phone number and last name of the subscriber to the directory" << std::endl;
        std::cout << "\"find name\" - find out the last name of the subscriber by phone number" << std::endl;
        std::cout << "\"find phone number\" - find out the phone number of the subscriber by last name" << std::endl;
        std::cout << "\"exit\" - close the phonebook and end the program" << std::endl;
        std::getline(std::cin, command);
        std::cout << std::endl;

        if (command == "exit") {
            std::cout << "At the moment we are closing the phonebook and the program, see you soon!" << std::endl;
            break;
        }

        if (command == "add") {
            add(phonebook_key_name, phonebook_key_phone);
        } else if (command == "find name") {
            findName(phonebook_key_phone);
        } else if (command == "find phone number") {
            findPhoneNum(phonebook_key_name);
        } else {
            std::cout << "Unknown operation... Try again" << std::endl;
        }

        std::cin.ignore(256, '\n');
    } while (command != "exit");

    return 0;
}
