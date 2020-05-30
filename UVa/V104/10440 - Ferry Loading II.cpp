#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1500;

int T, n, ti, m, arr[MAXN];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> ti >> m;
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }

        int ans1 = 0, ans2 = 0;

        if (n >= m) {
            ans1 = arr[m - 1] + ti;
            ans2 = 1;
        } else if (m % n == 0) {
            for (int i = 0; i < m; i += n) {
                ans1 = max(ans1, arr[i + n - 1]) + 2 * ti;
                ans2++;
            }
            ans1 -= ti; //the last time no return
        } else {
            ans1 = arr[m % n - 1] + 2 * ti;
            ans2++;
            for (int i = m % n; i < m; i += n) {
                ans1 = max(ans1, arr[i + n - 1]) + 2 * ti;
                ans2++;
            }
            ans1 -= ti; //the last time no return
        }

        cout << ans1 << " " << ans2 << '\n';
    }
}