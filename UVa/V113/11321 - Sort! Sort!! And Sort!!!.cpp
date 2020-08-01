#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

int n, m, arr[MAXN];

bool cmp(int a, int b) {
    int am = a % m, bm = b % m; 
    if (am != bm) {
        return am < bm;
    }
    bool aodd = (a & 1), bodd = (b & 1);
    if (aodd && bodd) {
        return a > b;
    } else if (!aodd && !bodd) {
        return a < b;
    } else {
        return aodd;
    }
}

int main() {
    while (cin >> n >> m) {
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << '\n';
        }
    }
}