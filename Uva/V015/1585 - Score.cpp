#include <bits/stdc++.h>
using namespace std;

int T, ans, cnt;
string str;

int main() {
    cin >> T;
    while (T--) {
        cin >> str;
        int len = str.length();
        cnt = 0;
        ans = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == 'O') {
                cnt++;
                ans += cnt;   
            } else {
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
}