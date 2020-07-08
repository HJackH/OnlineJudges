#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long p, q;
vector<long long> num[30];

void solve(int l, long long now) {
    if (l > 17) {
        return;
    }
    num[l].push_back(now);
    solve(l + 1, now * 10 + 1);
    solve(l + 1, now * 10 + 2);
}

int main() {
    solve(0, 0);

    int T, kase = 0;
    cin >> T;
    while (T--) {
        cin >> p >> q;
        q = (1LL << q);

        long long ansMin = INF, ansMax = -1;
        for (auto i : num[p]) {
            if (i % q == 0) {
                ansMin = min(ansMin, i);
                ansMax = max(ansMax, i);
            }
        }

        cout << "Case " << ++kase << ": ";
        if (ansMin == INF && ansMax == -1) {
            cout << "impossible\n";
        } else if (ansMin == ansMax) {
            cout << ansMin << '\n';
        } else {
            cout << ansMin << ' ' << ansMax << '\n';
        }
    }
}