#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;

struct Argus{
    int name;
    int per;
    int time;
    bool operator < (const Argus &other) const {
        return (time > other.time) || (time == other.time && name > other.name);
    }
};

int k;
string in;
Argus argus;

int main() {
    priority_queue<Argus> pq;
    while (cin >> in && in != "#") {
        cin >> argus.name >> argus.per;
        argus.time = argus.per;
        pq.push(argus);
    }
    cin >> k;
    while (k--) {
        auto i = pq.top();
        pq.pop();
        cout << i.name << '\n';
        pq.push((Argus){i.name, i.per, i.time + i.per});
    }
}