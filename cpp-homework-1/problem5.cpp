#include <iostream>   
#include <vector>    

int main()
{
    std::vector<int> numbers;   
    int choice = 0;             

    // Loop continues until user chooses 4 (Quit)
    while (choice != 4)
    {
        // Display menu
        std::cout << "1. Enter number" << std::endl;
        std::cout << "2. Display all numbers" << std::endl;
        std::cout << "3. Display largest number" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Option 1: Enter number
        if (choice == 1)
        {
            int num;
            std::cout << "Enter a number: ";
            std::cin >> num;

            numbers.push_back(num);  // Add number to vector
        }

        // Option 2: Display all numbers
        else if (choice == 2)
        {
          
           std::cout << "Numbers: ";

           // Loop through vector and print each number
           for (int i = 0; i < numbers.size(); i++)
           {
               std::cout << numbers[i] << " ";
          }

           std::cout << std::endl;
            
        }

        // Option 3: Display largest number
        else if (choice == 3)
        {
            
          // Assume first number is the largest
           int largest = numbers[0];
         // Compare remaining numbers
           for (int i = 1; i < numbers.size(); i++)
           {                 if (numbers[i] > largest)
               {
                   largest = numbers[i];  // Update largest
            }
         }

          std::cout << "Largest number: " << largest << std::endl;
            
        }

        // Option 4: Quit
        else if (choice == 4)
        {
            std::cout << "Goodbye!\n";
        }

    }

    return 0;   
}
