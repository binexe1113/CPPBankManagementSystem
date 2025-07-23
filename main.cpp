#include<iostream>
#include<string>
#include "banksys.h"
using namespace std;

int main(){
    cout << "Welcome to the Bank Management System!" << endl;
    bool continueProgram = true;

    do{
        BankAccount account;
        int choice;

        cout << "1. Create Account" << endl;
        cout << "2. Show Account Details" << endl;
        cout << "3. Modify Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";

        choice = getint();

        switch(choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.showAccount();
                break;
            case 3:
                account.modify();
                break;
            case 4: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            }
            case 5: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 6:
                cout << "Exiting the system." << endl;
                continueProgram = false;
                break;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }while(continueProgram);
    return 0;
}