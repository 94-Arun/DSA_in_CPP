#include <iostream>

int main() {
    double num1, num2, num3;

    // Prompt the user for input
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    // Incorrectly calculates the average due to a logical error
    double average = num1 + num2 + num3 / 3.0;

    // Displays the incorrect result
    std::cout << "The average is: " << average << std::endl;

    return 0;
}