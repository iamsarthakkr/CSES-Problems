#include <bits/stdc++.h>
#include <iterator>
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
    }

    vector<int> pv(n, -1);
    vector<int> vis(n);

    auto solve = [&](int root) -> vector<int> {
        int start = -1, end = -1;
        function<bool(int)> dfs = [&](int u) -> bool {
            vis[u] = 1;
            bool has = 0;
            for(int v : g[u]) {
                if(vis[v] == 0) {
                    pv[v] = u;
                    if(dfs(v)) {
                        has = 1;
                        break;
                    }
                } else if(vis[v] == 1) {
                    start = v, end = u;
                    has = 1;
                    break;
                }
            }
            vis[u] = 2;
            return has;
        };

        auto ret = dfs(root);
        if(!ret) return {};

        vector<int> path = {start};

        int cur = end;
        while(cur != start) {
            path.emplace_back(cur);
            cur = pv[cur];
        }
        path.emplace_back(start);
        reverse(path.begin(), path.end());
        return path;
    };

    for(int u = 0; u < n; u++) {
        if(vis[u]) continue;

        auto path = solve(u);
        if((int)path.size() <= 1) continue;

        cout << (int)path.size() << '\n';
        for(int v : path) cout << v + 1 << " ";
        cout << '\n';
        return 0;
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
