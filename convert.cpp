
#include <iostream>
#include <string>
using namespace std;

string ones[] = {
    "", "One", "Two", "Three", "Four",
    "Five", "Six", "Seven", "Eight", "Nine"
};

string teens[] = {
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string tens[] = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string convertBelowHundred(int n) {
    if (n < 10)
        return ones[n];

    if (n < 20)
        return teens[n - 10];

    string result = tens[n / 10];

    if (n % 10 != 0)
        result += " " + ones[n % 10];

    return result;
}

string convertBelowThousand(int n) {
    if (n < 100)
        return convertBelowHundred(n);

    string result = ones[n / 100] + " Hundred";

    if (n % 100 != 0)
        result += " " + convertBelowHundred(n % 100);

    return result;
}

string numberToWords(int n) {
    if (n == 0)
        return "Zero";

    string result = "";

    if (n >= 100000) {
        result += convertBelowThousand(n / 100000) + " Lakh";
        n %= 100000;

        if (n > 0) result += " ";
    }

    if (n >= 1000) {
        result += convertBelowThousand(n / 1000) + " Thousand";
        n %= 1000;

        if (n > 0) result += " ";
    }

    if (n > 0)
        result += convertBelowThousand(n);

    return result;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0 || n > 9999999) {
        cout << "Number out of range";
        return 0;
    }

    cout << numberToWords(n) << endl;

    return 0;
}
