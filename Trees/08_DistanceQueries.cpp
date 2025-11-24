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

    vector<vector<int>> g(n);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n, -1), par(n);
    vector<int> q(1, 0);
    dist[0] = 0, par[0] = 0;

    q.reserve(n);
    for(int i = 0; i < (int)q.size(); i++) {
        int u = q[i];
        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.emplace_back(v);
            }
        }
    }

    vector<vector<int>> jump(n, vector<int>(LOG + 1));
    for(int u = 0; u < n; u++) {
        jump[u][0] = par[u];
    }

    for(int k = 1; k <= LOG; k++) {
        for(int u = 0; u < n; u++) {
            jump[u][k] = jump[jump[u][k - 1]][k - 1];
        }
    }

    auto LCA = [&](int u, int v) -> int {
        if(dist[u] > dist[v]) swap(u, v);

        for(int k = LOG; k >= 0; k--) {
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

    auto GetDist = [&](int u, int v) {
        int w = LCA(u, v);
        return dist[u] + dist[v] - 2 * dist[w];
    };

    while(qq--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        cout << GetDist(u, v) << '\n';
    }

    return 0;
}
