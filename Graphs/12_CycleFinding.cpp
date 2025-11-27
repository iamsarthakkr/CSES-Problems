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
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
    }

    vector<long long> dist(n);
    vector<int> par(n, -1);
    int end = -1;
    for(int k = 0; k <= n; k++) {
        end = -1;
        for(int u = 0; u < n; u++) {
            for(auto &[v, c] : g[u]) {
                if(dist[u] + c < dist[v]) {
                    dist[v] = dist[u] + c;
                    end = v;
                    par[v] = u;
                }
            }
        }
    }

    debug(end, par);
    if(end == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    for(int i = 0; i <= n; i++) end = par[end];

    vector<int> path;
    path.push_back(end);

    int cur = par[end];
    while(cur != end) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "YES" << '\n';
    for(int u : path) cout << u + 1 << " ";
    cout << '\n';

    return 0;
}
