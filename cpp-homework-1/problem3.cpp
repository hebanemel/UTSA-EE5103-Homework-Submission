#include <iostream>     // Header: input/output tools
#include <vector>
int main()
{
  std::vector<int> numbers;
  int digit;
  
  while(digit != -1){
    std::cout << "Enter a number (Enter -1 to stop): ";
    std::cin >> digit;
    numbers.push_back(digit); // add entered digit to the vector "numbers"
    
    // Print the numbers in the vector
    int num;
    std::cout << "The numbers entered are: ";
    
    for (num : numbers) {
      std::cout << num << " ";

      // sum of the numbers
      int sum = 0;
      sum += num;   // accumulation
    }

    // average of the numbers
    double average;
    average = <double>(sum) / numbers.size();
    std::cout << "Average: " << average << std::endl;
  }
    return 0;
}