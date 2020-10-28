#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 12 + 5;

int t, n, a[MAXN];
int choose[MAXN];
vector<vector<int>> ans;
unordered_set<string> vis;

void dfs(int i, int l, int sum) {
    if (sum > t) {
        return;
    }
    if (sum == t) {
        vector<int> tmp;
        for (int i = 1; i <= l; i++) {
            tmp.pb(choose[i]);
        }
        ans.pb(tmp);
        return;
    }

    for (int j = i + 1; j <= n; j++) {
        choose[l + 1] = a[j];
        dfs(j, l + 1, sum + a[j]);
    }
}

int main() { IOS
    while (cin >> t >> n && n) {
        ans.clear();
        vis.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        dfs(0, 0, 0);

        cout << "Sums of " << t << ":\n";
        if (ans.empty()) {
            cout << "NONE\n";
        } else {
            for (auto v : ans) {
                string s;
                int first = 1;
                for (auto i : v) {
                    if (!first) {
                        s += '+';
                    }
                    first = 0;
                    s += to_string(i);
                }
                if (!vis.count(s)) {
                    cout << s << '\n';
                    vis.insert(s);
                }
            }
        }
    }
}