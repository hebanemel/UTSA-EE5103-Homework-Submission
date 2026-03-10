/*
IPO Outline

Input:
- Integer sensor readings entered by the user
- Input continues until the sentinel value -1 is entered

Process:
- For each input value:
    • Check if the value is within the valid range [0, 500]
    • If valid:
        - Update count of valid readings
        - Update minimum value
        - Update maximum value
        - Add value to sum
- After input ends:
    • Compute the average using sum / count

Output:
- If no valid readings were entered:
      "No valid data."
- Otherwise print:
      • Number of valid readings
      • Minimum value
      • Maximum value
      • Average (formatted to 1 decimal place)
*/

#include <iostream>
#include <iomanip>
#include <climits> // used for INT_MAX and INT_MIN so min/max start at extreme values

// Function prototypes (declared here so main() knows about them before they are defined)
bool isValid(int value);

void updateStats(int value, 
                int& count, 
                int& minVal, 
                int& maxVal, 
                double& sum);

double computeAverage(int count, 
                      double sum);

void printSummary(int count, 
                  int minVal, 
                  int maxVal, 
                  double avg);
                  
int main()
{
    int value;              // variable to store each sensor reading
    int count = 0;          // number of valid readings
    int minVal = INT_MAX;   // start with the largest possible int
    int maxVal = INT_MIN;   // start with the smallest possible int
    double sum = 0;         // used to compute the average later

    // keep reading values until the user enters -1
    while (true)
    {
        std::cin >> value;

        // -1 signals the end of input
        if (value == -1)
            break;

        // only process the value if it is within the valid range
        if (isValid(value))
        {
            updateStats(value, count, minVal, maxVal, sum);
        }
    }

    // if no valid values were entered
    if (count == 0)
    {
        std::cout << "No valid data." << std::endl;
    }
    else
    {
        // compute the average using the helper function
        double avg = computeAverage(count, sum);

        // print the final results
        printSummary(count, minVal, maxVal, avg);
    }

    return 0;
}

// checks if the sensor reading is in the valid range [0,500]
bool isValid(int value)
{
    return (value >= 0 && value <= 500);
}

// updates the statistics every time we get a valid value
void updateStats(int value, 
                int& count, 
                int& minVal, 
                int& maxVal, 
                double& sum)
{   
  // check if this value is the new minimum
  if (value < minVal)
      minVal = value;

  // check if this value is the new maximum
  if (value > maxVal)
      maxVal = value;

  // add value to sum for average calculation
  sum += value;

  // increase the number of valid readings
  count++;
}

// calculates the average of all valid readings
double computeAverage(int count, double sum)
{
    return sum / count;
}

// prints the final summary statistics
void printSummary(int count, int minVal, int maxVal, double avg)
{
    std::cout << "Valid readings: " << count << std::endl;
    std::cout << "Minimum: " << minVal << std::endl;
    std::cout << "Maximum: " << maxVal << std::endl;

    // format average to 1 decimal place
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average: " << avg << std::endl;
}