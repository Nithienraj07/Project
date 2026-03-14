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

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited successfully!" << endl;
        } else {
            cout << "Invalid amount!"<< endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!"<<endl;
        }
        else if (amount <= 0) {
            cout << "Invalid amount!"<<endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful!"<<endl;
        }
    }

    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {

    BankAccount *account = NULL;
    int mainChoice;

    do {
        cout << "    MAIN MENU   " << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Existing Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {

            int accNo;
            double initialBalance;

            cout << "Enter account number: ";
            cin >> accNo;

            cout << "Enter initial amount: ";
            cin >> initialBalance;

            account = new BankAccount(accNo, initialBalance);

            cout << "Account created successfully!" << endl;

        }

        else if (mainChoice == 2) {

            if (account == NULL) {
                cout << "No account found! Please create account first." << endl;
                continue;
            }

            int accNo;
            cout << "Enter account number: ";
            cin >> accNo;

            if (accNo != account->getAccountNumber()) {
                cout << "Invalid account number!" << endl;
                continue;
            }

            int choice;
            double amount;

            do {
                cout << " TRANSACTION MENU "<<endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Exit" << endl;
                cout << "Choose option: ";
                cin >> choice;

                switch (choice) {

                case 1:
                    cout << "Enter amount: ";
                    cin >> amount;
                    account->deposit(amount);
                    break;

                case 2:
                    cout << "Enter amount: ";
                    cin >> amount;
                    account->withdraw(amount);
                    break;

                case 3:
                    account->displayBalance();
                    break;

                case 4:
                    cout << "Exiting transaction menu." << endl;
                    break;

                default:
                    cout << "Invalid choice!" << endl;
                }

            } while (choice != 4);
        }

    } while (mainChoice != 3);

    cout << "Thank you for using ATM!\n";

    return 0;
}