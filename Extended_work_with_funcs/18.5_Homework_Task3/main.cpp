#include <iostream>

int num_ways(int num_steps, int max_length=3) {
    if (num_steps < 0)
        return 0;
    else if (num_steps == 0) {
        return 1;
    } else {
        int count_lengths = 0;
        for (int i = max_length; i > 0; i--)
            count_lengths += (num_ways(num_steps - i, max_length));
        return count_lengths;
    }
}


int main() {
    std::cout << "Task 2" << std::endl;
    std::cout << std::endl;

    int num_steps, max_l_jump;

    std::cout << "Enter the number of steps on the stairs: " << std::endl;
    std::cin >> num_steps;

    std::cout << "Enter the maximum jump length: " << std::endl;
    std::cin >> max_l_jump;

    std::cout << "Number of ways the rabbit can jump up to the " << num_steps << " step with maximum jump length = " << max_l_jump <<
    " is " << num_ways(num_steps, max_l_jump) << std::endl;
    return 0;
}