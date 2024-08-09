#include <iostream>
#include <vector>
#include <string>

class Talent {
public:
    virtual std::string getName() const = 0;

    virtual ~Talent() = default;
};


class Swimming : public Talent {
public:
    std::string getName() const override {
        return "Swim";
    }
};

class Dancing : public Talent {
public:
    std::string getName() const override {
        return "Dance";
    }
};

class Counting : public Talent {
public:
    std::string getName() const override {
        return "Count";
    }
};

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
private:
    std::vector<Talent*> talents;

public:
    Dog(const std::string& name) : Animal(name) {}

    ~Dog() {
        for (auto talent : talents) {
            delete talent;
        }
    }

    void addTalent(Talent* talent) {
        talents.push_back(talent);
    }

    void show_talents() const {
        std::cout << "This is " << getName() << " and it has some talents:\n";
        for (const auto& talent : talents) {
            std::cout << "\tIt can \"" << talent->getName() << "\"\n";
        }
    }
};

int main() {
    Dog dog1("Steve");

    dog1.addTalent(new Dancing());
    dog1.addTalent(new Swimming());

    dog1.show_talents();

    return 0;
}
