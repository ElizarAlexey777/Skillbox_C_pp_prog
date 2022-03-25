#include <iostream>

void burst_the_region(bool field_pupyrka[][12], int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            std::cout << "Bubble with coordinates (" << i << " " << j << "):" << std::endl;
            if (field_pupyrka[i][j]) {
                field_pupyrka[i][j] = false;
                std::cout << "Pop!" << std::endl;
            } else {
                std::cout << "Already been busted" << std::endl;
            }
        }
    }
}

bool check_pupyrka(bool field_pupyrka[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (field_pupyrka[i][j]) {
                return true;
            }
        }
    }
    std::cout << "All the pupyrka bubbles have been burst" << std::endl;
    return false;
}

void pr_field_pupyrka(bool field_pupyrka[][12]) {
    std::cout << std::endl;
    std::cout << "Field of pupyrka: " << std::endl;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (field_pupyrka[i][j]) {
                std::cout << 'o' << ' ';
            } else {
                std::cout << 'x' << ' ';
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    std::cout << "Pupyrka" << std::endl;

    bool field_pupyrka[12][12] = {
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
            {true, true, true, true, true, true, true, true, true, true, true, true},
    };
    bool burst_pupyrka = true;
    int x1, y1, x2, y2;

    pr_field_pupyrka(field_pupyrka);

    while (burst_pupyrka) {
        std::cout << std::endl;
        std::cout << "Enter the coordinates of the beginning of the rectangular region of the burst: (x1 y1)" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Enter the coordinates of the end of the rectangular region of the burst: (x2 y2)" << std::endl;
        std::cin >> x2 >> y2;
        if (x1 < 12 and x1 >= 0 and x2 < 12 and x2 >= 0 and y1 < 12 and y1 >= 0 and y2 < 12 and y2 >= 0 and x1 <= x2 and y1 <= y2) {
            burst_the_region(field_pupyrka, x1, y1, x2, y2);
            pr_field_pupyrka(field_pupyrka);
        } else {
            std::cout << "Please enter correct coordinates" << std::endl;
        }
        burst_pupyrka = check_pupyrka(field_pupyrka);
    }
    return 0;
}
