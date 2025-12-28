#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int choice;
    time_t startTime, endTime;
    bool running = false;

    do {
        cout << "\n===== STOPWATCH =====\n";
        cout << "1. Start\n";
        cout << "2. Stop\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!running) {
                    startTime = time(0);
                    running = true;
                    cout << "Stopwatch Started...\n";
                } else {
                    cout << "Stopwatch already running!\n";
                }
                break;

            case 2:
                if (running) {
                    endTime = time(0);
                    running = false;
                    cout << "Stopwatch Stopped.\n";
                    cout << "Elapsed Time: "
                         << difftime(endTime, startTime)
                         << " seconds\n";
                } else {
                    cout << "Stopwatch not running!\n";
                }
                break;

            case 3:
                cout << "Exiting Stopwatch...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
