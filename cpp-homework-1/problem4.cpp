#include <iostream>
#include <vector>

int main()
{
    // Built-in array
    int arr[5] = {1, 2, 3, 4, 5};

    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Print original values
    std::cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    } 
    std::cout << std::endl;

    std::cout << "Vector: ";
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Double each element
    for (int i = 0; i < 5; i++) {
        arr[i] = arr[i] * 2;
        vec[i] = vec[i] * 2;
    }
    std::cout << std::endl;

    // Print updated values
    std::cout << "Updated array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Updated vector: ";
    for (int i = 0; i < 5; i++) {
        std::cout << vec[i] << " ";
    }
    
    return 0;
}
