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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = (long long)9e18, sum = 0, pref = 0;
    for(int x : a) sum += x;

    for(int i = 0; i < n; i++) {
        pref += a[i];
        long long suff = sum - pref;
        long long cur = (1LL * (i + 1) * a[i] - pref) + (suff - (n - i - 1) * 1LL * a[i]);

        ans = min(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
