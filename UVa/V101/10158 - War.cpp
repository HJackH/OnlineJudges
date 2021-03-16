#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define en(k) (k + n)
const int MAXN = 2e4 + 5;

int n, boss[MAXN];

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    if (boss[a] > boss[b]) {
        swap(a, b);
    }
    boss[a] += boss[b];
    boss[b] = a;
}

bool areF(int a, int b) {
    int af = find(a);
    int ae = find(en(a));
    int bf = find(b);
    int be = find(en(b));
    return af == bf && ae == be;
}

bool areE(int a, int b) {
    int af = find(a);
    int ae = find(en(a));
    int bf = find(b);
    int be = find(en(b));
    return af == be && ae == bf;
}

bool setF(int a, int b) {
    if (areE(a, b)) {
        return false;
    }
    uni(a, b);
    uni(en(a), en(b));
    return true;
}

bool setE(int a, int b) {
    if (areF(a, b)) {
        return false;
    }
    uni(a, en(b));
    uni(b, en(a));
    return true;
}

int main() { IOS
    cin >> n;
    for (int i = 0; i < (n << 1); i++) {
        boss[i] = -1;
    }

    int c, x, y;
    while (cin >> c >> x >> y && (c || x || y)) {
        switch(c) {
        case 1:
            cout << (setF(x, y) ? "" : "-1\n");
            break;
        case 2:
            cout << (setE(x, y) ? "" : "-1\n");
            break;
        case 3:
            cout << (areF(x, y) ? "1\n" : "0\n");
            break;
        case 4:
            cout << (areE(x, y) ? "1\n" : "0\n");
            break;
        default:
            break;
        }
    }
}