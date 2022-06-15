#include <iostream>
#include <vector>
#include <fstream>

const int sector_numbers[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void print_score_and_round(int &round, int more, int less) {
    round++;
    std::cout << std::endl;
    if (more == less) {
        std::cout << "                                           Score " << more << ":" << less << ". Score equalized" << std::endl;
    } else {
        std::string favour = more > less ? "experts" : "viewers";
        std::cout << "                                           Score " << more << ":" << less << " in favor of " << favour << std::endl;
    }
    if (more != 6 and less != 6) {
        std::cout << "                                                      Round " << round << std::endl;
    }
}

bool check_sector(std::vector<int> (&chosen_sector_numbers), int &cur) {
    bool found = false;
    for (int chosen_sector_number : chosen_sector_numbers) {
        if (cur == chosen_sector_number and chosen_sector_number != 0) {
            found = true;
        }
    }
    if (!found) {
        chosen_sector_numbers.push_back(cur);
        return true;
    }
    return false;
}

int next_sector(int cur_sector) {
    std::cout << "                Sector " << cur_sector << " already dropped out today, let's move on to the next one!                " << std::endl;
    std::cout << std::endl;
    return (cur_sector % 13) + 1;
}

int choose_sector(int cur_sector, int offset, std::vector<int> (&chosen_sector_numbers)) {
    cur_sector = sector_numbers[((cur_sector - 1) + (offset % 13)) % 13];
    while (!check_sector(chosen_sector_numbers, cur_sector)) {
        cur_sector = next_sector(cur_sector);
    }
    return cur_sector;
}

bool check_answer(std::string answer_expert, std::string correct_answer) {
    return answer_expert == correct_answer;
}

void question_and_answer(int cur_sector, int &score_experts, int &score_viewers) {
    std::cout << "                                    Attention! Question of sector " << cur_sector << ":" << std::endl;
    std::ifstream question;
//    question.open(#путь_к_папке_с_вопросами + "\\question_" + std::to_string(cur_sector) + ".txt")
    question.open("C:\\Users\\User\\Desktop\\Elizarov_Alexey\\C++\\Skillbox_C_pp_prog\\Reading_from_files\\19.5_Homework_game_What_Where_When\\question_" + std::to_string(cur_sector) + ".txt");

    if (question.is_open()) {
        while(!question.eof()) {
            char buffer[20];
            question.read(buffer, sizeof(buffer));
            buffer[question.gcount()] = '\0';
            std::cout << buffer;
        }
        std::cout << std::endl;
    } else {
        std::cout << "Invalid file path or such file does not exist!" << std::endl;
    }

    question.close();

    std::string answer_expert, correct_answer;
    std::cin >> answer_expert;

    std::ifstream answer_file;
//    answer_file.open(#путь_к_папке_с_вопросами + "\\question_" + std::to_string(cur_sector) + "_answer.txt")
    answer_file.open("C:\\Users\\User\\Desktop\\Elizarov_Alexey\\C++\\Skillbox_C_pp_prog\\Reading_from_files\\19.5_Homework_game_What_Where_When\\question_" + std::to_string(cur_sector) + "_answer.txt");

    if (answer_file.is_open()) {
        answer_file >> correct_answer;
        std::cout << "                                    Attention! Correct answer: " << correct_answer << std::endl;
        if (check_answer(answer_expert, correct_answer)) {
            score_experts++;
            std::cout << "                                    Of course! This is the correct answer!" << std::endl;
        } else {
            score_viewers++;
            std::cout << "                                    It's a shame, but this is the wrong answer..." << std::endl;
        }
    } else {
        std::cout << "Invalid file path or such file does not exist!" << std::endl;
    }

    answer_file.close();
}

void define_winner(int score_experts, int score_viewers) {
    std::string favour = score_experts > score_viewers ? "experts" : "viewers";
    int more = score_experts > score_viewers ? score_experts : score_viewers;
    int less = score_experts < score_viewers ? score_experts : score_viewers;
    std::cout << "                                      Final Score " << more << ":" << less << " in favor of " << favour << std::endl;
    if (score_experts == 6) {
        std::cout << "A team of connoisseurs defeats the TV viewers and gets the right to play in the main episode of the season!" << std::endl;
    } else {
        std::cout << "So, in this game, the viewers won! You know the list of their names. Each of them will receive 100,000 rubles!" << std::endl;
    }
}

int check_offset(int offset) {
    while (offset == 0) {
        std::cout << "                                    Mister Druz', don't brake the drum, please... :)" << std::endl;
        std::cout << "Re-enter the offset, please: " << std::endl;
        std::cin >> offset;
    }
    return offset;
}

int main() {
    std::cout << "Game \"What? Where? When?\"" << std::endl;
    std::cout << std::endl;

    std::cout << "Today Sunday, June 12, in Moscow 22 hours 7 minutes, and we start a live broadcast of the game \"What? Where? When?\"" << std::endl;
    std::cout << "                                Good evening dear viewers, good evening dear experts" << std::endl;
    std::cout << "                                                  Play to 6 points" << std::endl;
    std::cout << "                                                     Score  0:0" << std::endl;
    std::cout << "                                                      Round  1" << std::endl;
    std::cout << std::endl;

    std::vector <int> chosen_sector_numbers;
    int offset, cur_sector = sector_numbers[0], cur_round = 1, score_experts = 0, score_viewers = 0;

    do {
        std::cout << "Enter the offset of the index arrow of the spinning top on the drum: " << std::endl;

        std::cin >> offset;
        offset = check_offset(offset);
        cur_sector = choose_sector(cur_sector, offset, chosen_sector_numbers);
        question_and_answer(cur_sector, score_experts, score_viewers);
        print_score_and_round(cur_round, score_experts, score_viewers);
    } while (score_experts != 6 and score_viewers != 6);

    define_winner(score_experts, score_viewers);
    return 0;
}
