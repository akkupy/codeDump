#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Bank 
{
public:
    int acc_no;
    string name, type;
    float balance;

    Bank() : acc_no(0) {}

    void create() 
    {
        static int nxtacc = 1;
        acc_no = nxtacc++;
        cout << "\nEnter Your Full Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "\nSelect Account Type:" << endl;
        cout << "1. Current Account" << endl;
        cout << "2. Savings Account" << endl;
        cout << "Enter your choice: ";
        int typeChoice;
        cin >> typeChoice;

        if (typeChoice == 1)
        {
            type = "Current";
        }
        else if (typeChoice == 2)
        {
            type = "Savings";
        }
        else
        {
            cout << "\nInvalid Option. Please Try Again.\n";
            return;
        }

        cout << "\nEnter Your Initial Deposit: Rs. ";
        cin >> balance;
        cout << "\nYour Account was Successfully Created with Account Number: " << acc_no << endl << endl;
    }

    void deposit()
    {
        float amount;
        cout << "\nEnter the Amount You want to Deposit: Rs. ";
        cin >> amount;
        balance += amount;
        cout << "Hey " << name << ", Your Balance is: Rs. " << balance << endl << endl;
    }

    void withdraw() 
    {
        float amount;
        cout << "\nEnter the Amount You want to Withdraw: Rs. ";
        cin >> amount;
        if (amount > balance) 
        {
            cout << "Insufficient funds" << endl;
        } 
        else 
        {
            balance -= amount;
        }
        cout << "Hey " << name << ", Your balance is: Rs. " << balance << endl << endl;
    }

    void display() 
    {
        cout << "\n\nAccount Number: " << acc_no << endl;
        cout << "Name: " << name << endl;
        cout << "Account Type: " << type << endl;
        cout << "Balance: Rs. " << balance << endl << endl;
    }
};

class curr_acct : public Bank 
{
public:
    void updatecur() 
    {
        if (balance < 10000) 
        {
            cout << "Your account doesn't meet the minimum balance.\n A service charge of Rs. 250 will be deducted from your account." << endl;
            balance -= 250;
            cout << "Please deposit money by cash or by cheque.\nIf you are out of cheque leaves from your chequebook, contact an employee to provide you with a new chequebook.";
        } 
        else 
        {
            cout << "Your account meets the minimum balance.\nNo service charge imposed." << endl;
        }
        display();
    }

    void chequebook(Bank* accounts[], int numAccounts) 
    {
        cout << "\nChequeBook Facilities Menu:\n";
        cout << "1. Withdraw with Cheque" << endl;
        cout << "2. Send Money to Another Account with Cheque" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                withdraw();
                break;

            case 2:
                int receiverAccNo;
                float amount;
                cout << "\nEnter the Receiver's Account Number: ";
                cin >> receiverAccNo;

                if (receiverAccNo >= 1 && receiverAccNo <= numAccounts && receiverAccNo != acc_no && accounts[receiverAccNo - 1] != nullptr) 
                {
                    cout << "\nEnter the Amount to Send: Rs. ";
                    cin >> amount;

                    if (amount <= balance) 
                    {
                        balance -= amount;
                        accounts[receiverAccNo - 1]->balance += amount;
                        cout << "\nMoney sent successfully!\n" << endl;
                    } 
                    else 
                    {
                        cout << "\nInsufficient funds in your account.\n" << endl;
                    }
                } 
                else 
                {
                    cout << "\nInvalid Receiver's Account Number.\n" << endl;
                }
                break;

            default:
                cout << "\nInvalid choice.\n" << endl;
        }
    }
};

class sav_acc : public Bank
{
public:
    void updatesav()
    {   
        float interest, t;
        cout << "\nCalculating Interest:" << endl << endl;
        cout << "Rate of Interest is 6.8% and interest is compounded quarterly.\n" << endl;
        cout << "Please Enter the Time Period of Investment (in years, use decimal if months): "<< endl;
        cin >> t;
        interest = balance * pow((1+ 0.068/4), (4 * t)) - balance;
        cout << "\nYour Interest is = Rs. " << interest << endl;
        balance += interest;
        display();
    }
};

