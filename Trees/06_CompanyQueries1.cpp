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
    for(int u = 1; u <= n - 1; u++) {
        int p;
        cin >> p;
        --p;

        g[u].push_back(p);
        g[p].push_back(u);
    }

    vector<int> dist(n, -1), par(n, -1);
    vector<int> q;
    q.emplace_back(0);
    dist[0] = 0;
    par[0] = 0;

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
        for(int k = 0; k <= LOG; k++) {
            if(k == 0) {
                jump[u][k] = par[u];
                continue;
            }
            jump[u][k] = jump[jump[u][k - 1]][k - 1];
        }
    }

    while(qq--) {
        int u, x;
        cin >> u >> x;
        --u;

        if(dist[u] < x) {
            cout << -1 << '\n';
            continue;
        }

        for(int k = LOG; k >= 0; --k) {
            int del = 1 << k;
            if(del <= x) {
                u = jump[u][k];
                x -= del;
            }
        }
        cout << u + 1 << '\n';
    }

    return 0;
}
