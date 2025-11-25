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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto good = [&](long long sum) {
        int cnt = 1;
        long long cs = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > sum) return false;
            cs += a[i];
            if(cs > sum) {
                cs = a[i];
                cnt++;
            }
        }

        return cnt <= k;
    };

    long long lo = 0, hi = 1e15; // max sum > lo, <= hi
    while(hi > lo + 1) {
        long long mid = (hi + lo) >> 1;
        if(good(mid))
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << '\n';

    return 0;
}
