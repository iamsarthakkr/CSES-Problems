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
    for(int u = 1; u <= n - 1; u++) {
        int p;
        cin >> p;
        --p;

        g[u].push_back(p);
        g[p].push_back(u);
    }

    vector<int> sz(n);
    function<void(int, int)> dfs = [&](int u, int pr) {
        sz[u]++;
        for(int v : g[u]) {
            if(v == pr) continue;
            dfs(v, u);
            sz[u] += sz[v];
        }
    };

    dfs(0, 0);

    for(int i = 0; i < n; i++) cout << sz[i] - 1 << " \n"[i == n - 1];

    return 0;
}
