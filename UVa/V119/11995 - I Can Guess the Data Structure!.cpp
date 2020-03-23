#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;

struct DS {
    int type;
    int num;
};

int n;
DS dss[MAXN];

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> dss[i].type >> dss[i].num;
        }

        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;
        vector<bool> flag(3, true);
        int cnt = 3;

        for (int i = 0; i < n; i++) {
            if (flag[0]) {
                switch (dss[i].type)
                {
                case 1:
                    st.push(dss[i].num);
                    break;

                case 2:
                    if (st.empty() || (!st.empty() && st.top() != dss[i].num)) {
                        flag[0] = false;
                        cnt--;
                    } else {
                        st.pop();
                    }
                    break;
                
                default:
                    flag[0] = false;
                    cnt--;
                    break;
                }
            }

            if (flag[1]) {
                switch (dss[i].type)
                {
                case 1:
                    qu.push(dss[i].num);
                    break;

                case 2:
                    if (qu.empty() || (!qu.empty() && qu.front() != dss[i].num)) {
                        flag[1] = false;
                        cnt--;
                    } else {
                        qu.pop();
                    }
                    break;
                
                default:
                    flag[1] = false;
                    cnt--;
                    break;
                }
            }

            if (flag[2]) {
                switch (dss[i].type)
                {
                case 1:
                    pq.push(dss[i].num);
                    break;

                case 2:
                    if (pq.empty() || (!pq.empty() && pq.top() != dss[i].num)) {
                        flag[2] = false;
                        cnt--;
                    } else {
                        pq.pop();
                    }
                    break;
                
                default:
                    flag[2] = false;
                    cnt--;
                    break;
                }
            }
        }

        if (cnt == 0) {
            cout << "impossible\n";
        } else if (cnt >= 2) {
            cout << "not sure\n";
        } else if (flag[0]) {
            cout << "stack\n";
        } else if (flag[1]) {
            cout << "queue\n";
        } else {
            cout << "priority queue\n";
        }
    }
}
