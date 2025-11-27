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

    vector<int> side(n, -1);

    vector<int> q;
    auto bfs = [&](int root) -> bool {
        q.assign(1, root);
        side[root] = 0;

        for(int i = 0; i < (int)q.size(); i++) {
            int u = q[i];
            for(int v : g[u]) {
                if(side[v] != -1) {
                    if(side[v] == side[u]) return false;
                    continue;
                }
                side[v] = side[u] ^ 1;
                q.emplace_back(v);
            }
        }
        return true;
    };

    for(int u = 0; u < n; u++) {
        if(side[u] == -1) {
            if(!bfs(u)) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << side[i] + 1 << " \n"[i == n - 1];

    return 0;
}
