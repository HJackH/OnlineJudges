#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

struct Item {
    int p;
    int q;
};

int n;
Item a[MAXN];
int w[MAXN];

int sol() {
    for (int i = 0; i < n; i++) {
        w[i] = a[i].p - a[i].q;
    }
    int st = 0;
    while (st < n) {
        int sum = w[st], ed = (st + 1) % n;
        while (ed != st) {
            if (sum < 0) {
                break;
            }
            sum += w[ed];
            ed = (ed + 1) % n;
        }
        if ((sum < 0 && ed == st) || ed < st) {
            return -1;
        } else if (ed == st) {
            return st;
        } else {
            st = ed;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i].p;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].q;
        }

        int ans = sol();
        cout << "Case " << kase << ": ";
        if (ans == -1) {
            cout << "Not possible\n";
        } else {
            cout << "Possible from station " << ans + 1 << "\n";
        }
    }
}