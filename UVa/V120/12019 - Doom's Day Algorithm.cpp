#include <bits/stdc++.h>
using namespace std;

const string s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int day[] = {4, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    for (int i = 1; i < 12; i++) {
        day[i] += day[i - 1];
    }
    int T, m, d;
    cin >> T;
    while (T--) {
        cin >> m >> d;
        cout << s[(day[m - 1] + d) % 7] << '\n';
    }
    return 0;
}