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

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<long long, int> mp;
    mp[0] = 1;

    long long ans = 0, pref = 0;
    for(int r = 0; r < n; r++) {
        pref += a[r];
        long long need = pref - x; // pref - pref1 = x -> pref1 = pref - x
        debug(a[r], pref, need, mp[need]);
        ans += mp[need];
        mp[pref] += 1;
    }
    cout << ans << '\n';

    return 0;
}
