#include <stdio.h>

// Initialized the account balance to $1000
double accountBalance = 1000.0;

// Function to display the account balance
void checkBalance() {
    printf("Your account balance is $%.2lf\n", accountBalance);
}

// Function to deposit money
void deposit() {
    double amount;
    printf("Enter the amount to deposit: $");
    scanf("%lf", &amount);

    if (amount > 0) {
        accountBalance += amount;
        printf("Deposit successful. Your new balance is $%.2lf\n", accountBalance);
    } else {
        printf("Invalid amount. Please enter a positive value.\n");
    }
}

// Function to withdraw money
void withdraw() {
    double amount;
    printf("Enter the amount to withdraw: $");
    scanf("%lf", &amount);

    if (amount > 0 && amount <= accountBalance) {
        accountBalance -= amount;
        printf("Withdrawal successful. Your new balance is $%.2lf\n", accountBalance);
    } else if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
    } else {
        printf("Insufficient funds. Your current balance is $%.2lf\n", accountBalance);
    }
}

int main() {
    int choice;

    printf("Welcome to the ATM\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

