#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXK = 30 + 5;

LL a3[MAXK];

LL qry(LL k, LL row) {
    if ((1 << k) == row) {
        return a3[k];
    }
    if (row <= 0) {
        return 0;
    }

    LL sum = 0, p = 1;
    k--;
    while (row > 0 && k >= 0) {
        LL half = 1LL << k;
        if (row >= half) {
            row -= half;
            sum += a3[k] * p;
            p *= 2;
        }
        k--;
    }
    return sum;
}

int main() {
    a3[0] = 1;
    for (int i = 1; i < MAXK; i++) {
        a3[i] = a3[i - 1] * 3;
    }

    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        LL k, a, b;
        cin >> k >> a >> b;
        LL tot = 1 << k;
        a = tot - a + 1;
        b = tot - b + 1;
        cout << "Case " << kase << ": " << (qry(k, a) - qry(k, b - 1)) << "\n";
    }
}