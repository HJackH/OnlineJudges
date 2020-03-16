#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 20;

int n, q, wnt, kase = 0;
vector<int> li(MAXN);

int main() {
    while (cin >> n >> q && n && q) {
        for (int i = 0; i < n; i++) {
            cin >> li[i];
        }
        sort(li.begin(), li.begin() + n);

        cout << "CASE# " << ++kase << ":\n";
        for (int i = 0; i < q; i++) {
            cin >> wnt;
            auto it = find(li.begin(), li.begin() + n, wnt);
            if (it == li.begin() + n) {
                cout << wnt << " not found\n";
            } else {
                cout << wnt << " found at " << it - li.begin() + 1 << '\n';
            }
        }
    }
}
