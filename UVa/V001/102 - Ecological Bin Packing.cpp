#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const long long INF = 1e15;

long long a[6 + 5], ans;
int table[26];
string conf, ansconf;

int main() {
    IOS
    table['B' - 'A'] = 0;
    table['G' - 'A'] = 1;
    table['C' - 'A'] = 2;
    while (cin >> a[0]) {
        for (int i = 1; i < 9; i++) {
            cin >> a[i];
        }
        ans = INF;
        conf = "BCG";

        long long move;
        do {
            move = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) {
                        continue;
                    }
                    move += a[j * 3 + table[conf[i] - 'A']];
                }
            }
            if (ans > move) {
                ans = move;
                ansconf = conf;
            }
        } while (next_permutation(conf.begin(), conf.end()));
        cout << ansconf << ' ' << ans << '\n';
    }
}