#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

struct Compo{
    int price;
    int quality;
    Compo(int p, int q) {
        price = p;
        quality = q;
    }
};

int T, n, b, k;
map<string, int> M;
vector<Compo> compos[MAXN];


void init() {
    k = 0;
    M.clear();
    for (int i = 0; i < n; i++) {
        compos[i].clear();
    }
}

int ID(string str) {
    if (M.count(str) == 0) {
        M[str] = k++;
    }
    return M[str];
}

bool canBuy(int Q) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int cheapest = b + 1, m = compos[i].size();
        for (int j = 0; j < m; j++) {
            if (compos[i][j].quality >= Q) {
                cheapest = min(cheapest, compos[i][j].price);
            }
        }

        if (cheapest == b + 1 || (sum += cheapest) > b) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> b;
        init();

        string typeTmp, nameTmp;
        int priceTmp, qualityTmp, maxQ = 0;
        for (int i = 0; i < n; i++) {
            cin >> typeTmp >> nameTmp >> priceTmp >> qualityTmp;
            maxQ = max(maxQ, qualityTmp);
            compos[ID(typeTmp)].push_back(Compo(priceTmp, qualityTmp));
        }

        int L = 0, R = maxQ, M;
        while (L < R) {
            M = L + (R - L + 1) / 2;
            if (canBuy(M)) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        cout << L << endl;
    }
}
