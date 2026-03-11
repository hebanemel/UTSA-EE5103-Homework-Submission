#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

// helper functions
void processLine(const std::string& line, std::map<std::string, int>& wordCounts);
void printTopWords(const std::map<std::string, int>& wordCounts, int topN);

int main()
{
    std::string filename;

    // 1. Prompt user for filename
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream file(filename);

    // check if file opened successfully
    if (!file)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }

    std::map<std::string, int> wordCounts;
    std::string line;

    // 2. Read file line-by-line
    while (std::getline(file, line))
    {
        processLine(line, wordCounts);
    }

    file.close();

    // 5. Print the 5 most frequent words
    printTopWords(wordCounts, 5);

    return 0;
}


// helper function that extracts words from a line
void processLine(const std::string& line, std::map<std::string, int>& wordCounts)
{
    std::istringstream iss(line);
    std::string word;

    // 3. extract words from the line
    while (iss >> word)
    {
        // 4. increase count for that word
        wordCounts[word]++;
    }
}


// helper function to print top N frequent words
void printTopWords(const std::map<std::string, int>& wordCounts, int topN)
{
    // convert map to vector so we can sort it
    std::vector<std::pair<std::string, int>> words(wordCounts.begin(), wordCounts.end());

    // sort by frequency (descending)
    std::sort(words.begin(), words.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    std::cout << "\nTop " << topN << " most frequent words:\n";

    for (int i = 0; i < topN && i < words.size(); i++)
    {
        std::cout << words[i].first << " : " << words[i].second << std::endl;
    }
}