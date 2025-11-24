#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

const long long inf = 1e18;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long best = -inf, bestEnding = 0;

    for(int i = 0; i < n; i++) {
        bestEnding = max((long long)a[i], bestEnding + a[i]);
        best = max(best, bestEnding);
    }

    cout << best << '\n';

    return 0;
}
