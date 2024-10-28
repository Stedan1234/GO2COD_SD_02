#include <iostream>  // Include input-output library for std::cin and std::cout
#include <limits>     // For std::numeric_limits to handle input errors

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract the second number from the first
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide the first number by the second, with error handling for division by zero
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero is not allowed.\n";
        return std::numeric_limits<double>::quiet_NaN(); // Return "Not a Number" to signal an error
    }
    return a / b;
}

// Function to display menu and get the user's operation choice
char getOperation() {
    char op;
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> op;
    return op;
}

// Function to get a valid numeric input from the user
double getNumber() {
    double num;
    while (true) { // Loop until valid input is given
        std::cout << "Enter a number: ";
        std::cin >> num;

        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a valid number.\n";
        } else {
            return num;
        }
    }
}

int main() {
    char choice;
    do {
        // Get two numbers from the user
        double num1 = getNumber();
        double num2 = getNumber();

        // Get the desired operation
        char op = getOperation();

        // Perform the operation based on the user's choice
        double result;
        switch (op) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                std::cout << "Invalid operation. Please try again.\n";
                continue; // Skip to the next iteration if the operation is invalid
        }

        // Display the result
        std::cout << "Result: " << result << "\n";

        // to ask if the user wants to perform another calculation
        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y'); // Continue until the user chooses to exit

    std::cout << "Goodbye!\n"; // Exit message
    return 0;
}
