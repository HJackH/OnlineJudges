#include <bits/stdc++.h>
using namespace std;

string input;
int odd, even;

int main() {
    while (cin >> input && input != "0") {
        odd = 0;
        even = 0;

        for (int i = 0; i < input.length(); i++) {
            if (i & 1) {
                odd += input[i] - '0';
            } else {
                even += input[i] - '0';
            }
        }

        cout << input << " is ";
        if ((odd - even) % 11) {
            cout << "not ";
        }
        cout << "a multiple of 11.\n";
    }
}
