#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int words = 0, vowels = 0, consonants = 0;

    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);

        if (c >= 'a' && c <= 'z') {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                vowels++;
            else
                consonants++;
        }

        if ((i == 0 && text[i] != ' ') || 
            (text[i] != ' ' && text[i-1] == ' '))
            words++;
    }

    cout << words << endl;
    cout << vowels << endl;
    cout << consonants << endl;

    return 0;
}
