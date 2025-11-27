#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const long long inf = 1e18;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
    }

    vector<vector<long long>> dist(n);
    multiset<pair<long long, int>> s;
    s.emplace(0, 0);

    while((int)dist[n - 1].size() < k) {
        debug(s);
        auto [d, u] = *s.begin();
        s.erase(s.begin());
        debug(u, d, dist[u], g[u]);

        if((int)dist[u].size() == k) continue;
        dist[u].emplace_back(d);

        for(auto [v, c] : g[u]) {
            long long nd = d + c;
            if((int)dist[v].size() < k) {
                s.emplace(nd, v);
            }
        }
    }

    for(auto d : dist[n - 1]) cout << d << " ";
    cout << '\n';

    return 0;
}
