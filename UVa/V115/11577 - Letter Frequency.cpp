#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, cnt[26];
    cin >> T;
    string s;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        memset(cnt, 0, sizeof(cnt));
        for (char &c : s) {
            if (isalpha(c)) {
                cnt[tolower(c) - 'a']++;
            }
        }

        int mx = 0;
        for (int i = 0; i < 26; i++) {
            mx = max(mx, cnt[i]);
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == mx) {
                cout << char('a' + i);
            }
        }
        cout << "\n";
    }
}