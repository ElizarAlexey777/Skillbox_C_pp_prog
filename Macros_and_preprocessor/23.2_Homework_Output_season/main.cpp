#include <iostream>

//#define SEASON "Winter"
#define SEASON "Summer"
//#define SEASON "Autumn"
//#define SEASON "Spring"

#ifdef SEASON
int main() {
    std::cout << "Output of the season" << std::endl << std::endl;

    std::cout << "Your season: " << SEASON;
}
#endif
