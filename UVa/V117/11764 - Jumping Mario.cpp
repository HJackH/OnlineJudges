#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 50 + 5;

int n, a[MAXN];

int main() { IOS
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int h = 0, l = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] < a[i]) {
                h++;
            }
            if (a[i - 1] > a[i]) {
                l++;
            }
        }
        cout << "Case " << kase << ": " << h << ' ' << l << '\n';
    }
}