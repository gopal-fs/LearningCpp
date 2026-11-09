
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    if (n == 0) {
        cout << "Binary: 0";
        return 0;
    }

    string binary = "";

    while (n > 0) {
        int remainder = n % 2;
        binary += to_string(remainder);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    cout << "Binary: " << binary << endl;

    return 0;
}
