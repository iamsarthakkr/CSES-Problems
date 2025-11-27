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

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> g(n, vector<long long>(n, inf));
    for(int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        --u, --v;

        g[u][v] = min(g[u][v], c);
        g[v][u] = min(g[v][u], c);
    }
    for(int u = 0; u < n; u++) g[u][u] = 0;

    vector<vector<long long>> dist(n, vector<long long>(n, inf));

    for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) {
            dist[u][v] = g[u][v];
        }
    }
    debug(dist);

    for(int k = 0; k < n; k++) {
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (dist[u][v] >= inf ? -1 : dist[u][v]) << '\n';
    }

    return 0;
}
