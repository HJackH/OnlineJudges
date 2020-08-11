#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

long long n;

int main() {
    IOS
    while (cin >> n && n) {
        long long qn = round(sqrt(n));
        if (n % qn == 0) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}