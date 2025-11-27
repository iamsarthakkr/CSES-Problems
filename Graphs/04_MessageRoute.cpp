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

    vector<int> dist(n, -1);
    vector<int> pv(n, -1);

    vector<int> q;
    int root = 0;
    q.assign(1, root);
    dist[root] = 0;

    for(int i = 0; i < (int)q.size(); i++) {
        int u = q[i];
        for(int v : g[u]) {
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            pv[v] = u;
            q.emplace_back(v);
        }
    }

    if(dist[n - 1] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    vector<int> path;
    int cur = n - 1;
    while(cur != -1) {
        path.emplace_back(cur);
        cur = pv[cur];
    }
    reverse(path.begin(), path.end());

    cout << (int)path.size() << '\n';
    for(int x : path) cout << x + 1 << " ";
    cout << '\n';

    return 0;
}
