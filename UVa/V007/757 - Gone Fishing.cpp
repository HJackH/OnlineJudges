#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25 + 5;

int n, h;
vector<int> fish(MAXN), d(MAXN), t(MAXN);
int ans;
vector<int> ansTime;

void sol() {
    for (int i = 0; i < n; i++) {
        int time = h * 60 - t[i] * 5;
        if (time <= 0) {
            continue;
        }
        int tans = 0;
        vector<int> tfish = fish, ttime(n, 0);
        while (time > 0) {
            int mx = 0, pos = i;
            for (int j = i; j >= 0; j--) {
                if (tfish[j] >= mx) {
                    mx = tfish[j];
                    pos = j;
                }
            }

            tans += mx;

            if (tfish[pos] - d[pos] < 0) {
                tfish[pos] = 0;
            } else {
                tfish[pos] -= d[pos];
            }
            ttime[pos] += 5;
            time -= 5;
        }

        if (tans > ans) {
            ans = tans;
            ansTime = ttime;
        }
    }
}

int main() {
    int first = 1;
    while (cin >> n && n) {
        if (!first) {
            cout << "\n";
        }
        first = 0;

        cin >> h;
        for (int i = 0; i < n; i++) {
            cin >> fish[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> t[i];
            t[i] += t[i - 1];
        }

        ans = -1;
        sol();

        cout << ansTime[0];
        for (int i = 1; i < n; i++) {
            cout << ", " << ansTime[i];
        }
        cout << "\n";
        cout << "Number of fish expected: " << ans << "\n";
    }
}