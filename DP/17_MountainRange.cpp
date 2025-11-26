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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> g(n);
    vector<int> indeg(n);
    auto Add = [&](int from, int to) {
        g[from].emplace_back(to);
        indeg[to]++;
    };

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    for(int rot = 0; rot < 2; rot++) {
        vector<int> s;
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && a[order[s.back()]] < a[order[i]]) {
                Add(order[i], order[s.back()]);
                s.pop_back();
            }
            s.push_back(i);
        }

        reverse(order.begin(), order.end());
    }

    order.clear();
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) order.emplace_back(i);
    }

    for(int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for(int v : g[u]) {
            --indeg[v];
            if(indeg[v] == 0) order.emplace_back(v);
        }
    }

    assert((int)order.size() == n); // has to be DAG

    reverse(order.begin(), order.end());

    vector<int> dp(n);
    for(int u : order) {
        dp[u] = 1;
        for(int v : g[u]) dp[u] = max(dp[u], 1 + dp[v]);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
