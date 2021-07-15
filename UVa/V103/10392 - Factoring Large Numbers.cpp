#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() { IOS
    LL n;
    while (cin >> n && n >= 0) {
        for (LL i = 2, ed = sqrt(n); i <= ed; i++) {
            while (n % i == 0) {
                n /= i;
                cout << "    " << i << "\n";
            }
        }
        
        if (n > 1) {
            cout << "    " << n << "\n";
        }
        cout << "\n";
    }
}