#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

bool parseLine(const std::string& line, 
              std::vector<int>& values);
double average(const std::vector<int>& values);

int main(int argc, char* argv[])
{
    // check if filename was given
    if (argc < 2)
    {
        std::cout << "Error: file name missing\n";
        return 1;
    }


    // check if file opened correctly
    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cout << "Error: could not open file\n";
        return 1;
    }

    std::string line;
    int totalLines = 0;
    int validLines = 0;
    int totalInts = 0;

    // read file line by line
    while (std::getline(file, line))
    {
        totalLines++;

        std::vector<int> values;

        // try to parse integers from the line
        if (!parseLine(line, values))
        {
            std::cout << "Warning: invalid data on line "
                      << totalLines << std::endl;
            continue; // skip bad line
        }

        validLines++;
        totalInts += values.size();

        double avg = average(values);

        std::cout << "Line " << totalLines
                  << ": count=" << values.size()
                  << " avg=" << avg
                  << std::endl;
    }

    // final summary
    std::cout << "\nTotal lines processed: " << totalLines << std::endl;
    std::cout << "Total valid lines: " << validLines << std::endl;
    std::cout << "Total integers read: " << totalInts << std::endl;

    return 0;
}


// reads integers from a line
// function to return false if something isn't a number
bool parseLine(const std::string& line, std::vector<int>& values)
{
    std::istringstream iss(line);
    int num;

    while (iss >> num)
    {
        values.push_back(num);
    }

    // if stream failed before reaching end, it means bad data
    if (!iss.eof())
        return false;

    return true;
}


// function to calculate average of numbers in vector
double average(const std::vector<int>& values)
{
    int sum = 0;

    for (int v : values)
    {
        sum += v;
    }

    return (double)sum / values.size();
}