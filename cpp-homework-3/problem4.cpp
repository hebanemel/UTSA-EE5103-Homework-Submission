#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class TextCollection {
private:
    // Shared ownership of the vector.
    // The custom deleter logs a message when the last owner is destroyed.
    std::shared_ptr<std::vector<std::string>> data;

    static std::shared_ptr<std::vector<std::string>> createSharedVector() {
        return std::shared_ptr<std::vector<std::string>>(
            new std::vector<std::string>,
            [](std::vector<std::string>* p) {
                std::cout << "Shared vector is being deallocated.\n";
                delete p;
            }
        );
    }

public:
    TextCollection() : data(createSharedVector()) {}

    TextCollection(const std::string& filename) : data(createSharedVector()) {
        std::ifstream infile(filename);
        std::string word;

        while (infile >> word) {
            data->push_back(word);
        }
    }

    void addWord(const std::string& word) {
        data->push_back(word);
    }

    void removeWord(const std::string& word) {
        data->erase(
            std::remove(data->begin(), data->end(), word),
            data->end()
        );
    }

    void printAll() const {
        for (const auto& word : *data) {
            std::cout << word << " ";
        }
        std::cout << '\n';
    }
};

int main() {
    {
        TextCollection tc1;
        tc1.addWord("apple");
        tc1.addWord("banana");

        TextCollection tc2 = tc1; // shared ownership

        std::cout << "tc1: ";
        tc1.printAll();

        std::cout << "tc2: ";
        tc2.printAll();

        tc2.addWord("orange");

        std::cout << "After tc2 adds orange:\n";
        std::cout << "tc1: ";
        tc1.printAll();
        std::cout << "tc2: ";
        tc2.printAll();

        std::cout << "Leaving inner scope...\n";
    }

    // Custom deleter message appears here, after the last owner is gone.
    std::cout << "Program ending.\n";

    return 0;
}