#include <iostream>

int num_ways(int num_steps) {
    if (num_steps < 0)
        return 0;
    else if (num_steps == 0) {
        return 1;
    } else {
        return (num_ways(num_steps - 3) + num_ways(num_steps - 2) + num_ways(num_steps - 1));
    }
}


int main() {
    std::cout << "Task 2" << std::endl;
    std::cout << std::endl;

    int num_steps;

    std::cout << "Enter the number of steps on the stairs: " << std::endl;
    std::cin >> num_steps;

    std::cout << "Number of ways the rabbit can jump up to the " << num_steps << " step is " << num_ways(num_steps) << std::endl;
    return 0;
}
