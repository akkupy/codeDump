#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

class BankAccount {
public:
    BankAccount(const std::string& accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds.");
        }
        balance -= amount;
    }

private:
    std::string accountNumber;
    double balance;
};

void saveAccounts(const std::vector<BankAccount>& accounts) {
    std::ofstream file("bank_accounts.txt");
    if (!file) {
        throw std::runtime_error("Unable to open the file for writing.");
    }

    for (const BankAccount& account : accounts) {
        file << account.getAccountNumber() << " " << account.getBalance() << "\n";
    }
}

int main() {
    std::vector<BankAccount> accounts;

    // Load account data from a file (if it exists)
    std::ifstream file("bank_accounts.txt");
    if (file) {
        std::string accountNumber;
        double balance;

        while (file >> accountNumber >> balance) {
            accounts.emplace_back(accountNumber, balance);
        }
    }

    while (true) {
        std::cout << "\nBanking System Menu:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string accountNumber;
            double initialBalance;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;
            accounts.emplace_back(accountNumber, initialBalance);
            saveAccounts(accounts);
            std::cout << "Account created successfully.\n";
        } else if (choice == 2) {
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    account.deposit(amount);
                    saveAccounts(accounts);
                    std::cout << "Deposit successful. New balance: " << account.getBalance() << "\n";
                    break;
                }
            }
        } else if (choice == 3) {
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;

            for (BankAccount& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    try {
                        account.withdraw(amount);
                        saveAccounts(accounts);
                        std::cout << "Withdrawal successful. New balance: " << account.getBalance() << "\n";
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << "\n";
                    }
                    break;
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
