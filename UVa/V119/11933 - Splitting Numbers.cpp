#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n;

int main() {
    IOS
    while (cin >> n && n) {
        unsigned a = 0, b = 0, d, cnt = 0;
        for (int i = 0; i <= 31; i++) {
            d = 1 << i;
            if (n & d) {
                cnt++;
                if (cnt & 1) {
                    a = a | d;
                } else {
                    b = b | d;
                }
            }
        }
        cout << a << ' ' << b << '\n';
    }
}