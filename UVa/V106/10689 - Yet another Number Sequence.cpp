#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())
const int MOD[] = {0, 10, 100, 1000, 10000};

int a, b, n, m;

struct Matrix {
    vector<vector<int>> v = {{0, 0}, {0, 0}};
    Matrix operator * (const Matrix &other)  {
        Matrix tmp;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    tmp.v[i][j] = (tmp.v[i][j] + v[i][k] * other.v[k][j]) % MOD[m]; 
                }
            }
        }
        return tmp;
    }
};

Matrix mpow(int e) {
    Matrix ans, base;
    ans.v = {{1, 0}, {0, 1}};
    base.v = {{1, 1}, {1, 0}};
    while (e > 0) {
        if (e & 1) {
            ans = ans * base;
        }
        base = base * base;
        e >>= 1;
    }
    return ans;
}

int sol() {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    Matrix ans = mpow(n - 1);
    return (ans.v[0][1] * a + ans.v[0][0] * b) % MOD[m];
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> n >> m;
        cout << sol() << "\n";
    }
}