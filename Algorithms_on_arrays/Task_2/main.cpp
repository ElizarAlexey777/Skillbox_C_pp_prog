#include <iostream>
#include <vector>

int main() {
    std::cout << "Task 2" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec = {7, 2, 11, 10};
    int result = 9;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }

    int first_num, second_num;
    for (int i = 0; i < vec.size(); i++) {
        first_num = vec[i];
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] > result - first_num) {
                break;
            }
            second_num = vec[j];
            if (first_num + second_num == result) {
                std::cout << "First number: " << first_num << std::endl;
                std::cout << "Second number: " << second_num << std::endl;
                std::cout << first_num << " + " << second_num << " = " << result << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
