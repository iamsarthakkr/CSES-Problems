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
    sort(order.begin(), order.end(), [&](int i, int j) { return l[i] < l[j]; });

    int ans = 0;
    multiset<int> rs;
    for(int i : order) {
        while(!rs.empty() && *rs.begin() < l[i]) rs.erase(rs.begin());
        rs.insert(r[i]);

        ans = max(ans, (int)rs.size());
    }

    cout << ans << '\n';

    return 0;
}
