// author-akshat khatri
// date-01-10-2023
// explaining various bitwise operators in cpp
#include <iostream>

int main()
{
    int num1, num2, choice, result;

    do
    {
        // Display menu
        std::cout << "Bitwise Operator Menu:\n";
        std::cout << "1. Bitwise AND (&)\n";
        std::cout << "2. Bitwise OR (|)\n";
        std::cout << "3. Bitwise XOR (^)\n";
        std::cout << "4. Bitwise NOT (~)\n";
        std::cout << "5. Left Shift (<<)\n";
        std::cout << "6. Right Shift (>>)\n";
        std::cout << "7. Swap Two Numbers using XOR\n"; // New option
        std::cout << "0. Exit\n";

        // Get user choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Exit if the choice is 0
        if (choice == 0)
        {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }

        // Get two integers from the user
        std::cout << "Enter the first integer: ";
        std::cin >> num1;
        std::cout << "Enter the second integer: ";
        std::cin >> num2;

        // Perform the selected bitwise operation
        switch (choice)
        {
        case 1:
            // Bitwise AND
            result = num1 & num2;
            break;
        case 2:
            // Bitwise OR
            result = num1 | num2;
            break;
        case 3:
            // Bitwise XOR
            result = num1 ^ num2;
            break;
        case 4:
            // Bitwise NOT
            result = ~num1;
            break;
        case 5:
            // Left Shift
            result = num1 << num2;
            break;
        case 6:
            // Right Shift
            result = num1 >> num2;
            break;
        case 7:
            // Swap Two Numbers using XOR
            num1 = num1 ^ num2;
            num2 = num1 ^ num2;
            num1 = num1 ^ num2;
            result = 0; // Set result to 0 for display purposes
            break;
        default:
            // Invalid choice
            std::cout << "Invalid choice. Please enter a valid option.\n";
            continue; // Skip the rest of the loop and start over
        }

        // Display the result
        std::cout << "Result: " << result << "\n\n";

    } while (true); // Infinite loop; user can exit by choosing option 0

    return 0;
}
