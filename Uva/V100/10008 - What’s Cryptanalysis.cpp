#include <bits/stdc++.h>
using namespace std;

struct Alpha {
    char letter;
    int cnt;

    bool operator < (Alpha const &other) const {
        if (cnt > other.cnt) {
            return true;
        } else if (cnt == other.cnt) {
            return letter < other.letter;
        } else {
            return false;
        }
    }
};

int n;
string str;
Alpha alpha[30];

int main() {
    for (int i = 0; i < 26; i++) {
        alpha[i] = (Alpha) {(char)(i + 'A'), 0};
    }

    cin >> n;
    getline(cin, str);
    while (n--) {
        getline(cin, str);
        int len = str.length();

        for (int i = 0; i < len; i++) { 
            if (isalpha(str[i])) {
                alpha[toupper(str[i]) - 'A'].cnt++;
            }
        }
    }

    sort(alpha, alpha + 26);
    for (int i = 0; i < 26 && alpha[i].cnt; i++) {
        cout << alpha[i].letter << ' ' << alpha[i].cnt << endl;
    }
}
