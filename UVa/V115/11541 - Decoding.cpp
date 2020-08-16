#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string s, ans;

int main() {
    IOS
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> s;
        ans.clear();
        int cnt = 0;
        char tmp = s[0];
        for (char c : s) {
            if (isalpha(c)) {
                ans.insert(ans.end(), cnt, tmp);
                cnt = 0;
                tmp = c;
            } else {
                cnt = cnt * 10 + c - '0';
            }
        }
        ans.insert(ans.end(), cnt, tmp);
        cout << "Case " << kase << ": " << ans << '\n';
    }
}