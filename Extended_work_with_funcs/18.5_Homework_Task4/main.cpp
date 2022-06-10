#include <iostream>

void evendigits(long long number, int& ans) {
    if (number == 0 and ans == 0) {
        ans = 1;
    } else if (number != 0) {
        if (number % 2 == 0) ans += 1;
        evendigits(number / 10, ans);
    }
}

int main() {
    std::cout << "Task 4" << std::endl;
    std::cout << std::endl;

    long long number;
    int ans;

    std::cout << "Enter a long-long number: " << std::endl;
    std::cin >> number;

    evendigits(number, ans);

    std::cout << "The number of even digits in the long-long number: " << ans << std::endl;

    return 0;
}
