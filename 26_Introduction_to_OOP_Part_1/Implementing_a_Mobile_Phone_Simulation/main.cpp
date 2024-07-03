#include <iostream>
#include <vector>
#include <sstream>

struct Contact {
    std::pair<std::string, std::string> contact;

    Contact(std::pair<std::string, std::string> contact_t) : contact(contact_t) {};
};

class Phone {
private:
    std::vector<Contact> contact_book;

    bool isValidPhoneNumber(const std::string& phoneNumber) {
        if (phoneNumber.size() == 12 && phoneNumber.substr(0, 2) == "+7") {
            for (size_t i = 2; i < phoneNumber.size(); ++i) {
                if (!isdigit(phoneNumber[i])) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    std::vector<Contact>::iterator findContact(const std::string& type, const std::string& value) {
        if (type == "name") {
            return std::find_if(contact_book.begin(), contact_book.end(),
                [&](const Contact& c) { return c.contact.first == value; });
        } else if (type == "phone") {
            return std::find_if(contact_book.begin(), contact_book.end(),
                [&](const Contact& c) { return c.contact.second == value; });
        } else {
            return contact_book.end();
        }
    }

public:
    void add() {
        std::string contact_name, contact_phone;
        std::cout << "Enter a contact name: ";
        std::cin >> contact_name;
        std::cout << "Enter a phone number: ";
        std::cin >> contact_phone;
        if (isValidPhoneNumber(contact_phone)) {
            contact_book.push_back(Contact({ contact_name, contact_phone }));
        } else {
            std::cout << "Invalid phone number" << std::endl;
        }
    }

    void call() {
        std::cin.ignore();
        std::string input;
        std::cout << "Enter a contact name or a phone number: (name [name] / phone [phone_number]): ";
        std::getline(std::cin, input);
        std::istringstream ss(input);

        std::string type, value;
        ss >> type >> value;

        auto it = findContact(type, value);
        if (it != contact_book.end()) {
            std::cout << "CALL: " << it->contact.second << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void sms() {
        std::cin.ignore();
        std::string input;
        std::cout << "Enter a contact name or a phone number: (name [name] / phone [phone_number]): ";
        std::getline(std::cin, input);
        std::istringstream ss(input);

        std::string type, value;
        ss >> type >> value;

        auto it = findContact(type, value);
        if (it != contact_book.end()) {
            std::cout << "SMS to " << it->contact.second << ": ";
            std::string message;
            std::getline(std::cin, message);
            std::cout << "SMS sent successfully!" << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }
};

int main() {
    std::cout << "-- Implementing a Mobile Phone Simulation --" << std::endl;

    Phone* phone = new Phone;
    std::string command;

    do {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "add") phone->add();
        else if (command == "call") phone->call();
        else if (command == "sms") phone->sms();
        else if (command == "exit") {
            delete phone;
            return 0;
        } else std::cout << "Command is error! Try again!!!\n";
    } while (true);
}
