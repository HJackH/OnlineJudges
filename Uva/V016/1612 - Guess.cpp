#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id;
    int rnk;
    int scr[3];
    int num[8];

    void calc() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    num[i * 4 + j * 2 + k] = (i & 1 ? scr[0] : 0) + (j & 1 ? scr[1] : 0) + (k & 1 ? scr[2] : 0);
                }
            }
        }
        sort(num, num + 8, greater<int>());
    }

    bool operator < (Player const &other) const {
        return rnk < other.rnk;
    }
};

int n, kase = 0;
Player p[17000];

int main() {
    double scrtmp;
    int idtmp;

    while (cin >> n && n) {
        
        for (int i = 0; i < n; i++) {
            p[i].id = i;
            for (int j = 0; j < 3; j++) {
                cin >> scrtmp;
                p[i].scr[j] = round(scrtmp * 100);
            }
            p[i].calc();
        }


        for (int i = 0; i < n; i++) {
            cin >> idtmp;
            p[idtmp - 1].rnk = i;
        }
        sort(p, p + n);

        int level = p[0].num[0];
        bool chk = true;
        for (int i = 1; i < n && chk; i++) {
            chk = false;
            if (p[i - 1].id < p[i].id) {
                for (int j = 0; j < 8; j++) {
                    if (p[i].num[j] <= level) {
                        level = p[i].num[j];
                        chk = true;
                        break;
                    }
                }
            } else {
                for (int j = 0; j < 8; j++) {
                    if (p[i].num[j] < level) {
                        level = p[i].num[j];
                        chk = true;
                        break;
                    }
                }
            }
        }

        cout << "Case " << ++kase << ": ";
        if (chk) {
            printf("%.2lf\n", (double)level / 100.0);
        } else {
            cout << "No solution" << endl;
        }
    }
}