#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    while (getline(cin, str)) {
        int ans = 0;
        bool hasAlpha = false;
        for (char c : str) {
            if (isalpha(c)) {
                hasAlpha = true;
            } else if (hasAlpha) {
                hasAlpha = false;
                ans++;
            }
        }
        if (hasAlpha) {
            ans++;
        }
        cout << ans << '\n';
    }
}