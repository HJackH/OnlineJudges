#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 12 + 5;

int t, n, a[MAXN];
int choose[MAXN];
unordered_set<string> vis;

void dfs(int i, int l, int sum) {
    if (sum > t) {
        return;
    }
    if (sum == t) {
        string s;
        for (int i = 1, first = 1; i <= l; i++) {
            if (!first) {
                s += '+';
            }
            first = 0;
            s += to_string(choose[i]);
        }
        if (!vis.count(s)) {
            cout << s << '\n';
            vis.insert(s);
        }
        return;
    }

    for (int j = i + 1; j <= n; j++) {
        choose[l + 1] = a[j];
        dfs(j, l + 1, sum + a[j]);
    }
}

int main() { IOS
    while (cin >> t >> n && n) {
        vis.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cout << "Sums of " << t << ":\n";
        dfs(0, 0, 0);
        if (vis.empty()) {
            cout << "NONE\n";
        }
    }
}