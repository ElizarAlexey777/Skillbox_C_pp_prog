#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Branch {
public:
    Branch* parent;
    std::vector<Branch*> children;
    std::string elf_name;

    Branch(Branch* p = nullptr) : parent(p), elf_name("") {}

    ~Branch() {
        for (Branch* child : children) {
            delete child;
        }
    }

    void addChild(Branch* child) {
        children.push_back(child);
    }

    Branch* findElf(const std::string& name) {
        if (elf_name == name) {
            return this;
        }
        for (Branch* child : children) {
            Branch* result = child->findElf(name);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }

    int countSiblings() {
        if (!parent) {
            return 0;
        }
        int count = 0;
        for (Branch* sibling : parent->children) {
            if (sibling != this && !sibling->elf_name.empty()) {
                ++count;
            }
        }
        return count;
    }
};

void generateTree(Branch* root) {
    int big_branches_num = rand() % 3 + 3;
    for (int i = 0; i < big_branches_num; ++i) {
        Branch* big_branch = new Branch(root);
        int medium_branches_num = rand() % 2 + 2;
        for (int j = 0; j < medium_branches_num; ++j) {
            Branch* medium_branch = new Branch(big_branch);
            big_branch->addChild(medium_branch);
        }
        root->addChild(big_branch);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<Branch*> trees(5);
    for (int i = 0; i < 5; ++i) {
        trees[i] = new Branch();
        generateTree(trees[i]);
    }

    for (Branch* tree : trees) {
        std::vector<Branch*> stack = { tree };
        while (!stack.empty()) {
            Branch* current = stack.back();
            stack.pop_back();
            std::cout << "Enter elf name for house: ";
            std::string name;
            std::getline(std::cin, name);
            if (name != "None") {
                current->elf_name = name;
            }
            for (Branch* child : current->children) {
                stack.push_back(child);
            }
        }
    }

    std::cout << "Enter the name of the elf to find: ";
    std::string elf_to_found;
    std::getline(std::cin, elf_to_found);

    for (Branch* tree : trees) {
        Branch* elfBranch = tree->findElf(elf_to_found);
        if (elfBranch) {
            std::cout << "The elf " << elf_to_found << " has " << elfBranch->countSiblings() << " neighbors on the same big branch.\n";
            return 0;
        }
    }

    std::cout << "Elf not found.\n";

    for (Branch* tree : trees) {
        delete tree;
    }

    return 0;
}
