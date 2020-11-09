#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int prices[] = {2, 3, 5, 7};

int toAmt(int x) {
    int ans = 0, now = 100, pre = 0;
    for (int i = 0; i < 3; i++) {
        ans += min(max(0, x / prices[i]), now - pre);
        x -= prices[i] * (now - pre);
        pre = now;
        now *= 100;
    }
    ans += max(0, x / prices[3]);
    return ans;
}

int toCost(int x) {
    int ans = 0, now = 100, pre = 0;
    for (int i = 0; i < 3; i++) {
        ans += min(max(0, x * prices[i]), (now - pre) * prices[i]);
        x -= now - pre;
        pre = now;
        now *= 100;
    }
    ans += max(0, x * prices[3]);
    return ans;
}

int main() { IOS
    int a, b;
    while (cin >> a >> b && (a || b)) {
        int total = toAmt(a);
        int L = 0, R = (total + 1) / 2, mCost, nCost;
        while (L < R) {
            int M = (L + R) / 2;
            mCost = toCost(M);
            nCost = toCost(total - M);
            if (nCost > mCost + b) {
                L = M + 1;
            } else if (nCost < mCost + b) {
                R = M;
            } else {
                break;
            }
        }
        cout << mCost << '\n';        
    }
}