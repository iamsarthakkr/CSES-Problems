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

    long long tot = 0;
    for(int x : a) tot += x;

    long long ans = (long long)9e18;
    for(int mask = 0; mask < 1 << n; mask++) {
        long long cur = 0;
        for(int i = 0; i < n; i++)
            if((mask >> i) & 1) cur += a[i];
        ans = min(ans, abs(2 * cur - tot));
    }

    cout << ans << '\n';

    return 0;
}
