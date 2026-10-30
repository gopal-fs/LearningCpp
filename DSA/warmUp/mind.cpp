
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Question {
    string question;
    vector<string> options;
    char answer;
};

int main() {

    vector<Question> quiz = {
        {
            "Which language is used for DSA?",
            {"Python", "C++", "HTML", "CSS"},
            'B'
        },
        {
            "What is the time complexity of Binary Search?",
            {"O(N)", "O(N^2)", "O(log N)", "O(1)"},
            'C'
        },
        {
            "Which data structure follows FIFO?",
            {"Stack", "Queue", "Tree", "Graph"},
            'B'
        },
        {
            "Which keyword is used for inheritance in C++?",
            {"extends", "implements", "public", "class"},
            'C'
        },
        {
            "Which algorithm finds the shortest path in an unweighted graph?",
            {"DFS", "BFS", "Merge Sort", "Quick Sort"},
            'B'
        }
    };

    int score = 0;
    int total = quiz.size();

    cout << "================================\n";
    cout << "       C++ QUIZ CHALLENGE       \n";
    cout << "================================\n";

    for (int i = 0; i < total; i++) {

        cout << "\nQuestion " << i + 1 << ": ";
        cout << quiz[i].question << "\n";

        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". "
                 << quiz[i].options[j] << "\n";
        }

        char choice;

        while (true) {
            cout << "\nYour answer: ";
            cin >> choice;

            choice = toupper(choice);

            if (choice >= 'A' && choice <= 'D') {
                break;
            }

            cout << "Invalid option! Choose A, B, C or D.\n";
        }

        if (choice == quiz[i].answer) {
            cout << "Correct answer! +10 points\n";
            score += 10;
        }
        else {
            cout << "Wrong answer!\n";
            cout << "Correct answer: "
                 << quiz[i].answer << "\n";
        }

        cout << "------------------------------\n";
    }

    double percentage = (score * 100.0) / (total * 10);

    cout << "\n========== QUIZ RESULT ==========\n";
    cout << "Total Questions: " << total << "\n";
    cout << "Correct Score: " << score << "/"
         << total * 10 << "\n";
    cout << "Percentage: " << percentage << "%\n";

    if (percentage >= 80) {
        cout << "Excellent performance!\n";
    }
    else if (percentage >= 50) {
        cout << "Good job! Keep practicing.\n";
    }
    else {
        cout << "Keep learning and try again!\n";
    }

    cout << "================================\n";

    return 0;
}
