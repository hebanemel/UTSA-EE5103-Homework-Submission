#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cctype>

std::string normalizeWord(const std::string& word) {
    std::string result;

    for (char ch : word) {
        if (!std::ispunct(static_cast<unsigned char>(ch))) {
            result += std::tolower(static_cast<unsigned char>(ch));
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::map<std::string, std::set<int>> wordIndex;
    std::string line;
    int lineNumber = 0;

    while (std::getline(infile, line)) {
        ++lineNumber;
        std::string word;

        for (char ch : line) {
            if (std::isspace(static_cast<unsigned char>(ch))) {
                if (!word.empty()) {
                    word = normalizeWord(word);
                    if (!word.empty()) {
                        wordIndex[word].insert(lineNumber);
                    }
                    word.clear();
                }
            } else {
                word += ch;
            }
        }

        if (!word.empty()) {
            word = normalizeWord(word);
            if (!word.empty()) {
                wordIndex[word].insert(lineNumber);
            }
        }
    }

    std::string query;
    while (true) {
        std::cout << "Enter word to search: ";
        if (!(std::cin >> query)) {
            break;
        }

        query = normalizeWord(query);

        auto it = wordIndex.find(query);

        if (it != wordIndex.end()) {
            std::cout << query << " occurs on lines: ";
            for (int num : it->second) {
                std::cout << num << " ";
            }
            std::cout << '\n';
        } else {
            std::cout << query << " does not occur in the file.\n";
        }
    }

    return 0;
}