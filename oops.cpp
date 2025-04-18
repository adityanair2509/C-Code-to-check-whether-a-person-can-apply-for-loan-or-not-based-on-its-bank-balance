#include <iostream>
#include <string>
using namespace std;

// Base class
class BankAccount {
protected:
    string owner;
    double balance;

public:
    // Constructor
    BankAccount(string ownerName, double initialBalance) {
        owner = ownerName;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << endl;
    }

    // Method to withdraw money
    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". Remaining balance: " << balance << endl;
        }
    }

    // Method to display account information
    virtual void display() {
        cout << "Account owner: " << owner << ", Balance: " << balance << endl;
    }

    // Method to check loan eligibility
    bool isEligibleForLoan() {
        return balance >= 5000;  // Minimum balance required for loan eligibility
    }

    // Method to calculate the maximum loan amount
    double calculateMaxLoan() {
        // Let the maximum loan amount be 5 times the balance
        return balance * 5;
    }

    // Method to calculate loan interest (simple interest for simplicity)
    double calculateLoanInterest(double loanAmount, double interestRate, int years) {
        return loanAmount * interestRate * years;
    }
};

// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string ownerName, double initialBalance, double rate)
        : BankAccount(ownerName, initialBalance), interestRate(rate) {}

    // Method to apply interest to savings
    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied. New balance: " << balance << endl;
    }

   
    void display() override {
        cout << "Savings Account of " << owner << ", Balance: " << balance
             << ", Interest rate: " << interestRate * 100 << "%" << endl;
    }
};

int main() {
    string ownerName;
    double initialBalance, depositAmount, loanAmount;
    int loanDuration;
    const double interestRate = 0.08;  // 8% interest rate for loan

    // Take account information from the user
    cout << "Enter account owner's name: ";
    getline(cin, ownerName);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create a BankAccount object with user input
    BankAccount userAccount(ownerName, initialBalance);

    // Display account details
    userAccount.display();

    // Take deposit amount from the user
    cout << "Enter the amount to deposit: ";
    cin >> depositAmount;

    // Deposit money
    userAccount.deposit(depositAmount);

    // Display updated account details
    userAccount.display();

    // Check if the user is eligible for a loan
    if (userAccount.isEligibleForLoan()) {
        cout << "You are eligible for a loan!" << endl;

        // Calculate and display the maximum loan amount
        double maxLoan = userAccount.calculateMaxLoan();
        cout << "The maximum loan you can get is: " << maxLoan << endl;

        
        cout << "Enter the loan amount you want to apply for: ";
        cin >> loanAmount;

        if (loanAmount > maxLoan) {
            cout << "Sorry, you can't apply for a loan amount greater than " << maxLoan << endl;
        } else {
            // Take loan duration from the user
            cout << "Enter the loan duration in years: ";
            cin >> loanDuration;

            // Calculate and display the interest on the loan
            double interest = userAccount.calculateLoanInterest(loanAmount, interestRate, loanDuration);
            cout << "For a loan amount of " << loanAmount << " over " << loanDuration << " years, the interest will be: " << interest << endl;
            cout << "Total amount to repay: " << loanAmount + interest << endl;
        }
    } else {
        cout << "Sorry, you are not eligible for a loan. Minimum balance required is 5000." << endl;
    }

    return 0;
}
