#include <iostream>
#include <fstream>

int main() {
    std::cout << "Program for searching words in a file" << std::endl;
    std::cout << std::endl;

    std::string word;

    std::cout << "Enter a search word in the \"words.txt\" file:" << std::endl;
    std::cin >> word;

    std::ifstream words;
    words.open("#путь_к_файлу_\"words.txt\"");

    int count_matched_words = 0;

    while(!words.eof()) {
        std::string file_word;
        words >> file_word;
        if (word == file_word) {
            count_matched_words++;
        }
    }

    std::cout << "The number of words from the file that matched the word '" << word << "': " << count_matched_words << std::endl;
    return 0;
}
