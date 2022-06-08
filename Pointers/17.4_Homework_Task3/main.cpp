#include <iostream>

bool substr(char* a, char* b) {
    int i = 0;
    bool res = false;
    while (*(a+i) != '\0') {
        if (*(b) == *(a+i)) {
            int j = 0;
            res = true;
            while (*(b + j) != '\0') {
                if (*(b + j) == *(a + i)) {
                    i++;
                    j++;
                } else {
                    i += j;
                    res = false;
                    break;
                }
            }
        } else i++;
    }
    return res;
}

int main() {
    std::cout << "Task 3" << std::endl;
    std::cout << std::endl;

    char* a = "Hello world";

    char* b = "wor";

    char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c);
    return 0;
}
