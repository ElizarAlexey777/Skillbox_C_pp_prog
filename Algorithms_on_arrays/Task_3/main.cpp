#include <iostream>
#include <vector>

std::vector<int> sort_vec(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
    return vec;
}

int main() {
    std::cout << "Task 3" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec;

    int inp;
    do {
        std::cin >> inp;
        if (inp == -1) {
            vec = sort_vec(vec);
            std::cout << "5th ascending element in the array: " << vec[4] << std::endl;
        } else {
            vec.push_back(inp);
        }
    } while (inp != -2);
    return 0;
}
