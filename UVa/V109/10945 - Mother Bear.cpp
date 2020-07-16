#include <bits/stdc++.h>
using namespace std;

string str;

bool isPa() {
    int l = 0, r = str.length() - 1;
    while (true) {
        while (!isalpha(str[l])) {
            l++;
        }
        while (!isalpha(str[r])) {
            r--;
        }
        if (l > r) {
            break;
        }
        if (toupper(str[l]) != toupper(str[r])) {
            return false;
        } else {
            l++;
            r--;
        }
    }
    return true;
}

int main() {
    while (getline(cin, str) && str != "DONE") {
        if (isPa()) {
            cout << "You won't be eaten!\n";
        } else {
            cout << "Uh oh..\n";
        }
    }
}