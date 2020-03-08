#include <bits/stdc++.h>
using namespace std;

int T, n, m, value;
char c;
string tmp;

int main() {
    cin >> T;
    while (T--) {
        map<char, int> M;
        set<char> S;
        int ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> c >> value;
            M[c] = value;
            S.insert(c);
        }

        cin >> m;
        getline(cin, tmp);
        for (int i = 0; i < m; i++) {
            getline(cin, tmp);
            int len = tmp.length();
            for (int j = 0; j < len; j++) {
                if (S.count(tmp[j]) != 0) {
                    ans += M[tmp[j]];
                } else {
                    M[tmp[j]] = 0;
                    S.insert(tmp[j]);
                }
            }
        }

        printf("%.2lf$\n", (double)ans / 100.0);
    }
}
