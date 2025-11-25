#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if(l[i] == l[j]) return r[i] < r[j];
        return l[i] < l[j];
    });

    int cur = 1;
    set<int> avail;
    set<pair<int, int>> present; // {leavetime, id}
    vector<int> room(n);

    for(int i : order) {
        while(!present.empty() && present.begin()->first < l[i]) {
            auto j = *present.begin();
            present.erase(j);
            avail.insert(room[j.second]);
        }
        if(avail.empty()) {
            avail.insert(cur++);
        }
        int nr = *avail.begin();
        room[i] = nr;
        avail.erase(nr);
        present.emplace(r[i], i);
    }
    int req = cur - 1;

    cout << req << '\n';
    for(int rr : room) cout << rr << " ";
    cout << '\n';

    return 0;
}
