#include <iostream>
#include <string>
#include <map>

//bool check_anagram(std::string & first, std::string & second) {
//    std::map <char, int> anagram;
//
//    if (first.length() == second.length()) {
//        for (int j = 0; j < first.length(); j++) {
//            if (anagram.find(first[j]) != anagram.cend()) {
//                auto it = anagram.find(first[j]);
//                it-> second++;
//            } else anagram.insert(std::pair<char, int> (first[j], 1));
//        }
//        for (int j = 0; j < second.length(); j++) {
//            if (anagram.find(second[j]) != anagram.cend()) {
//                auto it = anagram.find(second[j]);
//                it->second--;
//            } else return false;
//        }
//        for (auto j = anagram.begin(); j != anagram.end(); j++) {
//            if (j->second != 0) {
//                return false;
//            }
//        }
//        return true;
//    } else return false;
//}

std::map<char, int> countChars(std::string& string) {
    std::map<char, int> result;
    for (int i = 0; i < string.length(); ++i) {
        std::pair<char,int> pair = {string[i],string[i]};
        result.insert(pair);
    }
    return result;
}

int main() {
    std::cout << "Anagrams" << std::endl << std::endl;

    std::string first, second;

    std::cout << "Enter the first word:" << std::endl;
    std::cin >> first;
    std::map<char,int> first_m = countChars(first);

    std::cout << "Enter the second word:" << std::endl;
    std::cin >> second;
    std::map<char,int> second_m = countChars(second);

    if (first_m == second_m) {
        std::cout << "The first line is an anagram of the second line" << std::endl;
    } else {
        std::cout << "The first line is not an anagram of the second line" << std::endl;
    }
}