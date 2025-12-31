#include <iostream>
using namespace std;

class Contact {
public:
    string name;
    string phone;

    void input() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
    }

    void display() {
        cout << "Name: " << name << ", Phone: " << phone << endl;
    }
};

int main() {
    Contact contacts[50];
    int count = 0;
    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            contacts[count].input();
            count++;
            cout << "Contact Added Successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No contacts available!\n";
            } else {
                for (int i = 0; i < count; i++) {
                    contacts[i].display();
                }
            }
        }

        else if (choice == 3) {
            string searchName;
            bool found = false;

            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, searchName);

            for (int i = 0; i < count; i++) {
                if (contacts[i].name == searchName) {
                    contacts[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Contact Not Found!\n";
        }

        else if (choice == 4) {
            cout << "Exiting Contact Manager...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
