#include <bits/stdc++.h>
using namespace std;

long long s, d, i;

int main() {
    while (cin >> s >> d) {
        for (i = s; (s + i) * (i - s + 1) / 2 < d; i++);
        cout << i << endl;
    }
}
