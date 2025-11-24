#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const int LOG = 21;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, qq;
    cin >> n >> qq;

    vector<int> par(n);
    vector<vector<int>> g(n);

    for(int u = 1; u <= n - 1; u++) {
        int p;
        cin >> p;
        --p;
        par[u] = p;
        g[u].push_back(p);
        g[p].push_back(u);
    }

    vector<vector<int>> jump(n, vector<int>(LOG + 1));
    for(int u = 0; u < n; u++) {
        for(int k = 0; k <= LOG; k++) {
            if(k == 0) {
                jump[u][k] = par[u];
                continue;
            }
            jump[u][k] = jump[jump[u][k - 1]][k - 1];
        }
    }

    vector<int> dist(n, -1);
    vector<int> q(1, 0);
    dist[0] = 0;

    q.reserve(n);
    for(int i = 0; i < (int)q.size(); i++) {
        int u = q[i];
        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace_back(v);
            }
        }
    }

    auto LCA = [&](int u, int v) -> int {
        if(dist[u] > dist[v]) swap(u, v);

        for(int k = LOG; k >= 0; --k) {
            int v1 = jump[v][k];
            if(dist[v1] >= dist[u]) v = v1;
        }
        if(v == u) return u;

        for(int k = LOG; k >= 0; --k) {
            int u1 = jump[u][k], v1 = jump[v][k];
            if(u1 != v1) {
                u = u1;
                v = v1;
            }
        }
        return par[u];
    };

    while(qq--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        cout << LCA(u, v) + 1 << '\n';
    }

    return 0;
}
