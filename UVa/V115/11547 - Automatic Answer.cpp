#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n;

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (abs(315 * n + 36962) / 10) % 10 << '\n';  
    }
}