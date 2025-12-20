#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Student students[50];
    int count = 0;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            students[count].input();
            count++;
            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No students found!\n";
            } else {
                for (int i = 0; i < count; i++) {
                    students[i].display();
                }
            }
        }

        else if (choice == 3) {
            int rollNo;
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].roll == rollNo) {
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found!\n";
        }

        else if (choice == 4) {
            int rollNo;
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].roll == rollNo) {
                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    count--;
                    found = true;
                    cout << "Student Deleted Successfully!\n";
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found!\n";
        }

        else if (choice == 5) {
            cout << "Exiting Program...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
