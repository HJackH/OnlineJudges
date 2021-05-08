#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 2000;

int now, color[MAXN];
string s;

void build(int x) {
    switch (s[now++]) {
    case 'p':
        for (int i = 1; i <= 4; i++) {
            build(x * 4 + i);
        }
        break;

    case 'f':
        color[x] = 1;
        break;
    
    default:
        break;
    }
}

int dfs(int x, int lv) {
    if (lv == 5) {
        return color[x];
    }
    if (color[x]) {
        return 1024 / (1 << (lv << 1));
    }

    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        sum += dfs(x * 4 + i, lv + 1);
    }
    return sum;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        memset(color, 0, sizeof(color));
        cin >> s;
        now = 0;
        build(0);

        cin >> s;
        now = 0;
        build(0);

        cout << "There are " << dfs(0, 0) << " black pixels.\n";
    }
}