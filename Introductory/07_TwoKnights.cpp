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

    for(int k = 1; k <= n; k++) {
        long long ks = 1LL * k * k;
        long long tot = 1LL * ks * (ks - 1) / 2;

        {
            // 2 * 3
            long long bad = 2LL * (k - 1) * (k - 2);
            tot -= bad;
        }
        {
            // 3 * 2
            long long bad = 2LL * (k - 2) * (k - 1);
            tot -= bad;
        }
        cout << tot << " ";
    }
    cout << '\n';

    return 0;
}
