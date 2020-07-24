#include <bits/stdc++.h>
using namespace std;

// 0.040s StarBurst

#define lowbit(k) (k & -k)
const int MAXN = 1e5 + 5;

int n, k, a_neg[MAXN], a_zero[MAXN], tree_neg[MAXN], tree_zero[MAXN];
string ans;

void update(int x, int val) {
    int deltaNeg = 0, deltaZero = 0;
    //negative num
    if (!a_neg[x] && val < 0) {         // + -> -
        deltaNeg = 1;
    } else if (a_neg[x] && val >= 0) {  // - -> +
        deltaNeg = -1;
    }
    //zero num
    if (!a_zero[x] && val == 0) {       // !0 -> 0
        deltaZero = 1;
    } else if (a_zero[x] && val != 0) { // 0 -> !0
        deltaZero = -1;
    }

    //no update
    if (!deltaNeg && !deltaZero) {
        return;
    }

    a_neg[x] += deltaNeg;
    a_zero[x] += deltaZero;
    for (; x <= n; x += lowbit(x)) {
        if (deltaNeg) {
            tree_neg[x] += deltaNeg;
        }
        if (deltaZero) {
            tree_zero[x] += deltaZero;
        }
    }
}

char query(int l, int r) {
    int negCnt = 0, zeroCnt = 0;
    for (int i = r; i > 0; i -= lowbit(i)) {
        negCnt += tree_neg[i];
        zeroCnt += tree_zero[i];
    }
    for (int i = l - 1; i > 0; i -= lowbit(i)) {
        negCnt -= tree_neg[i];
        zeroCnt -= tree_zero[i];
    }
    if (zeroCnt) {
        return '0';
    }
    if (negCnt & 1) {
        return '-';
    } else {
        return '+';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            a_neg[i] = a_zero[i] = tree_neg[i] = tree_zero[i] = 0;
        }

        int num;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            update(i, num);
        }

        char mode;
        int x, y;
        ans.clear();
        for (int i = 0; i < k; i++) {
            cin >> mode >> x >> y;
            if (mode == 'C') {
                update(x, y);
            } else {
                ans += query(x, y);
            }
        }
        cout << ans << '\n';
    }
}