#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 5e5 + 5;

int n, value[26 + 5], p[2 * MAXN], sum[MAXN];

void Manacher(const string &s) {
    string st = "@#";
    for (char c : s) {
        st += c;
        st += '#';
    }
    st += '$';
    int id = 0, mx = 0;
    for (int i = 1; i < st.length() - 1; i++) {
        p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
        for (; st[i - p[i]] == st[i + p[i]]; p[i]++);
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
    }
}

int main() {
    IOS
    string s;
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 26; i++) {
            cin >> value[i];
        }
        cin >> s;
        n = s.length();
        //prefix sum
        sum[0] = value[s[0] - 'a'];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + value[s[i] - 'a'];
        }
        Manacher(s);

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {   //cut
            int tmp = 0;
            if ((p[i + 2] - 1) == (i + 1)) {
                tmp += sum[i];
            }
            if ((p[i + n + 2] - 1) == (n - i - 1)) {
                tmp += sum[n - 1] - sum[i];
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
}