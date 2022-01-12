#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25 + 5;

int n, k, m, a[MAXN];

int go(int pos, int dir, int step) {
    while (step--) {
        do {
            pos = (pos + dir + n - 1) % n + 1; 
        } while (a[pos] == 0);
    }
    return pos;
}

int main() {
    while (~scanf("%d %d %d", &n, &k, &m) && (n || k || m)) {
        for (int i = 1; i <= n; i++) {
            a[i] = 1;
        }
        int left = n;
        int p1 = n, p2 = 1;
        while (left) {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            a[p1] = a[p2] = 0;
            if (p1 == p2) {
                printf("%3d", p1);
                left--;
            } else {
                printf("%3d%3d", p1, p2);
                left -= 2;
            }
            if (left) {
                printf(",");
            }
        }
        printf("\n");
    }
}