#include "banksys.h"
#include<cstdlib>
#include<string>
#include <limits>
#include <iostream>
using namespace std;

void BankAccount::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cin.ignore(); // <--- Clear leftover newline

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Account Type (1.Savings/2.Current): ";
    char type;
    cin >> type;
    cin.ignore(); // <--- Clear newline after reading type

    if(type == '1') {
        accountType = "Savings";
    } else if(type == '2') {
        accountType = "Current";
    } else {
        cout << "Invalid account type. Defaulting to Savings." << endl;
        accountType = "Savings";
    }

    cout << "Enter Initial Balance: ";
    cin >> balance;
    if (balance < 0) {
        cout << "Initial balance cannot be negative. Setting to 0." << endl;
        balance = 0;
    }
    cout<< "Account created successfully!" << endl;
}

void BankAccount::showAccount() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: $" << balance << endl;
}
void BankAccount::modify(){
    cout<<"Do you want to modify the account details? (yes/no): ";
    std::string choice;
    std::cin >> choice;
    if (choice == "yes") {
        cout<<"Do you want to modify the name? (yes/no): ";
        std::string modifyName;
        std::cin >> modifyName;
        if (modifyName == "yes") {
            cout << "Enter new name: ";
            cin.ignore(); // Clear leftover newline
            getline(cin, name);
        }
        cout<<"Do you want to modify the account type? (yes/no): ";
        std::string modifyType;
        std::cin >> modifyType;
        if (modifyType == "yes") {
            cout << "Enter new account type (Savings/Current): ";
            cin.ignore(); // Clear leftover newline
            getline(cin, accountType);
        }
}
    cout << "Account details modified successfully." << endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

void BankAccount::withdraw(double amount){
    if (amount<=0){
        cout << "Withdrawal amount must be positive." << endl;
    } else if (amount > balance) {
        cout << "Insufficient balance for withdrawal." << endl;
    } else {
        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;
        cout<<"Remaining Balance: $" << balance << endl;
    }
}
int BankAccount::getAccountNumber() const {
    return accountNumber;
}
double BankAccount::getBalance() const {
    return balance;
}
std::string BankAccount::getAccountType() const {
    return accountType;
}
//methods
int getint() {
    int value;
    while (true) {
        cout << "Enter an integer: ";
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear(); // clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard any extra input
            return value;
        }
    }
}