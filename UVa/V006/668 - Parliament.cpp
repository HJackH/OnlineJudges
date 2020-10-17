#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1000;

vector<int> sum(MAXN + 5);

int main() { IOS
    sum[2] = 2;
    for (int i = 3; i <= MAXN; i++) {
        sum[i] = sum[i - 1] + i;
    }

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int wnt = upper_bound(sum.begin() + 2, sum.begin() + MAXN + 1, n) - sum.begin();
        
        int remain = n - sum[wnt - 1], last = 0;
        for (int i = 2, first = 1; i < wnt; i++) {
            if (!last && (i + remain >= wnt)) {
                last = i + remain;
                continue;
            }
            if (!first) {
                cout << ' ';
            }
            first = 0;
            cout << i;
        }
        if (last) {
            cout << ' ' << last;
        }
        
        cout << '\n';
        if (T) {
            cout << '\n';
        }
    }
}