int main() 
{
    Bank* accounts[10];

    int choice1, choice2;

    for (int i = 0; i < 10; i++) 
    {
        accounts[i] = nullptr;
    }

    while (true) 
    {
        cout << "\n\n*** Taz Bank Ltd. Banking App ***\n\n";
        cout << "1. Create a New Account" << endl;
        cout << "2. Deposit to an Existing Account" << endl;
        cout << "3. Withdraw from an Existing Account" << endl;
        cout << "4. Account Information Display Menu" << endl;
        cout << "5. Update Account" << endl;
        cout << "6. ChequeBook Facilities (Only For Current Accounts)" << endl;
        cout << "7. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice1;

        switch (choice1) 
        {
            case 1:
                int i;
                for (i = 0; i < 10; i++) 
                {
                    if (accounts[i] == nullptr) 
                    {
                        accounts[i] = new Bank();
                        accounts[i]->create();
                        break;
                    }
                }
                if (i == 10) 
                {
                    cout << "\nCannot create more accounts. The limit is reached." << endl;
                }
                break;

            case 2:
                int acc_no;
                cout << "\nEnter Your Account Number: ";
                cin >> acc_no;
                if (acc_no >= 1 && acc_no <= 10 && accounts[acc_no - 1] != nullptr) 
                {
                    accounts[acc_no - 1]->deposit();
                } 
                else 
                {
                    cout << "\nAccount Doesn't Exist!" << endl;
                }
                break;

            case 3:
                cout << "\nEnter Your Account Number: ";
                cin >> acc_no;
                if (acc_no >= 1 && acc_no <= 10 && accounts[acc_no - 1] != nullptr) 
                {
                    accounts[acc_no - 1]->withdraw();
                } 
                else 
                {
                    cout << "\nAccount Doesn't Exist!" << endl;
                }
                break;

            case 4:
                cout << "\n*** Account Information ***\n";
                cout << "1. Display Information of an Account" << endl;
                cout << "2. Display Information of All Accounts" << endl;
                cout << "3. Back to Main Menu" << endl;
                cout << "\nEnter your choice: ";
                cin >> choice2;

                switch (choice2) 
                {
                    case 1:
                        cout << "\nEnter Your Account Number: ";
                        cin >> acc_no;
                        if (acc_no >= 1 && acc_no <= 10 && accounts[acc_no - 1] != nullptr)
                        {
                            accounts[acc_no - 1]->display();
                        } 
                        else 
                        {
                            cout << "\nAccount Doesn't Exist!" << endl;
                        }
                        break;

                    case 2:
                        for (i = 0; i < 10; i++)
                        {
                            if (accounts[i] != nullptr)
                            {
                                accounts[i]->display();
                            }
                        }
                        break;

                    case 3:
                        break;

                    default:
                        cout << "\nInvalid choice in Account Information Menu. Please select a valid option.\n" << endl;
                }
                break;
            
            case 5:
                cout << "\nPlease Enter Your Account Number: ";
                cin >> i;
                if (accounts[i - 1] != nullptr)
                {
                    if (accounts[i - 1]->type == "Current")
                    {
                        static_cast<curr_acct*>(accounts[i - 1])->updatecur();
                    } 
                    else if (accounts[i - 1]->type == "Savings")
                    {
                        static_cast<sav_acc*>(accounts[i - 1])->updatesav();
                    }
                }
                break;

            case 6:
                cout << "\nPlease Enter Your Account Number: ";
                cin >> i;
                if (accounts[i - 1] != nullptr && accounts[i - 1]->type == "Current")
                {
                    static_cast<curr_acct*>(accounts[i - 1])->chequebook(accounts, 10);
                }
                else
                {
                    cout << "\nInvalid choice. Chequebook facilities are only available for Current Accounts.\n" << endl;
                }
                break;

            case 7:
                cout << "\n\nGoodbye User!! Hope to See You Soon." << endl;
                for (i = 0; i < 10; i++)
                {
                    delete accounts[i];
                }
                return 0;

            default:
                cout << "\nInvalid choice. Please select a valid option.\n" << endl;
        }
    }
}
