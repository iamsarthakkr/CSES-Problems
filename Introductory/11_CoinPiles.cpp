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

    int tt;
    cin >> tt;
    while(tt--) {
        int a, b;
        cin >> a >> b;

        int mx = max(a, b), mn = min(a, b);

        cout << ((a + b) % 3 == 0 && 2 * mn >= mx ? "YES" : "NO") << '\n';
    }

    return 0;
}
