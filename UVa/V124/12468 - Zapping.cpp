#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    while (cin >> a >> b && !(a == -1 && b == -1)) {
        cout << min(abs(a - b), 100 - abs(a - b)) << '\n';
    }
}