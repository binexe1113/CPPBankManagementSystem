#include <iostream>
#include <string>
class BankAccount {
private:
    int accountNumber;
    std::string name;
    std::string accountType; // "Savings" or "Current"
    double balance;

public:
    void createAccount();
    void showAccount() const;
    void modify();
    void deposit(double);
    void withdraw(double);
    int getAccountNumber() const;
    double getBalance() const;
    std::string getAccountType() const;
};

//methods implementation
int getint();