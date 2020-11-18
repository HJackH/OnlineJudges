#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n;
vector<int> like;

int main() { IOS
    cin >> n;
    like.resize(n + 1);
    for (int i = 1, f; i <= n; i++) {
        cin >> f;
        like[i] = f;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans |= like[like[like[i]]] == i;
    }

    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}