#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int s, b, l, r, L[MAXN], R[MAXN];

void init() {
    for (int i = 1; i <= s; i++) {
        L[i] = i - 1;
        R[i] = i + 1;
    }
}

void sokill(int ll, int rr) {
    int ltmp = L[ll], rtmp = R[rr];
    R[L[ll]] = rtmp;
    L[R[rr]] = ltmp;
}

int main() {
    while (cin >> s >> b && s && b) {
        init();

        for (int i = 0; i < b; i++) {
            cin >> l >> r;

            if (L[l] > 0) {
                cout << L[l] << " ";
            } else {
                cout << "* ";
            }
            if (R[r] <= s) {
                cout << R[r] << endl;
            } else {
                cout << '*' << endl;
            }

            sokill(l, r);
        }
        
        cout << '-' << endl;
    }
}
