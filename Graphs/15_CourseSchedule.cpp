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
    vector<int> indeg(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[v].emplace_back(u);
        indeg[u]++;
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

    if((int)order.size() != n) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        reverse(order.begin(), order.end());
        for(int u : order) cout << u + 1 << " ";
        cout << '\n';
    }

    return 0;
}
