#include <iostream>
#include <vector>

enum note
{
    DO = 1 << 0,
    RE = 1 << 1,
    MI = 1 << 2,
    FA = 1 << 3,
    SOL = 1 << 4,
    LA = 1 << 5,
    SI = 1 << 6
};

void pianoSound (int ch)
{
    int sound = 1 << ch;

    if (sound & DO)
        std::cout << "DO ";
    else if (sound & RE)
        std::cout << "RE ";
    else if (sound & MI)
        std::cout << "MI ";
    else if (sound & FA)
        std::cout << "FA ";
    else if (sound & SOL)
        std::cout << "SOL ";
    else if (sound & LA)
        std::cout << "LA ";
    else if (sound & SI)
        std::cout << "SI ";
}

bool check(std::string melody_combination) {
    bool flag = true;
    for (char note_num : melody_combination) {
        if (note_num < '0' or note_num > '7') {
            flag = false;
        }
    }
    return flag;
}


int main() {
    std::cout << "Mechanical piano" << std::endl;
    std::cout << std::endl;

    std::string melody_combinations[12];

    std::cout << "Enter 12 note combinations" << std::endl;
    for (int comb = 0; comb < 12; comb++) {
        std::cout << "Enter melody combination #" << comb + 1 << ":" << std::endl;
        std::cin >> melody_combinations[comb];
        while (!check(melody_combinations[comb])) {
            std::cout << "Enter the correct melody format (notes from 1 to 7):" << std::endl;
            std::cin >> melody_combinations[comb];
        }
    }

    for (auto & melody_combination : melody_combinations) {
        for (auto & note : melody_combination) {
            pianoSound(note - '1');
        }
        std::cout << std::endl;
    }

    return 0;
}
