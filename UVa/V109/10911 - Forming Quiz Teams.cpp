#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define sz(x) int((x).size())
const int INF = 1e9;
const int MAXN = (8 + 2) << 1;

struct Stu {
    int x;
    int y;
};

int n;
Stu stus[MAXN];
double d[MAXN][MAXN], dp[1 << MAXN];

double dis(const Stu &a, const Stu &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int kase = 0;
    while (cin >> n && n) {
        n <<= 1;
        string trash;
        for (int i = 0; i < n; i++) {
            cin >> trash >> stus[i].x >> stus[i].y;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                d[i][j] = d[j][i] = dis(stus[i], stus[j]);
            }
        }

        dp[0] = 0;
        for (int s = 1, ed = 1 << n; s < ed; s++) {
            dp[s] = INF;
            
            int i;
            for (i = n - 1; i >= 0; i--) {
                if (s & (1 << i)) {
                    break;
                }
            }

            // pair(i, j1), (i, j2), ...
            for (int j = 0; j < i; j++) {
                if (s & (1 << j)) {
                    dp[s] = min(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + d[i][j]);
                }
            }
        }
        
        printf("Case %d: %.2lf\n", ++kase, dp[(1 << n) - 1]);
    }
}