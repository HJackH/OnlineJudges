#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

bool isP(int x) {
    int sqx = sqrt(x);
    for (int i = 2; i <= sqx; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() { IOS
    int n;
    cin >> n;
    for (int i = 1; i <= 1000; i++) {
        if (!isP(n * i + 1)) {
            cout << i << '\n';
            return 0;
        }
    }
}