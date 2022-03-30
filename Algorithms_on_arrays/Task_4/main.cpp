#include <iostream>
#include <vector>

std::vector<int> sort_vec_abs(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (std::abs(vec[j]) > std::abs(vec[j+1])) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
    return vec;
}

int main() {
    std::cout << "Task 4" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec = {-100, -50, -5, 1, 10, 15};

    std::cout << "Array sorted in ascending modulus: " << std::endl;
    for (int i : sort_vec_abs(vec)) {
        std::cout << i << ' ';
    } std::cout << std::endl;
    return 0;
}
