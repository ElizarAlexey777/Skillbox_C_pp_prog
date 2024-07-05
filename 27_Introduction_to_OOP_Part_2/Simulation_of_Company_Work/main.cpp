#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

enum class TaskType { A, B, C };

class Employee {
public:
    std::string name;
    Employee(const std::string& name) : name(name) {}
    virtual ~Employee() = default;
    virtual void receiveTask(TaskType task) {
        std::cout << "Employee " << name << " received task " << static_cast<char>('A' + static_cast<int>(task)) << std::endl;
    }
};

class Worker : public Employee {
public:
    Worker(const std::string& name) : Employee(name) {}
};

class Manager : public Employee {
public:
    std::vector<Worker*> workers;
    Manager(const std::string& name) : Employee(name) {}

    ~Manager() {
        for (auto worker : workers) {
            delete worker;
        }
    }

    void addWorker(Worker* worker) {
        workers.push_back(worker);
    }

    void assignTasks(int seed) {
        std::srand(seed);
        int tasksCount = std::rand() % (workers.size() + 1);
        for (int i = 0; i < tasksCount; ++i) {
            TaskType task = static_cast<TaskType>(std::rand() % 3);
            workers[i]->receiveTask(task);
        }
    }
};

class CEO : public Employee {
public:
    std::vector<Manager*> managers;
    CEO(const std::string& name) : Employee(name) {}

    ~CEO() {
        for (auto manager : managers) {
            delete manager;
        }
    }

    void addManager(Manager* manager) {
        managers.push_back(manager);
    }

    void giveCommand(int command) {
        for (size_t i = 0; i < managers.size(); ++i) {
            int seed = command + i;
            managers[i]->assignTasks(seed);
        }
    }
};

int main() {
    int number_teams, workers_team;
    std::cout << "Enter number of teams: ";
    std::cin >> number_teams;
    std::cout << "Enter number of workers per team: ";
    std::cin >> workers_team;

    CEO ceo("CEO");

    for (int i = 0; i < number_teams; ++i) {
        Manager* manager = new Manager("Manager" + std::to_string(i + 1));
        for (int j = 0; j < workers_team; ++j) {
            Worker* worker = new Worker("Worker" + std::to_string(i + 1) + "_" + std::to_string(j + 1));
            manager->addWorker(worker);
        }
        ceo.addManager(manager);
    }

    std::cout << "Enter commands (end with -1): " << std::endl;
    int command;
    std::cin >> command;
    do {
        ceo.giveCommand(command);
        std::cout << "Enter command: " << std::endl;
        std::cin >> command;
    } while (command != -1);

    return 0;
}
