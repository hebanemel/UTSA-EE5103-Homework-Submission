#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

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

    std::vector<std::string> words{
        std::istream_iterator<std::string>(infile),
        std::istream_iterator<std::string>()
    };

    std::transform(words.begin(), words.end(), words.begin(),
        [](std::string word) {
            word.erase(
                std::remove_if(word.begin(), word.end(),
                    [](unsigned char c) {
                        return std::ispunct(c);
                    }),
                word.end()
            );

            std::transform(word.begin(), word.end(), word.begin(),
                [](unsigned char c) {
                    return std::tolower(c);
                });

            return word;
        });

    words.erase(
        std::remove_if(words.begin(), words.end(),
            [](const std::string& s) {
                return s.empty();
            }),
        words.end()
    );

    int totalWords = words.size();

    int longWords = std::count_if(words.begin(), words.end(),
        [](const std::string& s) {
            return s.size() >= 6;
        });

    std::sort(words.begin(), words.end());

    auto endUnique = std::unique(words.begin(), words.end());
    words.erase(endUnique, words.end());

    int uniqueWords = words.size();

    std::cout << "Total number of words: " << totalWords << '\n';
    std::cout << "Number of unique words: " << uniqueWords << '\n';
    std::cout << "Number of words with length >= 6: " << longWords << '\n';

    return 0;
}