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

    vector<int> dist(n, -1);
    vector<int> q;

    q.emplace_back(0);
    dist[0] = 0;

    for(int i = 0; i < (int)q.size(); i++) {
        int u = q[i];
        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.emplace_back(v);
            }
        }
    }

    vector<int> best(n, -1), secondBest(n, -1);
    auto Update = [&](int u, int val) {
        if(best[u] == -1) {
            best[u] = val;
            return;
        }
        if(val > best[u]) {
            secondBest[u] = best[u];
            best[u] = val;
            return;
        }
        secondBest[u] = max(secondBest[u], val);
    };

    function<void(int, int)> dfs1 = [&](int u, int pr) {
        Update(u, 0);
        for(int v : g[u]) {
            if(v == pr) continue;
            dfs1(v, u);
            Update(u, best[v] + 1);
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int pr) {
        Update(u, 0);
        for(int v : g[u]) {
            if(v == pr) continue;

            int b1 = best[u], b2 = secondBest[u];

            if(best[u] == best[v] + 1) {
                best[u] = secondBest[u];
                secondBest[u] = -1;
            }

            Update(v, best[u] + 1);
            dfs2(v, u);
            best[u] = b1, secondBest[u] = b2;
        }
    };

    dfs1(0, 0);
    dfs2(0, 0);

    for(int i = 0; i < n; i++) cout << best[i] << " \n"[i == n - 1];

    return 0;
}
