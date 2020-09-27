#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int a[3];

int main() {
    IOS
    
    while (true) {
        int chk = 0;
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            chk |= a[i];
        }
        if (!chk) {
            break;
        } 

        sort(a, a + 3);
        if ((a[0] * a[0] + a[1] * a[1]) == (a[2] * a[2])) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
}