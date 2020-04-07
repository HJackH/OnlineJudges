#include <bits/stdc++.h>
using namespace std;

int sz;
string input;
set<string> S;

bool isPa(string str) {
    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] == str[r]) {
            l++;
            r--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    while (getline(cin, input)) {
        S.clear();
        sz = input.length();
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j + i - 1 < sz; j++) {
                string tmp = input.substr(j, i);
                if (isPa(tmp)) {
                    S.insert(tmp);
                }
            }
        }

        cout << "The string '" << input << "' contains " << S.size() << " palindromes.\n";
    }
}