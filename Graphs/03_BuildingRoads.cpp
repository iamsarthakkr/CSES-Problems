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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> components;
    vector<bool> vis(n);

    vector<int> q;
    auto bfs = [&](int root) {
        q.assign(1, root);
        vis[root] = 1;
        for(int i = 0; i < (int)q.size(); i++) {
            int u = q[i];
            for(int v : g[u]) {
                if(vis[v]) continue;
                vis[v] = 1;
                q.emplace_back(v);
            }
        }
    };

    for(int u = 0; u < n; u++) {
        if(!vis[u]) {
            components.emplace_back(u);
            bfs(u);
        }
    }

    cout << (int)components.size() - 1 << '\n';
    for(int i = 1; i < (int)components.size(); i++) {
        cout << components[i] + 1 << " " << components[0] + 1 << '\n';
    }

    return 0;
}
