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

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sz(n);
    vector<long long> dp(n);

    function<void(int, int)> dfs1 = [&](int u, int pr) {
        sz[u]++;
        for(int v : g[u]) {
            if(v == pr) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int pr) {
        for(int v : g[u]) {
            if(v == pr) continue;

            long long val = dp[u];
            val -= (dp[v] + sz[v]);
            dp[v] += (val + n - sz[v]);

            dfs2(v, u);
        }
    };

    dfs1(0, 0);
    dfs2(0, 0);

    for(int i = 0; i < n; i++) cout << dp[i] << " \n"[i == n - 1];

    return 0;
}
