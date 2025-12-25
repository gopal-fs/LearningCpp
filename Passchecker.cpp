#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string password;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    cout << "===== PASSWORD STRENGTH CHECKER =====\n";
    cout << "Enter Password: ";
    cin >> password;

    if (password.length() < 8) {
        cout << "Password is WEAK ❌ (Minimum 8 characters required)\n";
        return 0;
    }

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }

    if (hasUpper && hasLower && hasDigit && hasSpecial) {
        cout << "Password is STRONG ✅\n";
    }
    else if ((hasUpper || hasLower) && hasDigit) {
        cout << "Password is MEDIUM ⚠️\n";
    }
    else {
        cout << "Password is WEAK ❌\n";
    }

    return 0;
}
