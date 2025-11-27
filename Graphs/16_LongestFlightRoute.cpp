#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const int inf = 2e9;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> indeg(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        indeg[v]++;
    }

    vector<int> order;
    for(int u = 0; u < n; u++) {
        if(indeg[u] == 0) order.emplace_back(u);
    }

    for(int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for(int v : g[u]) {
            if(--indeg[v] == 0) order.emplace_back(v);
        }
    }

    vector<int> pv(n, -1), dp(n, -inf);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int u = order[i];
        if(dp[u] < 0) continue;

        for(int v : g[u]) {
            if(cmax(dp[v], dp[u] + 1)) pv[v] = u;
        }
    }

    if(dp[n - 1] < 0) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        int ans = dp[n - 1], end = n - 1;

        vector<int> path;
        while(end != -1) {
            path.emplace_back(end);
            end = pv[end];
        }

        reverse(path.begin(), path.end());

        cout << ans << '\n';
        for(int u : path) cout << u + 1 << " ";
        cout << '\n';
    }

    return 0;
}
