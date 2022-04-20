#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string s;
int cnt[256];

int main() { IOS
    while (getline(cin, s)) {
        memset(cnt, 0, sizeof(cnt));
        for (const auto &c : s) {
            ++cnt[c];
        }
        
        int mx = 0;
        string ans;
        for (char i = 'A'; i <= 'Z'; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ans.clear();
                ans += i;
            } else if (cnt[i] == mx) {
                ans += i;
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ans.clear();
                ans += i;
            } else if (cnt[i] == mx) {
                ans += i;
            }
        }
        cout << ans << " " << mx << '\n';
    }
}