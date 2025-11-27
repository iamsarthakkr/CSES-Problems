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
    vector<vector<pair<int, int>>> gr(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
        gr[v].emplace_back(u, c);
    }

    vector<bool> con_start(n);
    vector<bool> con_end(n);

    function<void(int)> dfs_start = [&](int u) {
        con_start[u] = 1;
        for(auto &[v, c] : g[u]) {
            if(!con_start[v]) {
                dfs_start(v);
            }
        }
    };

    function<void(int)> dfs_end = [&](int u) {
        con_end[u] = 1;
        for(auto &[v, c] : gr[u]) {
            if(!con_end[v]) {
                dfs_end(v);
            }
        }
    };
    dfs_start(0);
    dfs_end(n - 1);

    vector<long long> dist(n, -inf);
    dist[0] = 0;

    for(int k = 0; k < n; k++) {
        for(int u = 0; u < n; u++) {
            for(auto &[v, c] : g[u]) {
                dist[v] = max(dist[v], dist[u] + c);
            }
        }
    }
    long long best = dist[n - 1];

    bool bad = 0;
    for(int u = 0; u < n; u++) {
        for(auto &[v, c] : g[u]) {
            long long d = dist[v], nd = dist[u] + c;
            if(nd > d && con_start[u] && con_end[v]) {
                bad = 1;
            }
        }
    }

    cout << (bad ? -1 : best) << '\n';

    return 0;
}
