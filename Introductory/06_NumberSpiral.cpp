#include <bits/stdc++.h>
using namespace std;

template <typename T> inline bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template <typename T> inline bool cmax(T &a, const T &b) { return b > a ? a = b, true : false; }

#ifdef SARTHAK_LOCAL
#include "/Users/sarthakkumar/work/Cpp/Templates/Common/debug.hpp"
#else
#define debug(...) ((void)0)
#endif

long long solve(int r, int c) {
    int mx = max(r, c);
    long long cell = 1LL * mx * mx;

    if(mx & 1) {
        // from top down
        cell -= r - 1;
        if(r == mx) {
            // go right
            cell -= (mx - c);
        }

    } else {
        // from bottom up
        cell -= c - 1;
        if(c == mx) {
            cell -= (mx - r);
        }
    }
    return cell;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(12) << fixed;

    int tt;
    cin >> tt;
    while(tt--) {
        int r, c;
        cin >> r >> c;

        cout << solve(r, c) << '\n';
    }

    return 0;
}
