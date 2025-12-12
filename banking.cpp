#include <iostream>
using namespace std;

int balance = 50000;

void showBalance() {
    cout << "Your Balance Amount is: " << balance << " rs" << endl;
}

void withdraw() {
    int money;
    cout << "Enter Amount You Want to Withdraw: ";
    cin >> money;

    if (money > balance) {
        cout << "Insufficient Funds!" << endl;
        return;
    } else if (money > 0 && money <= balance) {
        balance -= money;
        cout << "Amount Withdrawn Successfully!" << endl;
        char response;
        cout << "Want to View your balance [y/n]? ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            showBalance();
            return;
        } else if (response == 'n' || response == 'N') {
            cout << "Thanks For Using QuickTM!" << endl;
            return;
        } else {
            cout << "Invalid Response." << endl;
            return;
        }
    }
}

void deposit() {
    int depositAmount;
    cout << "Enter Amount You Want to Deposit: ";
    cin >> depositAmount;
    if (depositAmount <= 0) {
        cout << "Enter a positive amount." << endl;
        return;
    }
    balance += depositAmount;
    cout << "Amount Deposited Successfully" << endl;
    char response;
    cout << "Want to View your balance [y/n]? ";
    cin >> response;
    if (response == 'y' || response == 'Y') {
        showBalance();
    } else if (response == 'n' || response == 'N') {
        cout << "Thanks For Using QuickTM!" << endl;
    } else {
        cout << "Invalid Response." << endl;
    }
}

bool continued(char response) {
    if (response == 'y' || response == 'Y') {
        return true;
    } else if (response == 'n' || response == 'N') {
        return false;
    } else {
        cout << "Invalid Response. Assuming 'n' (stop)." << endl;
        return false;              
    }
}

bool promptAndPerformOnce() {
    int userOp;
    cout << "Hello User Select Your Preference [1.withdraw, 2.showbalance, 3.deposit]: ";
    cin >> userOp;

    if (userOp == 1) {
        withdraw();
    } else if (userOp == 2) {
        showBalance();
    } else if (userOp == 3) {
        deposit();
    } else {
        cout << "Please Check Your Preference (choose 1, 2, or 3)." << endl;
    }

    char response;
    cout << "Do you want to Continue the Transaction? [y/n]: ";
    cin >> response;
    return continued(response);
}

int main() {
    cout << "******************WELCOME TO QuickTM*************************" << endl;

    // Loop until user chooses to stop
    while (true) {
        bool keepGoing = promptAndPerformOnce();
        if (!keepGoing) break;
    }

    cout << "Thanks For Using QuickTM, Have a Great Day!" << endl;
    cout << "*******************END***************************" << endl;
    return 0;
}
