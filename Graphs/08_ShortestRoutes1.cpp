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

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
    }

    vector<long long> dist(n, inf);
    set<pair<long long, int>> s;
    s.emplace(0, 0);
    dist[0] = 0;

    while(!s.empty()) {
        auto [d, u] = *s.begin();
        s.erase(s.begin());

        debug(d, u);
        for(auto [v, c] : g[u]) {
            long long nd = d + c;
            if(nd < dist[v]) {
                auto it = s.find({dist[v], v});
                if(it != s.end()) s.erase(it);

                dist[v] = nd;
                s.emplace(nd, v);
            }
        }
    }
    for(int i = 0; i < n; i++) cout << dist[i] << " \n"[i == n - 1];

    return 0;
}
