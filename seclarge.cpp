#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x;
    long long largest = LLONG_MIN, secondLargest = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x != largest && x > secondLargest) {
            secondLargest = x;
        }
    }

    if (secondLargest == LLONG_MIN) cout << -1;
    else cout << secondLargest;

    return 0;
}
