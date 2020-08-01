#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

struct Maker {
    string name;
    int l;
    int r;
};

int d;
Maker makers[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> d;
        for (int i = 0; i < d; i++) {
            cin >> makers[i].name >> makers[i].l >> makers[i].r;
        }
        
        int Q, price, cnt;
        string ans;
        cin >> Q;
        while (Q--) {
            cin >> price;
            cnt = 0;
            for (int i = 0; i < d; i++) {
                if (makers[i].l <= price && price <= makers[i].r) {
                    ans = makers[i].name;
                    cnt++;
                    if (cnt >= 2) {
                        break;
                    }
                }
            }
            if (cnt == 1) {
                cout << ans << '\n';
            } else {
                cout << "UNDETERMINED\n";
            }
        }
        if (T) {
            cout << '\n';
        }
    }
}