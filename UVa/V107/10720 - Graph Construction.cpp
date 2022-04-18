#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;

int n;
int a[MAXN];

bool sol() {
    for (int i = 0; i < n; i++) {
        sort(a + i, a + n, greater<int>());
        if (i + a[i] >= n) {
            return false;
        }
        for (int j = i + 1; j <= i + a[i]; j++) {
            a[j]--;
            if (a[j] < 0) {
                return false;
            }
        }
    }
    return a[n - 1] == 0;
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (sol()) {
            cout << "Possible\n";
        } else {
            cout << "Not possible\n";
        }
    }
}