#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

int n, rank_boy[MAXN][MAXN], Boysgirl[MAXN], Girlsboy[MAXN];
deque<int> girl_choice[MAXN], notPair;

int main() {
    int T;
    cin >> T;
    while (T--) {
        notPair.clear();
        cin >> n;

        int boy, girl;
        for (int i = 1; i <= n; i++) {
            notPair.push_back(i);
            girl_choice[i].clear();
            for (int j = 1; j <= n; j++) {
                cin >> boy;
                girl_choice[i].push_back(boy);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> girl;
                rank_boy[i][girl] = j;
            }
        }


        memset(Boysgirl, 0, sizeof(Boysgirl));
        memset(Girlsboy, 0, sizeof(Girlsboy));
        while (!notPair.empty()) {
            int girl = notPair.front();
            notPair.pop_front();
            int choose_boy = girl_choice[girl].front();
            girl_choice[girl].pop_front();
            
            if (!Boysgirl[choose_boy]) {
                Boysgirl[choose_boy] = girl;
                Girlsboy[girl] = choose_boy;
                continue;
            }

            if (rank_boy[choose_boy][girl] < rank_boy[choose_boy][Boysgirl[choose_boy]]) {
                notPair.push_back(Boysgirl[choose_boy]);
                Boysgirl[choose_boy] = girl;
                Girlsboy[girl] = choose_boy;
            } else {
                notPair.push_back(girl);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << Girlsboy[i] << '\n';
        }

        if (T) {
            cout << '\n';
        }
    }
}