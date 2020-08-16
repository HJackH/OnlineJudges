#include <bits/stdc++.h>
using namespace std;

string input;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> input;
        int n = input.length();
        string ans = input;
        input += input;
        for (int i = 1; i < n; i++) {
            ans = min(ans, input.substr(i, n));
        }
        cout << ans << '\n';
    }
}