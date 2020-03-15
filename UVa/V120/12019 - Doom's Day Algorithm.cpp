#include <bits/stdc++.h>
using namespace std;

int T, m, d, now;
int table[12 + 5][31 + 10], day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string name[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    now = 4;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= day[i - 1]; j++) {
            now = (now + 1) % 7;
            table[i][j] = now;
        }
    }

    cin >> T;
    while (T--) {
        cin >> m >> d;
        cout << name[table[m][d]] << '\n';
    }
}
