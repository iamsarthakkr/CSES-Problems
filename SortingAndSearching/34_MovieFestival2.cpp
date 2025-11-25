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

    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if(r[i] == r[j]) return l[i] < l[j];
        return r[i] < r[j];
    });

    multiset<int> rs;
    int cnt = 0;
    for(int i : order) {
        auto it = rs.upper_bound(l[i]);
        if((int)rs.size() > 0 && it != rs.begin()) {
            rs.erase(prev(it));
            cnt++;
            rs.insert(r[i]);
            continue;
        }

        if((int)rs.size() < k) {
            rs.insert(r[i]);
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
