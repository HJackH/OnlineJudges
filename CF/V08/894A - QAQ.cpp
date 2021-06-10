#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())

int ans = 0;
string s;

void dfs(int i, int d) {
    if (d == 3) {
        ans++;
        return;
    }
    for (; i < sz(s); i++) {
        if (s[i] == 'Q' && (d == 0 || d == 2)) {
            dfs(i, d + 1);
        } else if (s[i] == 'A' && d == 1) {
            dfs(i, d + 1);
        }
    }
}

int main() { IOS
    cin >> s;
    dfs(0, 0);
    cout << ans << "\n";
}