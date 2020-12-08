#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n;

int main() { IOS
    while (cin >> n && n) {
        for (int i = 1; i < n; i++) {
            int off = 0;
            for (int j = 1; j < n; j++) {
                off = (off + i) % j;
            }
            if (off == 11) {
                cout << i << '\n';
                break;
            }
        }
    }
}