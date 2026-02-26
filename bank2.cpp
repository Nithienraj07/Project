#include <iostream>
using namespace std;

class BankAccount {
    private:
        int accountNumber;
        double balance;

    public:

        BankAccount(int accNo, double initialBalance) {
            accountNumber = accNo;
            balance = initialBalance;
        }

 
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited successfully!" << endl;
            } else {
                cout << "Invalid amount!" << endl;
            }
        }

    
        void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient balance!" << endl;
            } 
            else if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            }
            else {
                balance -= amount;
                cout << "Withdrawal successful!" << endl;
            }
        }

    
        void displayBalance() {
            cout << "Current Balance: " << balance << endl;
        }
};

int main() {
    int accNo;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNo;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accNo, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit" << endl;
        cout << "2. Withdraw" << endl; 
        cout << "3. Check Balance" << endl;
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.displayBalance();
                break;

            case 4:
                cout << "Thank you for using ATM!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}