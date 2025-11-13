#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i] >> c[i];

    vector<int> all;
    for(int x : l) all.emplace_back(x);
    for(int x : r) all.emplace_back(x);

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for(int &x : l) x = 1 + int(lower_bound(all.begin(), all.end(), x) - all.begin());
    for(int &x : r) x = 1 + int(lower_bound(all.begin(), all.end(), x) - all.begin());

    int mx = (int)all.size() + 1;
    vector<vector<int>> ids(mx + 1);
    for(int i = 0; i < n; i++) ids[r[i]].emplace_back(i);

    vector<long long> dp(mx + 1);

    for(int rx = 1; rx <= mx; rx++) {
        dp[rx] = dp[rx - 1];
        for(int i : ids[rx]) {
            int lx = l[i];
            cmax(dp[rx], dp[lx - 1] + c[i]);
        }
    }
    cout << dp[mx] << '\n';

    return 0;
}
