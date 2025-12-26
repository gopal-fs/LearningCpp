#include <iostream>
using namespace std;

int main() {
    string tasks[50];
    bool completed[50] = {false};
    int taskCount = 0;
    int choice;

    do {
        cout << "\n===== TO-DO LIST APP =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter task: ";
            getline(cin, tasks[taskCount]);
            completed[taskCount] = false;
            taskCount++;
            cout << "Task Added Successfully!\n";
        }

        else if (choice == 2) {
            if (taskCount == 0) {
                cout << "No tasks available!\n";
            } else {
                for (int i = 0; i < taskCount; i++) {
                    cout << i + 1 << ". " << tasks[i];
                    if (completed[i])
                        cout << " [DONE]";
                    cout << endl;
                }
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter task number to mark completed: ";
            cin >> num;

            if (num > 0 && num <= taskCount) {
                completed[num - 1] = true;
                cout << "Task marked as completed\n";
            } else {
                cout << "Invalid task number!\n";
            }
        }

        else if (choice == 4) {
            cout << "Exiting To-Do App...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
