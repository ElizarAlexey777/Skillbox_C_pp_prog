#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void TimerEnd(std::tm timer) {
  std::time_t start_t = std::time(nullptr);
  std::tm *start_tt = localtime(&start_t);
  std::tm start{};
  start.tm_sec = start_tt->tm_sec;
  start.tm_min = start_tt->tm_min;
  while (timer.tm_sec > 0 or timer.tm_min > 0) {
    std::time_t now_t = std::time(nullptr);
    std::tm *now = localtime(&now_t);
    if (now->tm_sec > start.tm_sec or now->tm_min > start.tm_min) {
      timer.tm_sec -= 1;
      std::cout << timer.tm_min << ":" << timer.tm_sec << std::endl;
      std::time_t start_t = std::time(nullptr);
      std::tm *start_tt = localtime(&start_t);
      start.tm_sec = start_tt->tm_sec;
      start.tm_min = start_tt->tm_min;
    }
  }
  std::cout << "DING! DING! DING!" << std::endl;
}

int main() {
    std::cout << "Timer program" << std::endl << std::endl;

    std::tm timer{};

    std::cout << "Enter the time for the timer: (min:sec)" << std::endl;
    std::cin >> std::get_time(&timer,"%M:%S");
    TimerEnd(timer);
}
