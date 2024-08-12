#include <iostream>
#include <string>

class Toy {
public:
    Toy(const std::string& name) : name_(name) {}

    std::string getName() const {
        return name_;
    }

    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped" << std::endl;
    }

private:
    std::string name_;
};

class shared_ptr_toy {
public:
    shared_ptr_toy() : toy_ptr_(nullptr), ref_count_(nullptr) {}

    explicit shared_ptr_toy(const std::string& name) {
        toy_ptr_ = new Toy(name);
        ref_count_ = new int(1);
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        toy_ptr_ = other.toy_ptr_;
        ref_count_ = other.ref_count_;
        if (ref_count_) {
            ++(*ref_count_);
        }
    }

    ~shared_ptr_toy() {
        release();
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this == &other) {
            return *this;
        }

        release();

        toy_ptr_ = other.toy_ptr_;
        ref_count_ = other.ref_count_;
        if (ref_count_) {
            ++(*ref_count_);
        }
        return *this;
    }

    void reset() {
        release();
        toy_ptr_ = nullptr;
        ref_count_ = nullptr;
    }

    Toy* get() const {
        return toy_ptr_;
    }

    int use_count() const {
        return ref_count_ ? *ref_count_ : 0;
    }

    std::string getToyName() const {
        return toy_ptr_ ? toy_ptr_->getName() : "Nothing";
    }

private:
    Toy* toy_ptr_;
    int* ref_count_;

    void release() {
        if (ref_count_) {
            --(*ref_count_);
            if (*ref_count_ == 0) {
                delete toy_ptr_;
                delete ref_count_;
            }
        }
    }
};

shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(name);
}

int main() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");

    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
        << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_02 = toy_03;

    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
        << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    toy_01.reset();

    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
        << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;

    return 0;
}