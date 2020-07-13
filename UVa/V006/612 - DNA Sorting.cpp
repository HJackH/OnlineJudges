#include <bits/stdc++.h>
using namespace std;

#define lowbit(k) (k & (-k))

const int MAXN = 100 + 5;

struct BIT {
    int cnt[26 + 5];

    void update(int at, int delta) {
        for (; at <= 26; at += lowbit(at)) {
            cnt[at] += delta;
        }
    }

    int query(int at) {
        int ans = 0;
        for (; at > 0; at -= lowbit(at)) {
            ans += cnt[at];
        }
        return ans;
    }

    int getInv(string &x) {
        memset(cnt, 0, sizeof(cnt));

        int ans = 0;
        for (int i = x.length() - 1; i >= 0; i--) {
            ans += query(x[i] - 'A');   //less
            update(x[i] - 'A' + 1, 1);
        }
        return ans;
    }
};

struct DNA {
    string str;
    int id;
    int inv;
    bool operator < (const DNA &other) const {
        if (inv == other.inv) {
            return id < other.id;
        }
        return inv < other.inv;
    }
};

int n, m;
DNA s[MAXN];
BIT bits;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> s[i].str;
            s[i].id = i;
            s[i].inv = bits.getInv(s[i].str);
        }

        sort(s, s + m);
        for (int i = 0; i < m; i++) {
            cout << s[i].str << '\n';
        }
        if (T) {
            cout << '\n';
        }
    }
} 
