#include <bits/stdc++.h>
using namespace std;

string input, table = " `1234567890-=qwertyuiop[]asdfghjkl;'\\zxcvbnm,./";

int main() {
    while (getline(cin, input)) {
        int leni = input.length();

        size_t found;
        for (int i = 0; i < leni; i++) {
            if (input[i] == ' ') {
                cout << ' ';
                continue;
            }
            char tmp = tolower(input[i]);
            found = table.find(tmp);
            cout << table[found - 2];
        }
        cout << '\n';
    }
}
