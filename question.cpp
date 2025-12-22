#include <iostream>
using namespace std;

int main() {
    string questions[5] = {
        "1. C++ was developed by?",
        "2. Which keyword is used to create object?",
        "3. Which loop is entry controlled?",
        "4. Which symbol is used for address?",
        "5. Which file extension is for C++?"
    };

    string options[5][4] = {
        {"A. Dennis Ritchie", "B. Bjarne Stroustrup", "C. James Gosling", "D. Guido"},
        {"A. class", "B. object", "C. new", "D. create"},
        {"A. do-while", "B. while", "C. for", "D. switch"},
        {"A. *", "B. &", "C. #", "D. %"},
        {"A. .c", "B. .java", "C. .cpp", "D. .py"}
    };

    char answers[5] = {'B', 'C', 'C', 'B', 'C'};
    char userAns;
    int score = 0;

    cout << "===== SIMPLE QUIZ APP =====\n";

    for (int i = 0; i < 5; i++) {
        cout << "\n" << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }

        cout << "Enter your answer (A/B/C/D): ";
        cin >> userAns;

        if (toupper(userAns) == answers[i]) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer is " << answers[i] << endl;
        }
    }

    cout << "\nYour Final Score: " << score << "/5\n";

    return 0;
}
