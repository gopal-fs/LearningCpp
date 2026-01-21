#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float divi(int a, int b) {
    return (float)a / b;
}

int main() {
    int choice, x, y;

    do {
        cout << "1.Add\n2.Sub\n3.Mul\n4.Div\n5.Exit\n";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cin >> x >> y;
        }

        switch (choice) {
            case 1: cout << add(x, y); break;
            case 2: cout << sub(x, y); break;
            case 3: cout << mul(x, y); break;
            case 4: 
                if (y != 0) cout << divi(x, y);
                else cout << "Error";
                break;
        }
        cout << endl;

    } while (choice != 5);

    return 0;
}
