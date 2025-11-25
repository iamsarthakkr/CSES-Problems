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

    // pref[r] - pref[l - 1] == 0 (mod n)
    // => pref[r] == pref[l - 1] (mod n)

    vector<int> cnt(n);
    cnt[0]++;

    long long ans = 0;
    for(int i = 0, ps = 0; i < n; i++) {
        ps += a[i];
        ps %= n;
        if(ps < 0) ps += n;

        ans += cnt[ps];
        cnt[ps]++;
    }

    cout << ans << '\n';

    return 0;
}
