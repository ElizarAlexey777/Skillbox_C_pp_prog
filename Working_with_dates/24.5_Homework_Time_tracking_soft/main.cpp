#include <iostream>
#include <ctime>
#include <vector>

void session(std::vector <std::time_t> & interval, int var = 0) {
    interval[var] = std::time(nullptr);
}

void write_to_status(std::vector <std::time_t> & interval, std::vector <std::pair <std::string, std::tm>> & v_status, const std::string & task){
    auto t = (std::time_t)std::difftime(interval[1],interval[0]);
    std::tm time = *std::localtime(&t);
    v_status.emplace_back(task, time);
    interval[0] = interval[1] = 0;
}

void task_name_inp(std::string & name_task) {
    std::cin.ignore(256, '\n');
    std::cout << "Enter the name of the task you plan to start working on: " << std::endl;
    std::getline(std::cin, name_task);
    std::cout << "Start of task \"" << name_task << "\"" << std::endl;
}

int main() {
    std::cout << "Time tracking software" << std::endl << std::endl;

    std::string operation, task_name;
    std::vector <std::pair<std::string, std::tm>> v_status;
    std::vector <std::time_t> intervals(2);

    while (true) {
        std::cout << "Input command:" << std::endl;
        std::cin >> operation;

        if (operation == "begin"){
            if (intervals[0] == 0) {
                task_name_inp(task_name);
                session(intervals);
            } else {
                session(intervals, 1);
                std::cout << "Task \"" << task_name << "\" has been automatically terminated!" << std::endl;
                write_to_status(intervals, v_status, task_name);
                task_name_inp(task_name);
                session(intervals);
            }
        } else if (operation == "end"){
            if (intervals[0] != 0) {
                session(intervals, 1);
                write_to_status(intervals, v_status, task_name);
            }
        } else if (operation == "status"){
            if (!v_status.empty()) {
                for (const auto & run:v_status) {
                    std::cout << run.first << " - " << run.second.tm_min << " min, " << run.second.tm_sec << " sec" << std::endl;
                }
                if (v_status.back().first != task_name)  std::cout << task_name << " in progress" << std::endl;
            } else std::cout << task_name << " in progress" << std::endl;
        } else if (operation == "exit") break;
    }
}
