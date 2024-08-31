#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

template <typename K, typename V>
struct Entry {
    K key;
    V value;

    Entry(K k, V v) : key(k), value(v) {}
};

template <typename K, typename V>
class Registry {
private:
    std::vector<Entry<K, V>> entries;

public:
    void add(const K& key, const V& value) {
        entries.push_back(Entry<K, V>(key, value));
    }

    void remove(const K& key) {
        entries.erase(std::remove_if(entries.begin(), entries.end(),
            [&key](const Entry<K, V>& entry) { return entry.key == key; }),
            entries.end());
    }

    void find(const K& key) const {
        for (const auto& entry : entries) {
            if (entry.key == key) {
                std::cout << "Key: " << entry.key << ", Value: " << entry.value << std::endl;
            }
        }
    }

    void print() const {
        for (const auto& entry : entries) {
            std::cout << "Key: " << entry.key << ", Value: " << entry.value << std::endl;
        }
    }
};

template <typename T>
T convertToType(const std::string& str) {
    std::istringstream iss(str);
    T value;
    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Invalid input for conversion");
    }
    return value;
}

bool isInteger(const std::string& str) {
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+'))) return false;

    char* p;
    strtol(str.c_str(), &p, 10);

    return (*p == 0);
}

template <typename K, typename V>
void processCommands(Registry<K, V>& registry) {
    std::string command;
    while (true) {
        std::cout << "Enter command (add, remove, find, print, exit): ";
        std::cin >> command;

        if (command == "add") {
            std::string keyStr, valueStr;
            std::cin >> keyStr >> valueStr;

            try {
                K key = convertToType<K>(keyStr);
                V value = convertToType<V>(valueStr);
                registry.add(key, value);
            } catch (const std::invalid_argument&) {
                std::cout << "Invalid key-value type combination!" << std::endl;
            }

        } else if (command == "remove") {
            K key;
            std::cin >> key;
            registry.remove(key);

        } else if (command == "find") {
            K key;
            std::cin >> key;
            registry.find(key);

        } else if (command == "print") {
            registry.print();

        } else if (command == "exit") {
            break;

        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

template <typename K, typename V>
void createRegistry(const std::string& keyStr, const std::string& valueStr) {
    try {
        K key = convertToType<K>(keyStr);
        V value = convertToType<V>(valueStr);

        Registry<K, V> registry;
        registry.add(key, value);
        processCommands(registry);
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void determineAndStartRegistry(const std::string& keyStr, const std::string& valueStr) {
    try {
        if (keyStr.find('.') != std::string::npos) {
            createRegistry<double, std::string>(keyStr, valueStr);
        } else if (isInteger(keyStr)) {
            createRegistry<int, std::string>(keyStr, valueStr);
        } else {
            throw std::invalid_argument("Unsupported key type");
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Unsupported key-value type combination!" << std::endl;
    }
}

int main() {
    std::string key, value;

    std::cout << "Enter first key-value pair (key and value separated by space): ";
    std::cin >> key >> value;

    determineAndStartRegistry(key, value);

    return 0;
}
