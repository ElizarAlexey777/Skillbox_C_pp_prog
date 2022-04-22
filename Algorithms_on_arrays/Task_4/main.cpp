#include <iostream>
#include <vector>

void sort_vec_abs(std::vector<int> vec) {
    bool flag = false;
    int count_sdvig = 0;
    int ind_first_pol = 0;
    for (int i = 0; i + count_sdvig < vec.size(); i++) {
        if (vec[i] >= 0 and !flag) {
            flag = true;
            ind_first_pol = i;
            std::cout << vec[i] << ' ';
        }
        if (flag) {
            count_sdvig += 1;
            if (ind_first_pol - count_sdvig >= 0 and ind_first_pol + count_sdvig <= vec.size()) {
                if (std::abs(vec[ind_first_pol + count_sdvig]) > std::abs(vec[ind_first_pol - count_sdvig])) {
                    if (ind_first_pol - count_sdvig >= 0) {
                        std::cout << vec[ind_first_pol - count_sdvig] << ' ';
                    }
                    if (ind_first_pol + count_sdvig < vec.size()) {
                        std::cout << vec[ind_first_pol + count_sdvig] << ' ';
                    }
                } else {
                    if (ind_first_pol + count_sdvig < vec.size()) {
                        std::cout << vec[ind_first_pol + count_sdvig] << ' ';
                    }
                    if (ind_first_pol - count_sdvig >= 0) {
                        std::cout << vec[ind_first_pol - count_sdvig] << ' ';
                    }
                }
                i -= 1;
            }
        }
    }
}

int main() {
    std::cout << "Task 4" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec = {-100, -50, -5, 1, 10, 15};

    std::cout << "Array sorted in ascending modulus: " << std::endl;
    sort_vec_abs(vec);
    std::cout << std::endl;
    return 0;
}
