#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice;
    double amount, total = 0;
    string category;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Expense\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream out("expenses.txt", ios::app);
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Enter category: ";
            cin >> category;
            out << amount << " " << category << endl;
            out.close();
            cout << "Expense Added ✅\n";
        }

        else if (choice == 2) {
            ifstream in("expenses.txt");
            if (!in) {
                cout << "No expenses found!\n";
            } else {
                cout << "\nAmount   Category\n";
                while (in >> amount >> category) {
                    cout << amount << "     " << category << endl;
                }
                in.close();
            }
        }

        else if (choice == 3) {
            ifstream in("expenses.txt");
            total = 0;
            while (in >> amount >> category) {
                total += amount;
            }
            in.close();
            cout << "Total Expense: ₹" << total << endl;
        }

        else if (choice == 4) {
            cout << "Exiting Expense Tracker...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
