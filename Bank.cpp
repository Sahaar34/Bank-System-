#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string accName, int accNumber) {
        name = accName;
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        } else {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }

    void showBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << name << "\nAccount Number: " << accountNumber << "\nBalance: $" << balance << endl;
    }
};

int main() {
    unordered_map<int, BankAccount> accounts;
    int choice, accNumber;
    string name;
    double amount;

    while (true) {
        cout << "\n=== Banking System Menu ===\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new account number: ";
                cin >> accNumber;
                if (accounts.find(accNumber) == accounts.end()) {
                    accounts[accNumber] = BankAccount(name, accNumber);
                    cout << "Account created successfully.\n";
                } else {
                    cout << "Account number already exists.\n";
                }
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accNumber;
                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[accNumber].deposit(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accNumber;
                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[accNumber].withdraw(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accNumber;
                if (accounts.find(accNumber) != accounts.end()) {
                    accounts[accNumber].showBalance();
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
