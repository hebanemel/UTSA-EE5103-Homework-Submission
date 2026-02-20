#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int digit;

    while (true) {
        std::cout << "Enter a number (Enter -1 to stop): ";
        std::cin >> digit;

        if (digit == -1) {
            break;
        }

        numbers.push_back(digit);
    }

    // Print numbers
    std::cout << "The numbers entered are: ";
    for (int num : numbers) {
        std::cout << num << " " << std::endl;

    }
    
    // Calculate sum
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }

    std::cout << "Sum: " << sum << std::endl;

    // Calculate average
    
   double average = sum / numbers.size();
   std::cout << "Average: " << average << std::endl;
    

    return 0;
}
