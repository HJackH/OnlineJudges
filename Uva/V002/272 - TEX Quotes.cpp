#include <bits/stdc++.h>
using namespace std;

string input, quo = "\"";
int len;

int main() {
    bool sw = true;

    while (getline(cin, input)) {
        len = input.length();
        for (int i = 0; i < len; i++) {
            if (input[i] == '"') {
                if (sw) {
                    cout << "``";
                    sw = !sw;
                } else {
                    cout << "''";
                    sw = !sw;
                }
            } else {
                cout << input[i];
            }
        }
        cout << '\n';
    }
}
