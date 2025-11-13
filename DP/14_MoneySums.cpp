#include <bits/stdc++.h>
using namespace std;

template <typename T> bool cmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/CP_Templates/debug.cpp"
#else
#define debug(...) 69
#endif

const int M = 100001;

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> dp(M, 0), ndp(M, 0);

    dp[0] = true;

    for(int i = 0; i < n; i++) {
        fill(ndp.begin(), ndp.end(), false);
        for(int s = 0; s < M; s++) {
            ndp[s] = dp[s];
            if(s - a[i] >= 0) ndp[s] = ndp[s] || dp[s - a[i]];
        }
        dp.swap(ndp);
    }

    vector<int> ans;
    for(int s = 1; s < M; s++) {
        if(dp[s]) ans.emplace_back(s);
    }

    cout << (int)ans.size() << '\n';
    for(int x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}
