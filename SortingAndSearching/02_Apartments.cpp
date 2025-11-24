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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        while(j < m && b[j] + k < a[i]) j++;
        if(j < m && abs(a[i] - b[j]) <= k) {
            ans += 1;
            j += 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
