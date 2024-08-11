#include <iostream>
#include <string>

class Toy {
public:

    Toy(const std::string& name) : name_(name) {}

    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }

    std::string getName() const {
        return name_;
    }

private:
    std::string name_;
};

class Dog {
public:
    void getToy(const std::shared_ptr<Toy>& toy) {
        if (favorite_toy == toy) {
            std::cout << "I already have this toy." << std::endl;
        } else if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy." << std::endl;
        } else {
            favorite_toy = toy;
            std::cout << "Dog picked up the toy: " << toy->getName() << std::endl;
        }
    }

    void dropToy() {
        if (favorite_toy) {
            std::cout << "Dog dropped the toy: " << favorite_toy->getName() << std::endl;
            favorite_toy.reset();
        } else {
            std::cout << "Nothing to drop." << std::endl;
        }
    }

private:
    std::shared_ptr<Toy> favorite_toy;
};

int main() {
    std::shared_ptr<Toy> toy_1 = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> toy_2 = std::make_shared<Toy>("Bone");

    Dog dog_1;
    Dog dog_2;

    dog_1.getToy(toy_1);  // Dog1 подбирает игрушку "Ball"
    dog_2.getToy(toy_1);  // Dog2 пытается подобрать ту же игрушку, но она уже у Dog1

    dog_1.dropToy();     // Dog1 бросает игрушку "Ball"
    dog_2.getToy(toy_1);  // Dog2 теперь может подобрать игрушку "Ball"

    dog_2.getToy(toy_2);  // Dog2 подбирает игрушку "Bone"
    dog_1.getToy(toy_2);  // Dog1 пытается подобрать игрушку "Bone", но она уже у Dog2

    dog_2.dropToy();     // Dog2 бросает игрушку "Bone"
    dog_1.getToy(toy_2);  // Dog1 теперь может подобрать игрушку "Bone"

    return 0;
}
