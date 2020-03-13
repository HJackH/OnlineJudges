#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;

struct Rock
{
    char type;
    int len;
};

int T, n, d;
Rock rocks[MAXN];

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> d;

        char hyphen;
        for (int i = 0; i < n; i++) {
            cin >> rocks[i].type >> hyphen >> rocks[i].len;
        }

        int ans = 0, lenA = 0, lenB = 0;
        bool ab = true;
        for (int i = 0; i < n; i++) {
            if (rocks[i].type == 'B') {
                ans = max(ans, rocks[i].len - lenA);
                ans = max(ans, rocks[i].len - lenB);
                lenA = rocks[i].len;
                lenB = rocks[i].len;
            } else if (ab) {
                ans = max(ans, rocks[i].len - lenA);
                lenA = rocks[i].len;
                ab = !ab;
            } else {
                ans = max(ans, rocks[i].len - lenB);
                lenB = rocks[i].len;
                ab = !ab;
            }
        }

        ans = max(ans, d - lenA);
        ans = max(ans, d - lenB);
        cout << "Case " << t << ": " << ans << '\n';
    }
}
