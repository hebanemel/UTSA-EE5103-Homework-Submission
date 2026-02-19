#include <iostream>     // Header: input/output tools
int main()
{
  int temp1, temp2, temp3;

  
  std::cout << "Enter three(3) temperatures: "; 
  std::cin >> temp1, temp2, temp3; //statement. We do not add << std::endl; at the of the prompt bcause we still want the user to type on the same line

  // Calculate and print average
  float average = (temp1 + temp2 + temp3)/3;
  std::cout << "Average temperature: " << average << std::endl;

  // Printing the state of temperature based on avg.
  if (average < 50){
    std::cout << "The average temperature is cold" << std::endl;
  }

  else if (average > 80){
    std::cout << "The average temperature is hot" << std::endl;
  }

  else {
    std::cout << "The average temperature is moderate" << std::endl;
  }
    return 0;
}