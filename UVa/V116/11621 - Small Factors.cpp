#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const LL up = 1LL << 31;

vector<LL> a;

void table() {
    vector<LL> m2(35), m3(25);
    m2[0] = m3[0] = 1;
    for (int i = 1; i < 32; i++) {
        m2[i] = m2[i - 1] << 1;
    }
    for (int i = 1; i < 22; i++) {
        m3[i] = m3[i - 1] * 3;
    }
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 22; j++) {
            if (m2[i] * m3[j] > up) {
                break;
            }
            a.pb(m2[i] * m3[j]);
        }
    }
    sort(a.begin(), a.end());
}

int main() { IOS
    table();
    LL x;
    while (cin >> x && x) {
        cout << *lower_bound(a.begin(), a.end(), x) << "\n";
    }
}