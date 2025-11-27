#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const long long inf = 1e18;
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

    vector<array<long long, 2>> dist(n, {inf, inf});
    set<pair<long long, pair<int, int>>> s;
    s.insert({0, {0, 0}});
    dist[0][0] = 0;

    while(!s.empty()) {
        auto p = *s.begin();
        s.erase(s.begin());
        long long d = p.first;
        int u = p.second.first, type = p.second.second;
        if(dist[u][type] != d) continue;

        for(auto &[v, c] : g[u]) {
            long long nd = d + c;
            if(nd < dist[v][type]) {
                dist[v][type] = nd;
                s.insert({nd, {v, type}});
            }
            if(type == 0) { // can discount
                nd = d + c / 2;
                if(nd < dist[v][1]) {
                    dist[v][1] = nd;
                    s.insert({nd, {v, 1}});
                }
            }
        }
    }

    cout << dist[n - 1][1] << '\n';

    return 0;
}
