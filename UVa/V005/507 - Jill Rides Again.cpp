#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 20000 + 5;

int n, a[MAXN];

int main() { IOS
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }

        int mx = 0, sum = 0, k = 0, ansl = 0, ansr = 0;
        for (int i = 1; i < n; i++) {
            sum += a[i];
            if (sum > mx || (sum == mx && (ansr - ansl < i - k))) {
                ansr = i;
                ansl = k;
                mx = sum;
            }
            if (sum < 0) {
                sum = 0;
                k = i;
            }
        }

        if (mx == 0) {
            cout << "Route " << kase << " has no nice parts\n";
        } else {
            cout << "The nicest part of route " << kase << " is between stops "
                << ansl + 1 << " and " << ansr + 1 << "\n";
        }
    }
}