#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 50;

int T, n, k, a[MAXN], ans[MAXN], ansTmp[MAXN];

bool check(long long w) {
    memset(ansTmp, 0, sizeof(ansTmp));
    long long sum = 0;
    int kTmp = k;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > w) {
            return false;
        }
        if ((sum + a[i] > w || i + 1 < kTmp) && kTmp > 0) {
            sum = a[i];
            ansTmp[--kTmp]++;
        } else {
            sum += a[i];
            ansTmp[kTmp]++;
        }
    }
    
    if (kTmp == 1) {
        copy(ansTmp, ansTmp + k + 1, ans);
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> T;
    while (T--) {
        long long L = 0, R = 1, M;

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            R += a[i];
        }

        L = R / k - 1;
        while (L < R) {
            M = L + (R - L) / 2;
            if (check(M)) {
                R = M;
            } else {
                L = M + 1;
            }
        }

        int now = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = ans[i]; j >= 1; j--) {
                cout << a[now++];
                if (i != k || j != 1) {
                    cout << ' ';
                }
            }

            if (i != k) {
                cout << "/ ";
            } else {
                cout << '\n';
            }
        }
    }
}
