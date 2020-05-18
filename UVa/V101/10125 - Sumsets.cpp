#include <bits/stdc++.h>
using namespace std;

int n, arr[1000 + 5];
set<int> S;

int main() {
    while (cin >> n && n) {
        S.clear();
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            S.insert(arr[i]);
        }
        sort(arr, arr + n);

        bool flag = false;
        int ans;
        for (int d = n - 1; d >= 0 && !flag; d--) {
            for (int a = 0; a < n && !flag; a++) {
                for (int b = a + 1; b < n && !flag; b++) {
                    int c = arr[d] - arr[a] - arr[b];
                    if (arr[d] == c || arr[a] == c || arr[b] == c || a == d || b == d) {
                        continue;
                    }
                    if (S.count(c)) {
                        flag = true;
                        ans = arr[d];
                    }
                }
            }
        }

        if (flag) {
            cout << ans << '\n';
        } else {
            cout << "no solution\n";
        }
    }
}