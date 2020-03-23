#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 50;

struct Job{
    int num;
    int priority;
    bool operator < (Job const &other) const {
        return priority < other.priority;
    }
};

int T, n, m;
Job jobs[MAXN];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;

        priority_queue<Job, vector<Job>> pq;
        queue<Job> qu;
        for (int i = 0; i < n; i++) {
            jobs[i].num = i;
            cin >> jobs[i].priority;
            pq.push(jobs[i]);
            qu.push(jobs[i]);
        }

        int ans = 0;
        while (!qu.empty()) {
            ans++;
            while (qu.front().priority < pq.top().priority) {
                qu.push(qu.front());
                qu.pop();
            }
            if (qu.front().num == m) {
                break;
            }
            qu.pop();
            pq.pop();
        }
        cout << ans << '\n';
    }
}
