#include <bits/stdc++.h>
using namespace std;

int n, a[5];
map<string, int> M;

int main() {
    while (cin >> n && n) {
        M.clear();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[j];
            }
            sort(a, a + 5);

            string tmp;
            for (int j = 0; j < 5; j++) {
                tmp += to_string(a[j]);
            }

            auto it = M.find(tmp);
            if (it == M.end()) {
                M[tmp] = 1;
            } else {
                M[tmp]++;
            }
        }

        int ans = 0, now = 0;
        for (auto i = M.begin(); i != M.end(); i++) {
            if (i -> second > now) {
                now = i -> second;
                ans = now;
            } else if (i -> second == now) {
                ans += i -> second;
            }
        }
        cout << ans << endl;
    }
}