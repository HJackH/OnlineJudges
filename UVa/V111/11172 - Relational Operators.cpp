#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a > b) {
            cout << '>' << endl;
        } else if (a < b) {
            cout << '<' << endl;
        } else {
            cout << '=' << endl;
        }
    }
}
