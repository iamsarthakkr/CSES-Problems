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
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> a;
    for(int x : l) a.push_back(x);
    for(int x : r) a.push_back(x);

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    vector<vector<int>> ls(a.size() + 1);
    for(int i = 0; i < n; i++) {
        l[i] = int(lower_bound(a.begin(), a.end(), l[i]) - a.begin()) + 1;
        r[i] = int(lower_bound(a.begin(), a.end(), r[i]) - a.begin()) + 1;
        ls[r[i]].push_back(l[i]);
    }

    vector<int> dp(a.size() + 1, 0);

    for(int rr = 0; rr <= (int)a.size(); rr++) {
        if(rr > 0) {
            dp[rr] = dp[rr - 1];
        }
        for(int ll : ls[rr]) {
            dp[rr] = max(dp[rr], dp[ll] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
