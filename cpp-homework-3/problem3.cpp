#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class TextCollection {
private:
    // Shared ownership:
    // Multiple TextCollection objects point to the same vector of strings.
    // The vector stays alive until the last TextCollection using it is destroyed.
    std::shared_ptr<std::vector<std::string>> data;

public:
    // Default constructor: creates an empty shared vector
    TextCollection() : data(std::make_shared<std::vector<std::string>>()) {}

    // Constructor that reads words from a file
    TextCollection(const std::string& filename)
        : data(std::make_shared<std::vector<std::string>>()) {
        std::ifstream infile(filename);
        std::string word;

        while (infile >> word) {
            data->push_back(word);
        }
    }

    // Add a word to the collection
    void addWord(const std::string& word) {
        data->push_back(word);
    }

    // Remove all occurrences of a word from the collection
    void removeWord(const std::string& word) {
        data->erase(
            std::remove(data->begin(), data->end(), word),
            data->end()
        );
    }

    // Print all words in insertion order
    void printAll() const {
        for (const auto& word : *data) {
            std::cout << word << " ";
        }
        std::cout << '\n';
    }
};

int main(int argc, char* argv[]) {
    TextCollection tc1;

    tc1.addWord("apple");
    tc1.addWord("banana");
    tc1.addWord("orange");

    std::cout << "tc1 initially: ";
    tc1.printAll();

    // Shared ownership demonstration:
    // tc2 shares the same underlying vector as tc1
    TextCollection tc2 = tc1;

    tc2.addWord("grape");

    std::cout << "After tc2 adds grape:\n";
    std::cout << "tc1: ";
    tc1.printAll();
    std::cout << "tc2: ";
    tc2.printAll();

    tc1.removeWord("banana");

    std::cout << "After tc1 removes banana:\n";
    std::cout << "tc1: ";
    tc1.printAll();
    std::cout << "tc2: ";
    tc2.printAll();

    

    return 0;
}