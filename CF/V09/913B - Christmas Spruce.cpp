#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1000 + 5;

int n;
vector<int> G[MAXN];

bool dfs(int u) {
    int cnt = 0;
    for (auto v : G[u]) {
        if (G[v].empty()) {
            ++cnt;
        } else if (!dfs(v)) {
            return false;
        }
    }
    return cnt >= 3 || G[u].empty();
}

int main() {
    IOS

    cin >> n;
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        G[p].push_back(i);
    }

    if (dfs(1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}