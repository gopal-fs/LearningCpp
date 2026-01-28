#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Account {
public:
    int accNo;
    string name;
    double balance;

    Account(int a, string n, double b) : accNo(a), name(n), balance(b) {}
};

class Bank {
    vector<Account> accounts;
    int nextAcc = 1001;

    int findIndex(int accNo) {
        for (int i = 0; i < (int)accounts.size(); i++) {
            if (accounts[i].accNo == accNo) return i;
        }
        return -1;
    }

public:
    void createAccount() {
        string name;
        double deposit;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cin >> deposit;

        if (deposit < 0) deposit = 0;

        accounts.push_back(Account(nextAcc, name, deposit));
        cout << "AccountCreated " << nextAcc << "\n";
        nextAcc++;
    }

    void viewAccount() {
        int accNo;
        cin >> accNo;

        int idx = findIndex(accNo);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }

        cout << accounts[idx].accNo << "\n";
        cout << accounts[idx].name << "\n";
        cout << accounts[idx].balance << "\n";
    }

    void depositMoney() {
        int accNo;
        double amount;
        cin >> accNo >> amount;

        int idx = findIndex(accNo);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }

        if (amount <= 0) {
            cout << "Invalid\n";
            return;
        }

        accounts[idx].balance += amount;
        cout << "Deposited\n";
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cin >> accNo >> amount;

        int idx = findIndex(accNo);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }

        if (amount <= 0) {
            cout << "Invalid\n";
            return;
        }

        if (amount > accounts[idx].balance) {
            cout << "Insufficient\n";
            return;
        }

        accounts[idx].balance -= amount;
        cout << "Withdrawn\n";
    }

    void listAccounts() {
        if (accounts.empty()) {
            cout << "Empty\n";
            return;
        }

        for (auto &a : accounts) {
            cout << a.accNo << " | " << a.name << " | " << a.balance << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Bank bank;
    int choice;

    while (true) {
        cout << "1.Create\n2.View\n3.Deposit\n4.Withdraw\n5.List\n6.Exit\n";
        cin
