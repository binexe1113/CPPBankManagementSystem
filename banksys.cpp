#include "banksys.h"
#include<cstdlib>
#include<string>
#include <iostream>
using namespace std;

void BankAccount::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cin.ignore(); // To clear newline from input buffer

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Account Type (Savings/Current): ";
    getline(cin, accountType);

    cout << "Enter Initial Balance: ";
    cin >> balance;
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
            cin.ignore(); // Clear newline from input buffer
            getline(cin, name);
        }
        cout<<"Do you want to modify the account type? (yes/no): ";
        std::string modifyType;
        std::cin >> modifyType;
        if (modifyType == "yes") {
            cout << "Enter new account type (Savings/Current): ";
            cin.ignore(); // Clear newline from input buffer
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

