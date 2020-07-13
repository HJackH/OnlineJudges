#include <bits/stdc++.h>
using namespace std;

char mirrorMap[200];
string s;

void buildMap() {
    memset(mirrorMap, 0, sizeof(mirrorMap));
    mirrorMap['A'] = 'A';
    mirrorMap['E'] = '3';
    mirrorMap['H'] = 'H';
    mirrorMap['I'] = 'I';
    mirrorMap['J'] = 'L';
    mirrorMap['L'] = 'J';
    mirrorMap['M'] = 'M';
    mirrorMap['O'] = 'O';
    mirrorMap['S'] = '2';
    mirrorMap['T'] = 'T';
    mirrorMap['U'] = 'U';
    mirrorMap['V'] = 'V';
    mirrorMap['W'] = 'W';
    mirrorMap['X'] = 'X';
    mirrorMap['Y'] = 'Y';
    mirrorMap['Z'] = '5';
    mirrorMap['1'] = '1';
    mirrorMap['2'] = 'S';
    mirrorMap['3'] = 'E';
    mirrorMap['5'] = 'Z';
    mirrorMap['8'] = '8';
}

bool isPa() {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool isMirror() {
    int l = 0, r = s.length() - 1;
    while (l <= r) {
        if (s[r] != mirrorMap[s[l]]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    buildMap();
    while (cin >> s) {
        cout << s << " -- is ";
        if (isPa()) {
            if (isMirror()) {
                cout << "a mirrored palindrome.\n";
            } else {
                cout << "a regular palindrome.\n";
            }
        } else {
            if (isMirror()) {
                cout << "a mirrored string.\n";
            } else {
                cout << "not a palindrome.\n";
            }
        }
        cout << '\n';
    }
}