#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1000 + 5;

int n, a[MAXN];

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);

        int i, time = 0;
        for (i = n - 1; i >= 3; i -= 2) {
            int x = a[1] + a[0] + a[i] + a[1];
            int y = a[i - 1] + a[0] + a[i] + a[0];
            time += min(x, y);
        }

        if (i == 2) {
            time += a[1] + a[0] + a[2];
        } else if (i == 1) {
            time += a[1]; 
        } else if (i == 0) {
            time += a[0];
        }

        cout << time << '\n';

        for (i = n - 1; i >= 3; i -= 2) {
            int x = a[1] + a[0] + a[i] + a[1];
            int y = a[i - 1] + a[0] + a[i] + a[0];
            if (x < y) {
                cout << a[0] << ' ' << a[1] << '\n';
                cout << a[0] << '\n';
                cout << a[i - 1] << ' ' << a[i] << '\n';
                cout << a[1] << '\n';
            } else {
                cout << a[0] << ' ' << a[i - 1] << '\n';
                cout << a[0] << '\n';
                cout << a[0] << ' ' << a[i] << '\n';
                cout << a[0] << '\n';
            }
        }

        if (i == 2) {
            cout << a[0] << ' ' << a[1] << '\n';
            cout << a[0] << '\n';
            cout << a[0] << ' ' << a[2] << '\n';
        } else if (i == 1) {
            cout << a[0] << ' ' << a[1] << '\n';
        } else if (i == 0) {
            cout << a[0] << '\n';
        }

        if (T) {
            cout << '\n';
        }
    }
}