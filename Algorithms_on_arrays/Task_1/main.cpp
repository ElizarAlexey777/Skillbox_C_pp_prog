#include <iostream>
#include <vector>


int main() {
    std::cout << "Task 1" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int i = 0;
    int j = 0;
    int min_summa = 0;
    int min_pos = -1;
    int summa = 0;
    int answer = vec[0];

    for (int x = 0; x < vec.size(); x++) {
        summa += vec[x];
        int summa_temp = summa - min_summa;

        if (summa_temp > answer) {
            answer = summa_temp;
            i = min_pos + 1;
            j = x;
        }

        if (summa < min_summa) {
            min_summa = summa;
            min_pos = x;
        }
    }

//    int summa_max = 0;
//    for (int x = 0; x < vec.size(); x++) {
//        summa_temp = vec[x];
//        for (int y = x + 1; y < vec.size(); y++) {
//            summa_temp += vec[y];
//            if (summa_temp > summa_max) {
//                i = x;
//                j = y;
//                summa_max = summa_temp;
//            }
//        }
//    }
    std::cout << "Range frames: " << i << " " << j << std::endl;
    return 0;
}